#include "tthAnalysis/HiggsToTauTau/interface/GenLeptonCollectionSelector.h" // GenLeptonSelector

#include "tthAnalysis/HiggsToTauTau/interface/cmsException.h" // get_human_line()
#include "tthAnalysis/HiggsToTauTau/interface/analysisAuxFunctions.h" // kEra_*

GenLeptonSelector::GenLeptonSelector(int era,
				     int index,
				     bool debug)
  : era_(era)
  , max_absEta_muon_(2.4)
  , max_absEta_electron_(2.5)
  , debug_(debug)
{
  switch ( era_ )
  {
    case kEra_2016:
    {
      min_pt_muon_ = 10.;
      min_pt_electron_ = 10.;
      break;
    }
    case kEra_2017:
    {
      min_pt_muon_ = 5.;
      min_pt_electron_ = 7.;
      break;
    }
    case kEra_2018:
    {
      throw cmsException(this) << "Implement me!";
    }
    default: throw cmsException(this) << "Invalid era: " << era_;
  }
}

void
GenLeptonSelector::set_min_pt_muon(double min_pt)
{
  min_pt_muon_ = min_pt;
}

void
GenLeptonSelector::set_max_absEta_muon(double max_absEta)
{
  max_absEta_muon_ = max_absEta;
}

void
GenLeptonSelector::set_min_pt_electron(double min_pt)
{
  min_pt_electron_ = min_pt;
}

void
GenLeptonSelector::set_max_absEta_electron(double max_absEta)
{
  max_absEta_electron_ = max_absEta;
}

double
GenLeptonSelector::get_min_pt_muon() const
{
  return min_pt_muon_;
}

double
GenLeptonSelector::get_max_absEta_muon() const
{
  return max_absEta_muon_;
}

double
GenLeptonSelector::get_min_pt_electron() const
{
  return min_pt_electron_;
}

double
GenLeptonSelector::get_max_absEta_electron() const
{
  return max_absEta_electron_;
}

bool
GenLeptonSelector::operator()(const GenLepton & lepton) const
{
  if ( debug_ )
  {
    std::cout << get_human_line(this, __func__) << ":\n lepton: " << lepton << '\n';
  }

  double min_pt, max_absEta;
  if ( lepton.is_muon() ) 
  {
     min_pt = min_pt_muon_;
     max_absEta = max_absEta_muon_;
  } 
  else if ( lepton.is_electron() ) 
  {
     min_pt = min_pt_electron_;
     max_absEta = max_absEta_electron_;
  } else assert(0);

  if ( lepton.pt() < min_pt )
  {
    if ( debug_ )
    {
      std::cout << "FAILS pT >= " << min_pt << " cut\n";
    }
    return false;
  }
  if ( max_absEta > 0. && lepton.absEta() > max_absEta )
  {
    if ( debug_ )
    {
      std::cout << "FAILS abs(eta) <= " << max_absEta << " cut\n";
    }
    return false;
  }
  return true;
}
