#include "tthAnalysis/HiggsToTauTau/interface/Topness.h" // Topness

#include <Math/Factory.h> // ROOT::Math::Factory
#include <Math/Functor.h> // ROOT::Math::Functor
#include <TMath.h> // TMath::Sqrt, TMath::Min(), TMath::Max(), TMath::IsNaN()

using namespace topness;

/// global pointer for interface to MINUIT
const Topness* Topness::gTopness = nullptr;

/// define mass of top quark and of W boson 
/// (taken from "The review of particle physics", M. Tanabashi et al. (Particle Data Group), Phys. Rev. D 98, 030001 (2018))
const double mTop = 173.1; // GeV
const double mW = 80.379; // GeV

double ObjectiveFunctionAdapterMINUIT::operator()(const double* x) const 
{
  double chi2 = Topness::gTopness->operator()(x);
  return chi2;
}

Topness::Topness(int maxObjFunctionCalls)
  : sigmaTop_(5.)
  , sigmaW_(5.)
  , minimizer_(ROOT::Math::Factory::CreateMinimizer("Minuit2", "Migrad"))
  , maxObjFunctionCalls_(maxObjFunctionCalls)
  , fitStatus_(-1)
  , logTopness_(1.e+3)
{}

Topness::~Topness()
{
  delete minimizer_;
}

void Topness::set_sigmaW(double sigmaW) 
{ 
  assert(sigmaW > 0.);
  sigmaW_ = sigmaW; 
}

void Topness::set_sigmaTop(double sigmaTop) 
{ 
  assert(sigmaTop > 0.);
  sigmaTop_ = sigmaTop; 
}
  
namespace
{
  double compMassTop(const Particle::LorentzVector& leptonP4,
		     const Particle::LorentzVector& bjetP4,
		     double nuPx, double nuPy, double nuPz, double nuE)
  {
    double leptonPx = leptonP4.px();
    double leptonPy = leptonP4.py();
    double leptonPz = leptonP4.pz();
    double leptonE  = leptonP4.energy();

    double bjetPx   = bjetP4.px();
    double bjetPy   = bjetP4.py();
    double bjetPz   = bjetP4.pz();
    double bjetE    = bjetP4.energy();

    double topPx    = bjetPx + leptonPx + nuPx;
    double topPy    = bjetPy + leptonPy + nuPy;
    double topPz    = bjetPz + leptonPz + nuPz;
    double topE     = bjetE  + leptonE  + nuE;
    double topMass2 = topE*topE - (topPx*topPx + topPy*topPy + topPz*topPz);
    if ( topMass2 < 0. ) topMass2 = 0.;
    double topMass = TMath::Sqrt(topMass2);

    return topMass;
  }

  double compMassW(const Particle::LorentzVector& leptonP4,
		   double nuPx, double nuPy, double nuPz, double nuE)
  {
    double leptonPx = leptonP4.px();
    double leptonPy = leptonP4.py();
    double leptonPz = leptonP4.pz();
    double leptonE  = leptonP4.energy();

    double wPx    = leptonPx + nuPx;
    double wPy    = leptonPy + nuPy;
    double wPz    = leptonPz + nuPz;
    double wE     = leptonE  + nuE;
    double wMass2 = wE*wE - (wPx*wPx + wPy*wPy + wPz*wPz);
    if ( wMass2 < 0. ) wMass2 = 0.;
    double wMass = TMath::Sqrt(wMass2);

    return wMass;
  }

  double square(double x)
  {
    return x*x;
  }
}

double Topness::operator()(const double* x) const
{
  if ( numObjFunctionCalls_ > maxObjFunctionCalls_ ) {
    return -1.;
  }
  
  double nu1Px = x[0];
  double nu1Py = x[1];
  double nu1Pz = x[2];
  double nu1E  = TMath::Sqrt(nu1Px*nu1Px + nu1Py*nu1Py + nu1Pz*nu1Pz);

  double massTop1 = compMassTop(lepton1P4_, bjet1P4_, nu1Px, nu1Py, nu1Pz, nu1E);
  double massW1 = compMassW(lepton1P4_, nu1Px, nu1Py, nu1Pz, nu1E);

  double nu2Px = metPx_ - nu1Px;
  double nu2Py = metPx_ - nu1Py;
  double nu2Pz = x[3];
  double nu2E  = TMath::Sqrt(nu2Px*nu2Px + nu2Py*nu2Py + nu2Pz*nu2Pz);

  double massTop2 = compMassTop(lepton2P4_, bjet2P4_, nu2Px, nu2Py, nu2Pz, nu2E);
  double massW2 = compMassW(lepton2P4_, nu2Px, nu2Py, nu2Pz, nu2E);
  
  double chi2 = square((massTop1 - mTop)/sigmaTop_) + square((massW1 - mW)/sigmaW_) 
    + square((massTop2 - mTop)/sigmaTop_) + square((massW2 - mW)/sigmaW_);
  assert(!TMath::IsNaN(chi2));

  ++numObjFunctionCalls_;

  return chi2;
}

void Topness::fit(const Particle::LorentzVector& lepton1P4,
		  const Particle::LorentzVector& lepton2P4,
		  const Particle::LorentzVector& bjet1P4,
		  const Particle::LorentzVector& bjet2P4,
		  double metPx, double metPy)
{
//--- clear minimizer
  minimizer_->Clear();

//--- set verbosity level of minimizer
//      -1 quiet (also suppresses all warnings)
//       0 normal
//       1 verbose
  minimizer_->SetPrintLevel(-1);

  const int numPermutations = 2;
  double chi2[numPermutations];
  int fitStatus[numPermutations];
  for ( int idxPermutation = 0; idxPermutation < numPermutations; ++idxPermutation ) {

//--- set reconstructed momenta
    if        ( idxPermutation == 0 ) {
      lepton1P4_ = lepton1P4; 
      lepton2P4_ = lepton2P4; 
    } else if ( idxPermutation == 1 ) {
      lepton1P4_ = lepton2P4; 
      lepton2P4_ = lepton1P4; 
    } else assert(0);
    bjet1P4_     = bjet1P4; 
    bjet2P4_     = bjet2P4; 
    metPx_       = metPx;
    metPy_       = metPy;
    
//--- set interface to MINUIT
    const ROOT::Math::Functor toMinimize(objectiveFunctionAdapterMINUIT_, 4);
    minimizer_->SetFunction(toMinimize); 
    minimizer_->SetLimitedVariable(0, "Nu1Px", 0., 0.1, -5.e+3, +5.e+3);
    minimizer_->SetLimitedVariable(1, "Nu1Py", 0., 0.1, -5.e+3, +5.e+3);
    minimizer_->SetLimitedVariable(2, "Nu1Pz", 0., 0.1, -5.e+3, +5.e+3);
    minimizer_->SetLimitedVariable(3, "Nu2Pz", 0., 0.1, -5.e+3, +5.e+3);
    minimizer_->SetMaxFunctionCalls(maxObjFunctionCalls_);
    minimizer_->SetErrorDef(0.5);
  
//--- set MINUIT strategy = 2, in order to get reliable error estimates:
//     http://www-cdf.fnal.gov/physics/statistics/recommendations/minuit.html
    minimizer_->SetStrategy(2);

//--- do the minimization  
    numObjFunctionCalls_ = 0;
    minimizer_->Minimize();
    
//--- get Minimizer status code, check if solution is valid:
//       0: Valid solution
//       1: Covariance matrix was made positive definite
//       2: Hesse matrix is invalid
//       3: Estimated distance to minimum (EDM) is above maximum
//       4: Reached maximum number of function calls before reaching convergence
//       5: Any other failure
    fitStatus[idxPermutation] = minimizer_->Status();
    
    double minValue = minimizer_->MinValue();
    if ( fitStatus[idxPermutation] == 0 && !TMath::IsNaN(minValue) ) {
      chi2[idxPermutation] = minValue;
    } else {
      chi2[idxPermutation] = 1.e+3;
    }
  }

  double minChi2 = TMath::Min(chi2[0], chi2[1]);
  if ( minChi2 < 1.e-3 ) minChi2 = 1.e-3;
  fitStatus_ = TMath::Max(fitStatus[0], fitStatus[1]);
  if ( minChi2 >= 0. && fitStatus_ == 0 ) {
    logTopness_ = TMath::Log10(minChi2);
  } else {
    logTopness_ = 1.e+3;
  }
}

bool Topness::isValidSolution() const
{
  return ( fitStatus_ == 0 ) ? true : false;
}

double Topness::logTopness() const
{
  return logTopness_;
}