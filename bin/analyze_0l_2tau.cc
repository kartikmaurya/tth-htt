#include "FWCore/ParameterSet/interface/ParameterSet.h" // edm::ParameterSet
#include "FWCore/PythonParameterSet/interface/MakeParameterSets.h" // edm::readPSetsFrom()
#include "FWCore/Utilities/interface/Exception.h" // cms::Exception
#include "PhysicsTools/FWLite/interface/TFileService.h" // fwlite::TFileService
#include "DataFormats/FWLite/interface/InputSource.h" // fwlite::InputSource
#include "DataFormats/FWLite/interface/OutputFiles.h" // fwlite::OutputFiles
#include "DataFormats/Math/interface/LorentzVector.h" // math::PtEtaPhiMLorentzVector
#include "DataFormats/Math/interface/deltaR.h" // deltaR

#include <Rtypes.h> // Int_t, Long64_t, Double_t
#include <TChain.h> // TChain
#include <TTree.h> // TTree
#include <TBenchmark.h> // TBenchmark
#include <TString.h> // TString, Form
#include <TError.h> // gErrorAbortLevel, kError
#include <TH2F.h>

#include "tthAnalysis/HiggsToTauTau/interface/RecoLepton.h" // RecoLepton
#include "tthAnalysis/HiggsToTauTau/interface/RecoJet.h" // RecoJet
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTau.h" // RecoHadTau
#include "tthAnalysis/HiggsToTauTau/interface/GenLepton.h" // GenLepton
#include "tthAnalysis/HiggsToTauTau/interface/GenJet.h" // GenJet
#include "tthAnalysis/HiggsToTauTau/interface/GenHadTau.h" // GenHadTau
#include "tthAnalysis/HiggsToTauTau/interface/TMVAInterface.h" // TMVAInterface
#include "tthAnalysis/HiggsToTauTau/interface/XGBInterface.h" // XGBInterface
#include "tthAnalysis/HiggsToTauTau/interface/mvaAuxFunctions.h" // check_mvaInputs, get_mvaInputVariables
#include "tthAnalysis/HiggsToTauTau/interface/mvaInputVariables.h" // auxiliary functions for computing input variables of the MVA
#include "tthAnalysis/HiggsToTauTau/interface/LeptonFakeRateInterface.h" // LeptonFakeRateInterface
#include "tthAnalysis/HiggsToTauTau/interface/JetToTauFakeRateInterface.h" // JetToTauFakeRateInterface
#include "tthAnalysis/HiggsToTauTau/interface/RecoElectronReader.h" // RecoElectronReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoMuonReader.h" // RecoMuonReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTauReader.h" // RecoHadTauReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetReader.h" // RecoJetReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoMEtReader.h" // RecoMEtReader
#include "tthAnalysis/HiggsToTauTau/interface/MEtFilterReader.h" // MEtFilterReader
#include "tthAnalysis/HiggsToTauTau/interface/GenLeptonReader.h" // GenLeptonReader
#include "tthAnalysis/HiggsToTauTau/interface/GenHadTauReader.h" // GenHadTauReader
#include "tthAnalysis/HiggsToTauTau/interface/GenPhotonReader.h" // GenPhotonReader
#include "tthAnalysis/HiggsToTauTau/interface/GenJetReader.h" // GenJetReader
#include "tthAnalysis/HiggsToTauTau/interface/LHEInfoReader.h" // LHEInfoReader
#include "tthAnalysis/HiggsToTauTau/interface/EventInfoReader.h" // EventInfoReader, EventInfo
#include "tthAnalysis/HiggsToTauTau/interface/convert_to_ptrs.h" // convert_to_ptrs
#include "tthAnalysis/HiggsToTauTau/interface/ParticleCollectionCleaner.h" // Reco*CollectionCleaner
#include "tthAnalysis/HiggsToTauTau/interface/ParticleCollectionGenMatcher.h" // Reco*CollectionGenMatcher
#include "tthAnalysis/HiggsToTauTau/interface/RecoElectronCollectionSelectorLoose.h" // RecoElectronCollectionSelectorLoose
#include "tthAnalysis/HiggsToTauTau/interface/RecoElectronCollectionSelectorFakeable.h" // RecoElectronCollectionSelectorFakeable
#include "tthAnalysis/HiggsToTauTau/interface/RecoElectronCollectionSelectorTight.h" // RecoElectronCollectionSelectorTight
#include "tthAnalysis/HiggsToTauTau/interface/RecoMuonCollectionSelectorLoose.h" // RecoMuonCollectionSelectorLoose
#include "tthAnalysis/HiggsToTauTau/interface/RecoMuonCollectionSelectorFakeable.h" // RecoMuonCollectionSelectorFakeable
#include "tthAnalysis/HiggsToTauTau/interface/RecoMuonCollectionSelectorTight.h" // RecoMuonCollectionSelectorTight
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTauCollectionSelectorLoose.h" // RecoHadTauCollectionSelectorLoose
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTauCollectionSelectorFakeable.h" // RecoHadTauCollectionSelectorFakeable
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTauCollectionSelectorTight.h" // RecoHadTauCollectionSelectorTight
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetCollectionSelector.h" // RecoJetCollectionSelector
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetCollectionSelectorBtag.h" // RecoJetCollectionSelectorBtagLoose, RecoJetCollectionSelectorBtagMedium
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetCollectionSelectorHTTv2.h" // RecoJetSelectorHTTv2
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetHTTv2.h"
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetReaderHTTv2.h" // RecoJetReaderHTTv2
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetReaderAK8.h" // RecoJetReaderAK8
#include "tthAnalysis/HiggsToTauTau/interface/JetHistManagerHTTv2.h" // JetHistManagerHTTv2
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetCollectionSelectorAK8.h" // RecoJetSelectorAK8
#include "tthAnalysis/HiggsToTauTau/interface/ParticleCollectionCleanerSubJets.h" // RecoJetCollectionCleanerAK8SubJets
#include "tthAnalysis/HiggsToTauTau/interface/RunLumiEventSelector.h" // RunLumiEventSelector
#include "tthAnalysis/HiggsToTauTau/interface/MEtFilterSelector.h" // MEtFilterSelector
#include "tthAnalysis/HiggsToTauTau/interface/ElectronHistManager.h" // ElectronHistManager
#include "tthAnalysis/HiggsToTauTau/interface/MuonHistManager.h" // MuonHistManager
#include "tthAnalysis/HiggsToTauTau/interface/HadTauHistManager.h" // HadTauHistManager
#include "tthAnalysis/HiggsToTauTau/interface/JetHistManager.h" // JetHistManager
#include "tthAnalysis/HiggsToTauTau/interface/MEtHistManager.h" // MEtHistManager
#include "tthAnalysis/HiggsToTauTau/interface/MEtFilterHistManager.h" // MEtFilterHistManager
#include "tthAnalysis/HiggsToTauTau/interface/MVAInputVarHistManager.h" // MVAInputVarHistManager
#include "tthAnalysis/HiggsToTauTau/interface/EvtHistManager_0l_2tau.h" // EvtHistManager_0l_2tau
#include "tthAnalysis/HiggsToTauTau/interface/EvtYieldHistManager.h" // EvtYieldHistManager
#include "tthAnalysis/HiggsToTauTau/interface/CutFlowTableHistManager.h" // CutFlowTableHistManager
#include "tthAnalysis/HiggsToTauTau/interface/WeightHistManager.h" // WeightHistManager
#include "tthAnalysis/HiggsToTauTau/interface/GenEvtHistManager.h" // GenEvtHistManager
#include "tthAnalysis/HiggsToTauTau/interface/LHEInfoHistManager.h" // LHEInfoHistManager
#include "tthAnalysis/HiggsToTauTau/interface/leptonTypes.h" // getLeptonType, kElectron, kMuon
#include "tthAnalysis/HiggsToTauTau/interface/analysisAuxFunctions.h" // getBTagWeight_option, getHadTau_genPdgId, isHigherPt, isMatched
#include "tthAnalysis/HiggsToTauTau/interface/sysUncertOptions.h" // get*_option()
#include "tthAnalysis/HiggsToTauTau/interface/hadTauGenMatchingAuxFunctions.h" // getHadTauGenMatch_definitions_2tau, getHadTauGenMatch_string, getHadTauGenMatch_int
#include "tthAnalysis/HiggsToTauTau/interface/fakeBackgroundAuxFunctions.h" // getWeight_2L
#include "tthAnalysis/HiggsToTauTau/interface/hltPath.h" // hltPath, create_hltPaths, hltPaths_isTriggered, hltPaths_delete
#include "tthAnalysis/HiggsToTauTau/interface/hltPathReader.h" // hltPathReader
#include "tthAnalysis/HiggsToTauTau/interface/Data_to_MC_CorrectionInterface_2016.h"
#include "tthAnalysis/HiggsToTauTau/interface/Data_to_MC_CorrectionInterface_2017.h"
#include "tthAnalysis/HiggsToTauTau/interface/Data_to_MC_CorrectionInterface_2018.h"
#include "tthAnalysis/HiggsToTauTau/interface/Data_to_MC_CorrectionInterface_0l_2tau_trigger.h" // Data_to_MC_CorrectionInterface_0l_2tau_trigger
#include "tthAnalysis/HiggsToTauTau/interface/DYMCReweighting.h" // DYMCReweighting
#include "tthAnalysis/HiggsToTauTau/interface/DYMCNormScaleFactors.h" // DYMCNormScaleFactors
#include "tthAnalysis/HiggsToTauTau/interface/cutFlowTable.h" // cutFlowTableType
#include "tthAnalysis/HiggsToTauTau/interface/NtupleFillerBDT.h" // NtupleFillerBDT
#include "tthAnalysis/HiggsToTauTau/interface/HadTopTagger.h" // HadTopTagger
#include "tthAnalysis/HiggsToTauTau/interface/HadTopTagger_boosted.h" // HadTopTagger_boosted
#include "tthAnalysis/HiggsToTauTau/interface/HadTopTagger_semi_boosted_AK8.h" // HadTopTagger_semi_boosted
#include "tthAnalysis/HiggsToTauTau/interface/hadTopTaggerAuxFunctions.h" // isGenMatchedJetTriplet
#include "tthAnalysis/HiggsToTauTau/interface/hadTopTaggerAuxFunctions_geral.h" // isGenMatchedJetTriplet tags
#include "tthAnalysis/HiggsToTauTau/interface/TTreeWrapper.h" // TTreeWrapper
#include "tthAnalysis/HiggsToTauTau/interface/SyncNtupleManager.h" // SyncNtupleManager
#include "tthAnalysis/HiggsToTauTau/interface/hltFilter.h" // hltFilter()
#include "tthAnalysis/HiggsToTauTau/interface/EvtWeightManager.h" // EvtWeightManager
#include "tthAnalysis/HiggsToTauTau/interface/GenParticle.h" // GenParticle
#include "tthAnalysis/HiggsToTauTau/interface/GenParticleReader.h" // GenParticleReader

#include "TauAnalysis/ClassicSVfit/interface/ClassicSVfit.h" // ClassicSVfit
#include "TauAnalysis/ClassicSVfit/interface/MeasuredTauLepton.h" // classic_svFit::MeasuredTauLepton
#include "TauAnalysis/ClassicSVfit/interface/svFitHistogramAdapter.h"
#include "TauAnalysis/ClassicSVfit/interface/svFitAuxFunctions.h"

#include <boost/range/algorithm/copy.hpp> // boost::copy()
#include <boost/range/adaptor/map.hpp> // boost::adaptors::map_keys
#include <boost/math/special_functions/sign.hpp> // boost::math::sign()

#include <iostream> // std::cerr, std::fixed
#include <iomanip> // std::setprecision(), std::setw()
#include <string> // std::string
#include <vector> // std::vector<>
#include <cstdlib> // EXIT_SUCCESS, EXIT_FAILURE
#include <fstream> // std::ofstream
#include <assert.h> // assert

typedef math::PtEtaPhiMLorentzVector LV;
typedef std::vector<std::string> vstring;
typedef std::vector<double> vdouble;

enum { kFR_disabled, kFR_2tau };

const int hadTauSelection_antiElectron = -1; // not applied
const int hadTauSelection_antiMuon = -1; // not applied

struct HadTauHistManagerWrapper_eta
{
  HadTauHistManager* histManager_;
  double etaMin_;
  double etaMax_;
};

/**
 * @brief Produce datacard and control plots for 0l_2tau category.
 */
int main(int argc, char* argv[])
{
//--- throw an exception in case ROOT encounters an error
  gErrorAbortLevel = kError;

//--- parse command-line arguments
  if ( argc < 2 ) {
    std::cout << "Usage: " << argv[0] << " [parameters.py]" << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "<analyze_0l_2tau>:" << std::endl;

//--- keep track of time it takes the macro to execute
  TBenchmark clock;
  clock.Start("analyze_0l_2tau");

//--- read python configuration parameters
  if ( !edm::readPSetsFrom(argv[1])->existsAs<edm::ParameterSet>("process") )
    throw cms::Exception("analyze_0l_2tau")
      << "No ParameterSet 'process' found in configuration file = " << argv[1] << " !!\n";

  edm::ParameterSet cfg = edm::readPSetsFrom(argv[1])->getParameter<edm::ParameterSet>("process");

  edm::ParameterSet cfg_analyze = cfg.getParameter<edm::ParameterSet>("analyze_0l_2tau");

  std::string treeName = cfg_analyze.getParameter<std::string>("treeName");

  std::string process_string = cfg_analyze.getParameter<std::string>("process");
  bool isSignal = ( process_string == "signal" ) ? true : false;

  std::string histogramDir = cfg_analyze.getParameter<std::string>("histogramDir");
  bool isMCClosure_t = histogramDir.find("mcClosure_t") != std::string::npos;

  std::string era_string = cfg_analyze.getParameter<std::string>("era");
  const int era = get_era(era_string);

  vstring triggerNames_2tau = cfg_analyze.getParameter<vstring>("triggers_2tau");
  std::vector<hltPath*> triggers_2tau = create_hltPaths(triggerNames_2tau);
  bool use_triggers_2tau = cfg_analyze.getParameter<bool>("use_triggers_2tau");

  double lep_mva_cut = cfg_analyze.getParameter<double>("lep_mva_cut"); // CV: used for tight lepton selection only

  TString hadTauSelection_string = cfg_analyze.getParameter<std::string>("hadTauSelection").data();
  TObjArray* hadTauSelection_parts = hadTauSelection_string.Tokenize("|");
  assert(hadTauSelection_parts->GetEntries() >= 1);
  const std::string hadTauSelection_part1 = (dynamic_cast<TObjString*>(hadTauSelection_parts->At(0)))->GetString().Data();
  const int hadTauSelection = get_selection(hadTauSelection_part1);
  std::string hadTauSelection_part2 = ( hadTauSelection_parts->GetEntries() == 2 ) ? (dynamic_cast<TObjString*>(hadTauSelection_parts->At(1)))->GetString().Data() : "";
  delete hadTauSelection_parts;

  bool apply_hadTauGenMatching = cfg_analyze.getParameter<bool>("apply_hadTauGenMatching");
  std::vector<hadTauGenMatchEntry> hadTauGenMatch_definitions = getHadTauGenMatch_definitions_2tau(apply_hadTauGenMatching);
  std::cout << "hadTauGenMatch_definitions:" << std::endl;
  std::cout << hadTauGenMatch_definitions;

  enum { kOS, kSS };
  std::string hadTauChargeSelection_string = cfg_analyze.getParameter<std::string>("hadTauChargeSelection");
  int hadTauChargeSelection = -1;
  if      ( hadTauChargeSelection_string == "OS" ) hadTauChargeSelection = kOS;
  else if ( hadTauChargeSelection_string == "SS" ) hadTauChargeSelection = kSS;
  else throw cms::Exception("analyze_0l_2tau")
    << "Invalid Configuration parameter 'hadTauChargeSelection' = " << hadTauChargeSelection_string << " !!\n";

  bool isMC = cfg_analyze.getParameter<bool>("isMC");
  bool isMC_tH = ( process_string == "tHq" || process_string == "tHW" ) ? true : false;
  bool hasLHE = cfg_analyze.getParameter<bool>("hasLHE");
  std::string central_or_shift = cfg_analyze.getParameter<std::string>("central_or_shift");
  double lumiScale = ( process_string != "data_obs" ) ? cfg_analyze.getParameter<double>("lumiScale") : 1.;
  bool apply_genWeight = cfg_analyze.getParameter<bool>("apply_genWeight");
  bool apply_DYMCReweighting = cfg_analyze.getParameter<bool>("apply_DYMCReweighting");
  bool apply_DYMCNormScaleFactors = cfg_analyze.getParameter<bool>("apply_DYMCNormScaleFactors");
  bool apply_hlt_filter = cfg_analyze.getParameter<bool>("apply_hlt_filter");
  bool apply_met_filters = cfg_analyze.getParameter<bool>("apply_met_filters");
  edm::ParameterSet cfgMEtFilter = cfg_analyze.getParameter<edm::ParameterSet>("cfgMEtFilter");
  MEtFilterSelector metFilterSelector(cfgMEtFilter, isMC);

  const bool useNonNominal = cfg_analyze.getParameter<bool>("useNonNominal");
  const bool useNonNominal_jetmet = useNonNominal || ! isMC;

  const edm::ParameterSet syncNtuple_cfg = cfg_analyze.getParameter<edm::ParameterSet>("syncNtuple");
  const std::string syncNtuple_tree = syncNtuple_cfg.getParameter<std::string>("tree");
  const std::string syncNtuple_output = syncNtuple_cfg.getParameter<std::string>("output");
  const bool sync_requireGenMatching = syncNtuple_cfg.getParameter<bool>("requireGenMatching");
  const bool do_sync = ! syncNtuple_tree.empty() && ! syncNtuple_output.empty();

  const edm::ParameterSet additionalEvtWeight = cfg_analyze.getParameter<edm::ParameterSet>("evtWeight");
  const bool applyAdditionalEvtWeight = additionalEvtWeight.getParameter<bool>("apply");
  EvtWeightManager * eventWeightManager = nullptr;
  if(applyAdditionalEvtWeight)
  {
    eventWeightManager = new EvtWeightManager(additionalEvtWeight);
  }

  bool isDEBUG = cfg_analyze.getParameter<bool>("isDEBUG");
  if ( isDEBUG ) std::cout << "Warning: DEBUG mode enabled -> trigger selection will not be applied for data !!" << std::endl;

  checkOptionValidity(central_or_shift, isMC);
  const int hadTauPt_option         = getHadTauPt_option       (central_or_shift);
  const int jetToTauFakeRate_option = getJetToTauFR_option     (central_or_shift);
  const int lheScale_option         = getLHEscale_option       (central_or_shift);
  const int jetBtagSF_option        = getBTagWeight_option     (central_or_shift);
  const PUsys puSys_option          = getPUsys_option          (central_or_shift);
  const int dyMCReweighting_option  = getDYMCReweighting_option(central_or_shift);
  const int dyMCNormScaleFactors_option  = getDYMCNormScaleFactors_option(central_or_shift);

  const int met_option   = useNonNominal_jetmet ? kMEt_central_nonNominal : getMET_option(central_or_shift, isMC);
  const int jetPt_option = useNonNominal_jetmet ? kJet_central_nonNominal : getJet_option(central_or_shift, isMC);

  std::cout
    << "central_or_shift = "               << central_or_shift           << "\n"
       " -> hadTauPt_option            = " << hadTauPt_option            << "\n"
       " -> jetToTauFakeRate_option    = " << jetToTauFakeRate_option    << "\n"
       " -> lheScale_option            = " << lheScale_option            << "\n"
       " -> jetBtagSF_option           = " << jetBtagSF_option           << "\n"
       " -> met_option                 = " << met_option                 << "\n"
       " -> jetPt_option               = " << jetPt_option               << "\n"
       " -> dyMCReweighting_option     = " << dyMCReweighting_option     << '\n'
  ;

  DYMCReweighting * dyReweighting = nullptr;
  if(apply_DYMCReweighting)
  {
    dyReweighting = new DYMCReweighting(era, dyMCReweighting_option);
  }
  DYMCNormScaleFactors* dyNormScaleFactors = nullptr;
  if ( apply_DYMCNormScaleFactors ) {
    dyNormScaleFactors = new DYMCNormScaleFactors(era, dyMCNormScaleFactors_option);
  }

  edm::ParameterSet cfg_dataToMCcorrectionInterface;
  cfg_dataToMCcorrectionInterface.addParameter<std::string>("era", era_string);
  cfg_dataToMCcorrectionInterface.addParameter<std::string>("hadTauSelection", hadTauSelection_part2);
  cfg_dataToMCcorrectionInterface.addParameter<int>("hadTauSelection_antiElectron", hadTauSelection_antiElectron);
  cfg_dataToMCcorrectionInterface.addParameter<int>("hadTauSelection_antiMuon", hadTauSelection_antiMuon);
  cfg_dataToMCcorrectionInterface.addParameter<std::string>("central_or_shift", central_or_shift);
  if(era == kEra_2016)
  {
    const edm::ParameterSet cfg_triggerSF_2tau = cfg_analyze.getParameter<edm::ParameterSet>("triggerSF_2tau");
    cfg_dataToMCcorrectionInterface.addParameter<edm::ParameterSet>("triggerSF_2tau", cfg_triggerSF_2tau);
  }
  Data_to_MC_CorrectionInterface_Base * dataToMCcorrectionInterface = nullptr;
  switch(era)
  {
    case kEra_2016: dataToMCcorrectionInterface = new Data_to_MC_CorrectionInterface_2016(cfg_dataToMCcorrectionInterface); break;
    case kEra_2017: dataToMCcorrectionInterface = new Data_to_MC_CorrectionInterface_2017(cfg_dataToMCcorrectionInterface); break;
    case kEra_2018: dataToMCcorrectionInterface = new Data_to_MC_CorrectionInterface_2018(cfg_dataToMCcorrectionInterface); break;
    default: throw cmsException("analyze_0l_2tau", __LINE__) << "Invalid era = " << era;
  }
  Data_to_MC_CorrectionInterface_0l_2tau_trigger* dataToMCcorrectionInterface_0l_2tau_trigger = new Data_to_MC_CorrectionInterface_0l_2tau_trigger(cfg_dataToMCcorrectionInterface);

  std::string applyFakeRateWeights_string = cfg_analyze.getParameter<std::string>("applyFakeRateWeights");
  int applyFakeRateWeights = -1;
  if      ( applyFakeRateWeights_string == "disabled" ) applyFakeRateWeights = kFR_disabled;
  else if ( applyFakeRateWeights_string == "2tau"     ) applyFakeRateWeights = kFR_2tau;
  else throw cms::Exception("analyze_0l_2tau")
    << "Invalid Configuration parameter 'applyFakeRateWeights' = " << applyFakeRateWeights_string << " !!\n";
  bool selectBDT = cfg_analyze.getParameter<bool>("selectBDT");

  JetToTauFakeRateInterface* jetToTauFakeRateInterface = 0;
  if ( applyFakeRateWeights == kFR_2tau ) {
    edm::ParameterSet cfg_hadTauFakeRateWeight = cfg_analyze.getParameter<edm::ParameterSet>("hadTauFakeRateWeight");
    cfg_hadTauFakeRateWeight.addParameter<std::string>("hadTauSelection", hadTauSelection_part2);
    jetToTauFakeRateInterface = new JetToTauFakeRateInterface(cfg_hadTauFakeRateWeight, jetToTauFakeRate_option);
  }

  bool fillGenEvtHistograms = cfg_analyze.getParameter<bool>("fillGenEvtHistograms");
  edm::ParameterSet cfg_EvtYieldHistManager = cfg_analyze.getParameter<edm::ParameterSet>("cfgEvtYieldHistManager");

  std::string branchName_electrons = cfg_analyze.getParameter<std::string>("branchName_electrons");
  std::string branchName_muons = cfg_analyze.getParameter<std::string>("branchName_muons");
  std::string branchName_hadTaus = cfg_analyze.getParameter<std::string>("branchName_hadTaus");
  std::string branchName_jets = cfg_analyze.getParameter<std::string>("branchName_jets");
  std::string branchName_met = cfg_analyze.getParameter<std::string>("branchName_met");
  std::string branchName_jetsHTTv2 = cfg_analyze.getParameter<std::string>("branchName_jetsHTTv2");
  std::string branchName_subjetsHTTv2 = cfg_analyze.getParameter<std::string>("branchName_subjetsHTTv2");
  std::string branchName_jetsAK8 = cfg_analyze.getParameter<std::string>("branchName_jetsAK8");
  std::string branchName_subjetsAK8 = cfg_analyze.getParameter<std::string>("branchName_subjetsAK8");

  std::string branchName_genLeptons = cfg_analyze.getParameter<std::string>("branchName_genLeptons");
  std::string branchName_genHadTaus = cfg_analyze.getParameter<std::string>("branchName_genHadTaus");
  std::string branchName_genPhotons = cfg_analyze.getParameter<std::string>("branchName_genPhotons");
  std::string branchName_genJets = cfg_analyze.getParameter<std::string>("branchName_genJets");

  std::string branchName_genTauLeptons = cfg_analyze.getParameter<std::string>("branchName_genTauLeptons");

  std::string branchName_genTopQuarks = cfg_analyze.getParameter<std::string>("branchName_genTopQuarks");
  std::string branchName_genBJets = cfg_analyze.getParameter<std::string>("branchName_genBJets");
  std::string branchName_genWBosons = cfg_analyze.getParameter<std::string>("branchName_genWBosons");
  std::string branchName_genWJets = cfg_analyze.getParameter<std::string>("branchName_genWJets");
  std::string branchName_genQuarkFromTop = cfg_analyze.getParameter<std::string>("branchName_genQuarkFromTop");

  bool redoGenMatching = cfg_analyze.exists("redoGenMatching") ? cfg_analyze.getParameter<bool>("redoGenMatching") : true;

  std::string selEventsFileName_input = cfg_analyze.getParameter<std::string>("selEventsFileName_input");
  std::cout << "selEventsFileName_input = " << selEventsFileName_input << std::endl;
  RunLumiEventSelector* run_lumi_eventSelector = 0;
  if ( selEventsFileName_input != "" ) {
    edm::ParameterSet cfg_runLumiEventSelector;
    cfg_runLumiEventSelector.addParameter<std::string>("inputFileName", selEventsFileName_input);
    cfg_runLumiEventSelector.addParameter<std::string>("separator", ":");
    run_lumi_eventSelector = new RunLumiEventSelector(cfg_runLumiEventSelector);
  }

  std::string selEventsFileName_output = cfg_analyze.getParameter<std::string>("selEventsFileName_output");
  std::cout << "selEventsFileName_output = " << selEventsFileName_output << std::endl;

  const double minPt_hadTau_lead    = 40.;
  const double minPt_hadTau_sublead = 40.;

  fwlite::InputSource inputFiles(cfg);
  int maxEvents = inputFiles.maxEvents();
  std::cout << " maxEvents = " << maxEvents << std::endl;
  unsigned reportEvery = inputFiles.reportAfter();

  fwlite::OutputFiles outputFile(cfg);
  fwlite::TFileService fs = fwlite::TFileService(outputFile.file().data());

  TTreeWrapper * inputTree = new TTreeWrapper(treeName.data(), inputFiles.files(), maxEvents);

  std::cout << "Loaded " << inputTree -> getFileCount() << " file(s).\n";

//--- prepare sync Ntuple
  SyncNtupleManager * snm = nullptr;
  if(do_sync)
  {
    snm = new SyncNtupleManager(syncNtuple_output, syncNtuple_tree);
    snm->initializeBranches();
    snm->initializeHLTBranches({ triggers_2tau });
  }

//--- declare event-level variables
  EventInfo eventInfo(isSignal, isMC, isMC_tH);
  EventInfoReader eventInfoReader(&eventInfo, puSys_option);
  inputTree -> registerReader(&eventInfoReader);

  hltPathReader hltPathReader_instance(triggers_2tau);
  inputTree -> registerReader(&hltPathReader_instance);

  if(eventWeightManager)
  {
    inputTree->registerReader(eventWeightManager);
  }

//--- declare particle collections
  const bool readGenObjects = isMC && !redoGenMatching;
  RecoMuonReader* muonReader = new RecoMuonReader(era, branchName_muons, readGenObjects);
  inputTree -> registerReader(muonReader);
  RecoMuonCollectionGenMatcher muonGenMatcher;
  RecoMuonCollectionSelectorLoose preselMuonSelector(era, -1, isDEBUG);
  RecoMuonCollectionSelectorFakeable fakeableMuonSelector(era, -1, isDEBUG);
  RecoMuonCollectionSelectorTight tightMuonSelector(era, -1, isDEBUG);
  tightMuonSelector.getSelector().set_min_mvaTTH(lep_mva_cut);

  RecoElectronReader* electronReader = new RecoElectronReader(era, branchName_electrons, readGenObjects);
  electronReader->readUncorrected(useNonNominal);
  inputTree -> registerReader(electronReader);
  RecoElectronCollectionGenMatcher electronGenMatcher;
  RecoElectronCollectionCleaner electronCleaner(0.3, isDEBUG);
  RecoElectronCollectionSelectorLoose preselElectronSelector(era, -1, isDEBUG);
  RecoElectronCollectionSelectorFakeable fakeableElectronSelector(era, -1, isDEBUG);
  fakeableElectronSelector.disable_offline_e_trigger_cuts();
  RecoElectronCollectionSelectorTight tightElectronSelector(era, -1, isDEBUG);
  tightElectronSelector.disable_offline_e_trigger_cuts();
  tightElectronSelector.getSelector().set_min_mvaTTH(lep_mva_cut);

  RecoHadTauReader* hadTauReader = new RecoHadTauReader(era, branchName_hadTaus, readGenObjects);
  hadTauReader->setHadTauPt_central_or_shift(hadTauPt_option);
  inputTree -> registerReader(hadTauReader);
  RecoHadTauCollectionGenMatcher hadTauGenMatcher;
  RecoHadTauCollectionCleaner hadTauCleaner(0.3);
  RecoHadTauCollectionSelectorLoose preselHadTauSelector(era, -1, isDEBUG);
  preselHadTauSelector.set_if_looser(hadTauSelection_part2);
  preselHadTauSelector.set_min_antiElectron(hadTauSelection_antiElectron);
  preselHadTauSelector.set_min_antiMuon(hadTauSelection_antiMuon);
  RecoHadTauCollectionSelectorFakeable fakeableHadTauSelector(era, -1, isDEBUG);
  fakeableHadTauSelector.set_if_looser(hadTauSelection_part2);
  fakeableHadTauSelector.set_min_antiElectron(hadTauSelection_antiElectron);
  fakeableHadTauSelector.set_min_antiMuon(hadTauSelection_antiMuon);
  RecoHadTauCollectionSelectorTight tightHadTauSelector(era, -1, isDEBUG);
  tightHadTauSelector.set(hadTauSelection_part2);
  tightHadTauSelector.set_min_antiElectron(hadTauSelection_antiElectron);
  tightHadTauSelector.set_min_antiMuon(hadTauSelection_antiMuon);

  RecoJetReader* jetReader = new RecoJetReader(era, isMC, branchName_jets, readGenObjects);
  jetReader->setPtMass_central_or_shift(jetPt_option);
  jetReader->setBranchName_BtagWeight(jetBtagSF_option);
  inputTree -> registerReader(jetReader);
  RecoJetCollectionGenMatcher jetGenMatcher;
  RecoJetCollectionCleaner jetCleaner(0.4, isDEBUG);
  RecoJetCollectionCleaner jetCleaner_large8(0.8, isDEBUG);
  RecoJetCollectionSelector jetSelector(era, -1, isDEBUG);
  RecoJetCollectionSelectorBtagLoose jetSelectorBtagLoose(era, -1, isDEBUG);
  RecoJetCollectionSelectorBtagMedium jetSelectorBtagMedium(era, -1, isDEBUG);

  RecoJetReaderHTTv2* jetReaderHTTv2 = new RecoJetReaderHTTv2(era, branchName_jetsHTTv2, branchName_subjetsHTTv2);
  inputTree -> registerReader(jetReaderHTTv2);
  RecoJetCollectionSelectorHTTv2 jetSelectorHTTv2(era);
  RecoJetCollectionCleanerHTTv2 jetCleanerHTTv2(1.5, isDEBUG); //to clean against leptons and hadronic taus
  RecoJetCollectionCleanerHTTv2SubJets jetCleanerHTTv2SubJets(0.4, isDEBUG); //to clean against leptons and hadronic taus

  RecoJetReaderAK8* jetReaderAK8 = new RecoJetReaderAK8(era, branchName_jetsAK8, branchName_subjetsAK8);
  inputTree -> registerReader(jetReaderAK8);
  RecoJetCollectionSelectorAK8 jetSelectorAK8(era);
  RecoJetCollectionCleanerAK8 jetCleanerAK8(0.8, isDEBUG); //to clean against leptons and hadronic taus
  RecoJetCollectionCleanerAK8SubJets jetCleanerAK8SubJets(0.4, isDEBUG); //to clean against leptons and hadronic taus

  GenParticleReader* genTauLeptonReader = nullptr;
  if ( isMC && (apply_DYMCReweighting || apply_DYMCNormScaleFactors)) {
    genTauLeptonReader = new GenParticleReader(branchName_genTauLeptons);
    inputTree->registerReader(genTauLeptonReader);
  }

  GenParticleReader* genTopQuarkReader = new GenParticleReader(branchName_genTopQuarks);
  GenParticleReader* genBJetReader = new GenParticleReader(branchName_genBJets);
  GenParticleReader* genWBosonReader = new GenParticleReader(branchName_genWBosons);
  GenParticleReader* genWJetReader = new GenParticleReader(branchName_genWJets);
  GenParticleReader* genQuarkFromTopReader = new GenParticleReader(branchName_genQuarkFromTop);

  if ( isMC ) {
    inputTree -> registerReader(genTopQuarkReader);
    inputTree -> registerReader(genBJetReader);
    inputTree -> registerReader(genWBosonReader);
    inputTree -> registerReader(genWJetReader);
    inputTree -> registerReader(genQuarkFromTopReader);
  }

//--- declare missing transverse energy
  RecoMEtReader* metReader = new RecoMEtReader(era, isMC, branchName_met);
  metReader->setMEt_central_or_shift(met_option);
  inputTree -> registerReader(metReader);

  MEtFilter metFilters;
  MEtFilterReader* metFilterReader = new MEtFilterReader(&metFilters, era);
  inputTree -> registerReader(metFilterReader);

  GenLeptonReader* genLeptonReader = 0;
  GenHadTauReader* genHadTauReader = 0;
  GenPhotonReader* genPhotonReader = 0;
  GenJetReader* genJetReader = 0;
  LHEInfoReader* lheInfoReader = 0;
  if ( isMC ) {
    if ( !readGenObjects ) {
      if ( branchName_genLeptons != "" ) {
        genLeptonReader = new GenLeptonReader(branchName_genLeptons);
        inputTree -> registerReader(genLeptonReader);
      }
      if ( branchName_genHadTaus != "" ) {
        genHadTauReader = new GenHadTauReader(branchName_genHadTaus);
        inputTree -> registerReader(genHadTauReader);
      }
      if ( branchName_genPhotons != "" ) {
        genPhotonReader = new GenPhotonReader(branchName_genPhotons);
        inputTree -> registerReader(genPhotonReader);
      }
      if ( branchName_genJets != "" ) {
        genJetReader = new GenJetReader(branchName_genJets);
        inputTree -> registerReader(genJetReader);
      }
    }
    lheInfoReader = new LHEInfoReader(hasLHE);
    inputTree -> registerReader(lheInfoReader);
  }

  //--- initialize hadronic top tagger BDT
  HadTopTagger* hadTopTagger = new HadTopTagger();
  HadTopTagger_boosted* hadTopTagger_boosted = new HadTopTagger_boosted();
  HadTopTagger_semi_boosted_AK8* hadTopTagger_semi_boosted_fromAK8 = new HadTopTagger_semi_boosted_AK8();

  //--- initialize BDTs used to discriminate ttH vs. ttbar trained by Arun for 0l_2tau category
  std::string mvaFileName_0l_2tau_ttbar = "tthAnalysis/HiggsToTauTau/data/0l_2tau_ttbar_BDTG.weights.xml";
  std::vector<std::string> mvaInputVariables_0l_2tau_ttbar;
  mvaInputVariables_0l_2tau_ttbar.push_back("nJet");
  mvaInputVariables_0l_2tau_ttbar.push_back("nBJetLoose");
  mvaInputVariables_0l_2tau_ttbar.push_back("nBJetMedium");
  mvaInputVariables_0l_2tau_ttbar.push_back("mindr_tau1_jet");
  mvaInputVariables_0l_2tau_ttbar.push_back("mindr_tau2_jet");
  mvaInputVariables_0l_2tau_ttbar.push_back("avg_dr_jet");
  mvaInputVariables_0l_2tau_ttbar.push_back("ptmiss");
  mvaInputVariables_0l_2tau_ttbar.push_back("mT_tau1");
  mvaInputVariables_0l_2tau_ttbar.push_back("mT_tau2");
  mvaInputVariables_0l_2tau_ttbar.push_back("htmiss");
  mvaInputVariables_0l_2tau_ttbar.push_back("tau1_pt");
  mvaInputVariables_0l_2tau_ttbar.push_back("tau2_pt");
  mvaInputVariables_0l_2tau_ttbar.push_back("TMath::Abs(tau1_eta)");
  mvaInputVariables_0l_2tau_ttbar.push_back("TMath::Abs(tau2_eta)");
  mvaInputVariables_0l_2tau_ttbar.push_back("dr_taus");
  mvaInputVariables_0l_2tau_ttbar.push_back("mTauTauVis");
  mvaInputVariables_0l_2tau_ttbar.push_back("mTauTau");
  TMVAInterface mva_0l_2tau_ttbar(mvaFileName_0l_2tau_ttbar, mvaInputVariables_0l_2tau_ttbar, { "tau1_mva", "tau2_mva" });

  std::map<std::string, double> mvaInputs_ttbar;

  //--- initialize XGBs used to discriminate ttH vs. ttbar
  // Arun training
  std::string xgbFileName_0l_2tau_ttbar = "tthAnalysis/HiggsToTauTau/data/0l_2tau_XGB_HTTWithKinFitReduced_evtLevelTT_TTH_19Var.pkl";
  //--- initialize XGBs used to discriminate ttH vs. ttV
  std::string xgbFileName_0l_2tau_ttv = "tthAnalysis/HiggsToTauTau/data/0l_2tau_XGB_HTTWithKinFitReduced_evtLevelTTV_TTH_16Var.pkl";
  //--- initialize XGBs used to discriminate ttH vs. ttbar+ttV
  std::string xgbFileName_0l_2tau_sum = "tthAnalysis/HiggsToTauTau/data/0l_2tau_XGB_HTTWithKinFitReduced_evtLevelSUM_TTH_19Var.pkl";
  //--- initialize XGBs used to discriminate ttH vs. ttbar+ttV+DY
  std::string xgbFileName_0l_2tau_sum_dy = "tthAnalysis/HiggsToTauTau/data/0l_2tau_XGB_HTTWithKinFitReduced_evtLevelSUMwDY_TTH_22Var.pkl";
  std::vector<std::string> xgbInputVariables_0l_2tau_ttbar =
    { "mindr_tau1_jet", "mindr_tau2_jet", "avg_dr_jet", "ptmiss", "htmiss", "tau1_pt", "tau2_pt", "tau1_eta", "tau2_eta",
      "dr_taus", "mT_tau1", "mT_tau2", "mTauTauVis", "mTauTau", "HTT_wKinFit_top1", "HadTop1_pt", "HadTop1_eta", "HTT_wKinFit_top2",
      "HadTop2_pt", "nJet"};
  std::vector<std::string> xgbInputVariables_0l_2tau_ttv =
    { "mindr_tau1_jet", "mindr_tau2_jet", "avg_dr_jet", "ptmiss", "htmiss", "tau1_pt", "tau2_pt", "tau1_eta", "tau2_eta",
      "dr_taus", "mT_tau1", "mT_tau2", "mTauTauVis", "mTauTau", "HTT_wKinFit_top1", "HTT_wKinFit_top2", "nJet"};
  std::vector<std::string> xgbInputVariables_0l_2tau_dy =
    { "mindr_tau1_jet", "mindr_tau2_jet", "avg_dr_jet", "ptmiss", "htmiss", "tau1_pt", "tau2_pt", "tau1_eta", "tau2_eta",
      "dr_taus", "mT_tau1", "mT_tau2", "mTauTauVis", "mTauTau", "HTT_wKinFit_top1", "HadTop1_pt", "HadTop1_eta", "HTT_wKinFit_top2",
      "HadTop2_pt", "nJet", "nBJetLoose", "nBJetMedium"};

  XGBInterface xgb_0l_2tau_ttbar(xgbFileName_0l_2tau_ttbar, xgbInputVariables_0l_2tau_ttbar);
  XGBInterface xgb_0l_2tau_ttv(xgbFileName_0l_2tau_ttv, xgbInputVariables_0l_2tau_ttv);
  XGBInterface xgb_0l_2tau_sum(xgbFileName_0l_2tau_sum, xgbInputVariables_0l_2tau_ttbar);
  XGBInterface xgb_0l_2tau_sum_dy(xgbFileName_0l_2tau_sum_dy, xgbInputVariables_0l_2tau_dy);
  std::map<std::string, double> xgbInputs_ttbar;
  std::map<std::string, double> xgbInputs_ttv;
  std::map<std::string, double> xgbInputs_dy;
  //2D map for ttbar vs ttV
  const LocalFileInPath mapFileName_fip("tthAnalysis/HiggsToTauTau/data/HTT_from20_to_10bins_relLepIDFalse_CumulativeBins.root");
  TFile * fmap = TFile::Open(mapFileName_fip.fullPath().c_str(), "read");
  TH2F * hTargetBinning = static_cast<TH2F *>(fmap->Get("hTargetBinning"));

  // BDTs calculated by Xanda
  std::string mvaFileName_XGB_Updated = "tthAnalysis/HiggsToTauTau/data/BDTs_2017MC_postPAS/0l_2tau_XGB_Updated_evtLevelSUM_TTH_20Var.xml";
  std::vector<std::string> mvaInputVariables_XGB_Updated = {
    "mindr_tau1_jet", "mindr_tau2_jet",
    "avg_dr_jet", "ptmiss", "tau1_pt", "tau2_pt", "tau1_eta", "tau2_eta",
    "dr_taus", "mT_tau1", "mT_tau2", "mTauTauVis", "mTauTau", "nJet",
    "nBJetLoose", "nBJetMedium",
    "res-HTT_CSVsort4rd_2", "res-HTT_CSVsort4rd", "HadTop_pt_CSVsort4rd_2", "HadTop_pt_CSVsort4rd"
  };
  TMVAInterface mva_XGB_Updated(mvaFileName_XGB_Updated, mvaInputVariables_XGB_Updated);
  mva_XGB_Updated.enableBDTTransform();
  std::map<std::string, double> mvaInputs_XGB_Updated;

  std::string mvaFileName_XGB_Boosted_AK8 = "tthAnalysis/HiggsToTauTau/data/BDTs_2017MC_postPAS/0l_2tau_XGB_Boosted_AK8_evtLevelSUM_TTH_25Var.xml";
  std::vector<std::string> mvaInputVariables_XGB_Boosted_AK8 = {
    "mindr_tau1_jet", "mindr_tau2_jet",
    "avg_dr_jet", "ptmiss", "tau1_pt", "tau2_pt", "tau1_eta", "tau2_eta",
    "dr_taus", "mT_tau1", "mT_tau2", "mTauTauVis", "mTauTau", "nJet",
    "nBJetLoose", "nBJetMedium",
    "res-HTT_CSVsort4rd_2", "res-HTT_CSVsort4rd", "HadTop_pt_CSVsort4rd",
    "resolved_and_semi_AK8", "boosted_and_semi_AK8", "minDR_HTTv2_lep", "minDR_AK8_lep", "HTT_boosted", "HTT_semi_boosted_fromAK8"
  };
  TMVAInterface mva_XGB_Boosted_AK8(mvaFileName_XGB_Boosted_AK8, mvaInputVariables_XGB_Boosted_AK8);
  mva_XGB_Boosted_AK8.enableBDTTransform();
  std::map<std::string, double> mvaInputs_XGB_Boosted_AK8;

//--- open output file containing run:lumi:event numbers of events passing final event selection criteria
  std::ostream* selEventsFile = ( selEventsFileName_output != "" ) ? new std::ofstream(selEventsFileName_output.data(), std::ios::out) : 0;

//--- declare histograms
  struct selHistManagerType
  {
    ElectronHistManager* electrons_;
    MuonHistManager* muons_;
    HadTauHistManager* hadTaus_;
    HadTauHistManager* leadHadTau_;
    HadTauHistManager* subleadHadTau_;
    JetHistManager* jets_;
    JetHistManager* leadJet_;
    JetHistManager* subleadJet_;
    JetHistManager* BJets_loose_;
    JetHistManager* leadBJet_loose_;
    JetHistManager* subleadBJet_loose_;
    JetHistManager* BJets_medium_;
    MEtHistManager* met_;
    MEtFilterHistManager* metFilters_;
    MVAInputVarHistManager* mvaInputVariables_ttbar_;
    //MVAInputVarHistManager* mvaInputVariables_ttV_;
    //MVAInputVarHistManager* xgbInputVariables_ttbar_;
    EvtHistManager_0l_2tau* evt_;
    std::map<std::string, EvtHistManager_0l_2tau*> evt_in_decayModes_;
    std::map<std::string, EvtHistManager_0l_2tau*> evt_in_categories_;
    EvtYieldHistManager* evtYield_;
    WeightHistManager* weights_;
  };
  std::map<int, selHistManagerType*> selHistManagers;
  for ( std::vector<hadTauGenMatchEntry>::const_iterator hadTauGenMatch_definition = hadTauGenMatch_definitions.begin();
        hadTauGenMatch_definition != hadTauGenMatch_definitions.end(); ++hadTauGenMatch_definition ) {

    std::string process_and_genMatch = process_string;
    if ( apply_hadTauGenMatching ) process_and_genMatch += hadTauGenMatch_definition->name_;

    int idxHadTau = hadTauGenMatch_definition->idx_;

    selHistManagerType* selHistManager = new selHistManagerType();
    selHistManager->electrons_ = new ElectronHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/electrons", histogramDir.data()), era_string, central_or_shift, "allHistograms"));
    selHistManager->electrons_->bookHistograms(fs);
    selHistManager->muons_ = new MuonHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/muons", histogramDir.data()), era_string, central_or_shift, "allHistograms"));
    selHistManager->muons_->bookHistograms(fs);
    selHistManager->hadTaus_ = new HadTauHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/hadTaus", histogramDir.data()), era_string, central_or_shift, "allHistograms"));
    selHistManager->hadTaus_->bookHistograms(fs);
    selHistManager->leadHadTau_ = new HadTauHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/leadHadTau", histogramDir.data()), era_string, central_or_shift, "minimalHistograms", 0));
    selHistManager->leadHadTau_->bookHistograms(fs);
    selHistManager->subleadHadTau_ = new HadTauHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/subleadHadTau", histogramDir.data()), era_string, central_or_shift, "minimalHistograms", 1));
    selHistManager->subleadHadTau_->bookHistograms(fs);
    selHistManager->jets_ = new JetHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/jets", histogramDir.data()), era_string, central_or_shift, "allHistograms"));
    selHistManager->jets_->bookHistograms(fs);
    selHistManager->leadJet_ = new JetHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/leadJet", histogramDir.data()), era_string, central_or_shift, "minimalHistograms", 0));
    selHistManager->leadJet_->bookHistograms(fs);
    selHistManager->subleadJet_ = new JetHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/subleadJet", histogramDir.data()), era_string, central_or_shift, "minimalHistograms", 1));
    selHistManager->subleadJet_->bookHistograms(fs);
    selHistManager->BJets_loose_ = new JetHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/BJets_loose", histogramDir.data()), era_string, central_or_shift, "allHistograms"));
    selHistManager->BJets_loose_->bookHistograms(fs);
    selHistManager->leadBJet_loose_ = new JetHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/leadBJet_loose", histogramDir.data()), era_string, central_or_shift, "minimalHistograms", 0));
    selHistManager->leadBJet_loose_->bookHistograms(fs);
    selHistManager->subleadBJet_loose_ = new JetHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/subleadBJet_loose", histogramDir.data()), era_string, central_or_shift, "minimalHistograms", 1));
    selHistManager->subleadBJet_loose_->bookHistograms(fs);
    selHistManager->BJets_medium_ = new JetHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/BJets_medium", histogramDir.data()), era_string, central_or_shift, "allHistograms"));
    selHistManager->BJets_medium_->bookHistograms(fs);
    selHistManager->met_ = new MEtHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/met", histogramDir.data()), era_string, central_or_shift));
    selHistManager->met_->bookHistograms(fs);
    selHistManager->metFilters_ = new MEtFilterHistManager(makeHistManager_cfg(process_and_genMatch,
        Form("%s/sel/metFilters", histogramDir.data()), era_string, central_or_shift));
      selHistManager->metFilters_->bookHistograms(fs);
    selHistManager->mvaInputVariables_ttbar_ = new MVAInputVarHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/mvaInputs_ttbar", histogramDir.data()), era_string, central_or_shift));
    selHistManager->mvaInputVariables_ttbar_->bookHistograms(fs, mvaInputVariables_0l_2tau_ttbar);
    //selHistManager->mvaInputVariables_ttV_ = new MVAInputVarHistManager(makeHistManager_cfg(process_and_genMatch,
    //  Form("%s/sel/mvaInputs_ttV", histogramDir.data()), era_string, central_or_shift));
    //selHistManager->mvaInputVariables_ttV_->bookHistograms(fs, mvaInputVariables_0l_2tau_ttV);
    //selHistManager->xgbInputVariables_ttbar_ = new MVAInputVarHistManager(makeHistManager_cfg(process_and_genMatch,
    //  Form("%s/sel/xgbInputs_ttbar", histogramDir.data()), era_string, central_or_shift));
    //selHistManager->xgbInputVariables_ttbar_->bookHistograms(fs, xgbInputVariables_0l_2tau_ttbar);
    selHistManager->evt_ = new EvtHistManager_0l_2tau(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/evt", histogramDir.data()), era_string, central_or_shift));
    selHistManager->evt_->bookHistograms(fs);
    const vstring decayModes_evt = eventInfo.getDecayModes();
    if ( isSignal ) {
      for ( vstring::const_iterator decayMode = decayModes_evt.begin();
            decayMode != decayModes_evt.end(); ++decayMode) {

        std::string decayMode_and_genMatch = (*decayMode);
        if ( apply_hadTauGenMatching ) decayMode_and_genMatch += hadTauGenMatch_definition->name_;

        selHistManager->evt_in_decayModes_[*decayMode] = new EvtHistManager_0l_2tau(makeHistManager_cfg(decayMode_and_genMatch,
          Form("%s/sel/evt", histogramDir.data()), era_string, central_or_shift));
        selHistManager->evt_in_decayModes_[*decayMode]->bookHistograms(fs);
      }
    }
    vstring categories_evt = {
      "0l_2tau_0bM_0j", "0l_2tau_1bM_0j", "0l_2tau_2bM_0j",
      "0l_2tau_0bM_1j", "0l_2tau_1bM_1j", "0l_2tau_2bM_1j",
      "0l_2tau_0bM_2j", "0l_2tau_1bM_2j", "0l_2tau_2bM_2j"
      //"0l_2tau_bloose", "0l_2tau_btight"
    };
    for ( vstring::const_iterator category = categories_evt.begin();
          category != categories_evt.end(); ++category ) {
      TString histogramDir_category = histogramDir.data();
      histogramDir_category.ReplaceAll("0l_2tau", category->data());
      selHistManager->evt_in_categories_[*category] = new EvtHistManager_0l_2tau(makeHistManager_cfg(process_and_genMatch,
        Form("%s/sel/evt", histogramDir_category.Data()), era_string, central_or_shift));
      selHistManager->evt_in_categories_[*category]->bookHistograms(fs);
    }
    edm::ParameterSet cfg_EvtYieldHistManager_sel = makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/evtYield", histogramDir.data()), era_string, central_or_shift);
    cfg_EvtYieldHistManager_sel.addParameter<edm::ParameterSet>("runPeriods", cfg_EvtYieldHistManager);
    cfg_EvtYieldHistManager_sel.addParameter<bool>("isMC", isMC);
    selHistManager->evtYield_ = new EvtYieldHistManager(cfg_EvtYieldHistManager_sel);
    selHistManager->evtYield_->bookHistograms(fs);
    selHistManager->weights_ = new WeightHistManager(makeHistManager_cfg(process_and_genMatch,
      Form("%s/sel/weights", histogramDir.data()), era_string, central_or_shift));
    selHistManager->weights_->bookHistograms(fs,
      { "genWeight", "pileupWeight", "data_to_MC_correction", "triggerWeight", "hadTauEff", "fakeRate" });
    selHistManagers[idxHadTau] = selHistManager;
  }

  GenEvtHistManager* genEvtHistManager_beforeCuts = 0;
  GenEvtHistManager* genEvtHistManager_afterCuts = 0;
  LHEInfoHistManager* lheInfoHistManager = 0;
  if ( isMC ) {
    genEvtHistManager_beforeCuts = new GenEvtHistManager(makeHistManager_cfg(process_string,
      Form("%s/unbiased/genEvt", histogramDir.data()), era_string, central_or_shift));
    genEvtHistManager_beforeCuts->bookHistograms(fs);
    genEvtHistManager_afterCuts = new GenEvtHistManager(makeHistManager_cfg(process_string,
      Form("%s/sel/genEvt", histogramDir.data()), era_string, central_or_shift));
    genEvtHistManager_afterCuts->bookHistograms(fs);
     lheInfoHistManager = new LHEInfoHistManager(makeHistManager_cfg(process_string,
      Form("%s/sel/lheInfo", histogramDir.data()), era_string, central_or_shift));
    lheInfoHistManager->bookHistograms(fs);

    if(eventWeightManager)
    {
      genEvtHistManager_beforeCuts->bookHistograms(fs, eventWeightManager);
      genEvtHistManager_afterCuts->bookHistograms(fs, eventWeightManager);
    }
  }

  NtupleFillerBDT<float, int> * bdt_filler = nullptr;
  typedef std::remove_pointer<decltype(bdt_filler)>::type::float_type float_type;
  typedef std::remove_pointer<decltype(bdt_filler)>::type::int_type   int_type;
  if(selectBDT)
  {
    bdt_filler = new std::remove_pointer<decltype(bdt_filler)>::type(
      makeHistManager_cfg(process_string, Form("%s/sel/evtntuple", histogramDir.data()), era_string, central_or_shift)
    );
    bdt_filler -> register_variable<float_type>(
      "mindr_tau1_jet", "mindr_tau2_jet",
      "avg_dr_jet", "ptmiss", "htmiss", "tau1_mva", "tau2_mva", "tau1_pt", "tau2_pt",
      "tau1_eta", "tau2_eta", "dr_taus", "mT_tau1", "mT_tau2", //"Pzeta", "PzetaVis",
      "mTauTauVis", "mTauTau",
      "res-HTT_CSVsort4rd", "res-HTT_CSVsort4rd_2",
      "HadTop_pt_CSVsort4rd", "HadTop_pt_CSVsort4rd_2",
      "genTopPt_CSVsort4rd", "genTopPt_CSVsort4rd_2",
      "HTT_boosted", "genTopPt_boosted", "HadTop_pt_boosted",
      "HTT_semi_boosted_fromAK8", "genTopPt_semi_boosted_fromAK8", "HadTop_pt_semi_boosted_fromAK8",
      "minDR_HTTv2_lep", "minDR_AK8_lep",
      "minDR_HTTv2subjets_lep", "minDR_AK8subjets_lep",
      "mva_Boosted_AK8", "mva_Updated",
      "lumiScale", "genWeight", "evtWeight"
    );
    bdt_filler -> register_variable<int_type>(
      "nJet", "nBJetLoose", "nBJetMedium",
      "nHTTv2", "N_jetAK8", "cleanedJets_fromAK8",
      "hadtruth", "hadtruth_2",
      "bWj1Wj2_isGenMatched_CSVsort4rd", "bWj1Wj2_isGenMatched_CSVsort4rd_2",
      "hadtruth_boosted", "hadtruth_semi_boosted_fromAK8",
      "bWj1Wj2_isGenMatched_boosted", "bWj1Wj2_isGenMatched_semi_boosted_fromAK8",
      "resolved_and_semi_AK8", "boosted_and_semi_AK8", "resolved_and_boosted"
      //"passesTight_hadTau_lead", "passesTight_hadTau_sublead"
    );
    bdt_filler -> bookTree(fs);
  }

  int analyzedEntries = 0;
  int selectedEntries = 0;
  double selectedEntries_weighted = 0.;
  TH1* histogram_analyzedEntries = fs.make<TH1D>("analyzedEntries", "analyzedEntries", 1, -0.5, +0.5);
  TH1* histogram_selectedEntries = fs.make<TH1D>("selectedEntries", "selectedEntries", 1, -0.5, +0.5);
  cutFlowTableType cutFlowTable;
  const edm::ParameterSet cutFlowTableCfg = makeHistManager_cfg(
    process_string, Form("%s/sel/cutFlow", histogramDir.data()), era_string, central_or_shift
  );
  const std::vector<std::string> cuts = {
    "run:ls:event selection",
    "trigger",
    ">= 2 presel taus",
    ">= 2 jets",
    ">= 2 loose b-jets || 1 medium b-jet (1)",
    ">= 2 sel taus",
    "no tight leptons",
    "HLT filter matching",
    ">= 4 jets",
    ">= 2 loose b-jets || 1 medium b-jet (2)",
    "m(ll) > 12 GeV",
    Form("lead hadTau pT > %.0f GeV && abs(eta) < 2.1", minPt_hadTau_lead),
    Form("sublead hadTau pT > %.0f GeV && abs(eta) < 2.1", minPt_hadTau_sublead),
    "tau-pair OS/SS charge",
    "MEt filters",
    "signal region veto",
  };
  CutFlowTableHistManager * cutFlowHistManager = new CutFlowTableHistManager(cutFlowTableCfg, cuts);
  cutFlowHistManager->bookHistograms(fs);
  while(inputTree -> hasNextEvent() && (! run_lumi_eventSelector || (run_lumi_eventSelector && ! run_lumi_eventSelector -> areWeDone())))
  {
    if(inputTree -> canReport(reportEvery))
    {
      std::cout << "processing Entry " << inputTree -> getCurrentMaxEventIdx()
                << " or " << inputTree -> getCurrentEventIdx() << " entry in #"
                << (inputTree -> getProcessedFileCount() - 1)
                << " (" << eventInfo
                << ") file (" << selectedEntries << " Entries selected)\n";
    }
    ++analyzedEntries;
    histogram_analyzedEntries->Fill(0.);

    if ( isDEBUG ) {
      std::cout << "event #" << inputTree -> getCurrentMaxEventIdx() << ' ' << eventInfo << '\n';
    }

    if ( run_lumi_eventSelector && !(*run_lumi_eventSelector)(eventInfo) ) continue;
    cutFlowTable.update("run:ls:event selection");
    cutFlowHistManager->fillHistograms("run:ls:event selection", lumiScale);

    if(run_lumi_eventSelector)
    {
      std::cout << "processing Entry " << inputTree -> getCurrentMaxEventIdx() << ": " << eventInfo << '\n';
      if(inputTree -> isOpen())
      {
        std::cout << "input File = " << inputTree -> getCurrentFileName() << '\n';
      }
    }

//--- build collections of generator level particles (before any cuts are applied, to check distributions in unbiased event samples)
    std::vector<GenLepton> genLeptons;
    std::vector<GenLepton> genElectrons;
    std::vector<GenLepton> genMuons;
    std::vector<GenHadTau> genHadTaus;
    std::vector<GenPhoton> genPhotons;
    std::vector<GenJet> genJets;
    if ( isMC && fillGenEvtHistograms ) {
      if ( genLeptonReader ) {
        genLeptons = genLeptonReader->read();
        for ( std::vector<GenLepton>::const_iterator genLepton = genLeptons.begin();
              genLepton != genLeptons.end(); ++genLepton ) {
          int abs_pdgId = std::abs(genLepton->pdgId());
          if      ( abs_pdgId == 11 ) genElectrons.push_back(*genLepton);
          else if ( abs_pdgId == 13 ) genMuons.push_back(*genLepton);
        }
      }
      if ( genHadTauReader ) {
        genHadTaus = genHadTauReader->read();
      }
      if ( genPhotonReader ) {
        genPhotons = genPhotonReader->read();
      }
      if ( genJetReader ) {
        genJets = genJetReader->read();
      }
    }

    std::vector<GenParticle> genTauLeptons;
    if(isMC && (apply_DYMCReweighting || apply_DYMCNormScaleFactors))
    {
      genTauLeptons = genTauLeptonReader->read();
    }

    double evtWeight_inclusive = 1.;
    if(isMC)
    {
      if(apply_genWeight      ) evtWeight_inclusive *= boost::math::sign(eventInfo.genWeight);
      if(apply_DYMCReweighting) evtWeight_inclusive *= dyReweighting->getWeight(genTauLeptons);
      if(isMC_tH              ) evtWeight_inclusive *= eventInfo.genWeight_tH;
      if(eventWeightManager   ) evtWeight_inclusive *= eventWeightManager->getWeight();
      lheInfoReader->read();
      evtWeight_inclusive *= lheInfoReader->getWeight_scale(lheScale_option);
      evtWeight_inclusive *= eventInfo.pileupWeight;
      evtWeight_inclusive *= lumiScale;
      genEvtHistManager_beforeCuts->fillHistograms(
            genElectrons, genMuons, genHadTaus, genPhotons, genJets, evtWeight_inclusive
      );
      if(eventWeightManager)
      {
        genEvtHistManager_beforeCuts->fillHistograms(eventWeightManager, evtWeight_inclusive);
      }
    }
    std::vector<GenParticle> genTopQuarks;
    std::vector<GenParticle> genBJets;
    std::vector<GenParticle> genWBosons;
    std::vector<GenParticle> genWJets;
    std::vector<GenParticle> genQuarkFromTop;
    if ( isMC ) {
      genTopQuarks = genTopQuarkReader->read();
      genBJets = genBJetReader->read();
      genWBosons = genWBosonReader->read();
      genWJets = genWJetReader->read();
      genQuarkFromTop = genQuarkFromTopReader->read();
    }

    bool isTriggered_2tau = hltPaths_isTriggered(triggers_2tau, isDEBUG);

    bool selTrigger_2tau = use_triggers_2tau && isTriggered_2tau;
    if ( !selTrigger_2tau ) {
      if ( run_lumi_eventSelector ) {
        std::cout << "event " << eventInfo.str() << " FAILS trigger selection." << std::endl;
        std::cout << " (selTrigger_2tau = " << selTrigger_2tau << ")" << std::endl;
      }
      continue;
    }
    cutFlowTable.update("trigger");
    cutFlowHistManager->fillHistograms("trigger", lumiScale);
//--- build collections of electrons, muons and hadronic taus;
//    resolve overlaps in order of priority: muon, electron,
    std::vector<RecoMuon> muons = muonReader->read();
    std::vector<const RecoMuon*> muon_ptrs = convert_to_ptrs(muons);
    std::vector<const RecoMuon*> cleanedMuons = muon_ptrs; // CV: no cleaning needed for muons, as they have the highest priority in the overlap removal
    std::vector<const RecoMuon*> preselMuons = preselMuonSelector(cleanedMuons, isHigherConePt);
    std::vector<const RecoMuon*> fakeableMuons = fakeableMuonSelector(preselMuons, isHigherConePt);
    std::vector<const RecoMuon*> tightMuons = tightMuonSelector(fakeableMuons, isHigherConePt);
    if(isDEBUG || run_lumi_eventSelector)
    {
      printCollection("preselMuons",   preselMuons);
      printCollection("fakeableMuons", fakeableMuons);
      printCollection("tightMuons",    tightMuons);
    }

    std::vector<RecoElectron> electrons = electronReader->read();
    std::vector<const RecoElectron*> electron_ptrs = convert_to_ptrs(electrons);
    std::vector<const RecoElectron*> cleanedElectrons = electronCleaner(electron_ptrs, preselMuons);
    std::vector<const RecoElectron*> preselElectrons = preselElectronSelector(cleanedElectrons, isHigherConePt);
    std::vector<const RecoElectron*> fakeableElectrons = fakeableElectronSelector(preselElectrons, isHigherConePt);
    std::vector<const RecoElectron*> tightElectrons = tightElectronSelector(fakeableElectrons, isHigherConePt);
    if(isDEBUG || run_lumi_eventSelector)
    {
      printCollection("preselElectrons",   preselElectrons);
      printCollection("fakeableElectrons", fakeableElectrons);
      printCollection("tightElectrons",    tightElectrons);
    }

    std::vector<const RecoLepton*> preselLeptons = mergeLeptonCollections(preselElectrons, preselMuons, isHigherConePt);
    std::vector<const RecoLepton*> fakeableLeptons = mergeLeptonCollections(fakeableElectrons, fakeableMuons, isHigherConePt);
    std::vector<const RecoLepton*> tightLeptons = mergeLeptonCollections(tightElectrons, tightMuons, isHigherConePt);

    std::vector<RecoHadTau> hadTaus = hadTauReader->read();
    std::vector<const RecoHadTau*> hadTau_ptrs = convert_to_ptrs(hadTaus);
    std::vector<const RecoHadTau*> cleanedHadTaus = hadTauCleaner(hadTau_ptrs, preselMuons, preselElectrons);
    std::vector<const RecoHadTau*> preselHadTausFull = preselHadTauSelector(cleanedHadTaus, isHigherPt);
    std::vector<const RecoHadTau*> fakeableHadTausFull = fakeableHadTauSelector(preselHadTausFull, isHigherPt);
    std::vector<const RecoHadTau*> tightHadTausFull = tightHadTauSelector(fakeableHadTausFull, isHigherPt);

    std::vector<const RecoHadTau*> preselHadTaus = pickFirstNobjects(preselHadTausFull, 2);
    std::vector<const RecoHadTau*> fakeableHadTaus = pickFirstNobjects(fakeableHadTausFull, 2);
    std::vector<const RecoHadTau*> tightHadTaus = getIntersection(fakeableHadTaus, tightHadTausFull, isHigherPt);
    std::vector<const RecoHadTau*> selHadTaus = selectObjects(hadTauSelection, preselHadTaus, fakeableHadTaus, tightHadTaus);
    if(isDEBUG || run_lumi_eventSelector)
    {
      printCollection("preselHadTaus",   preselHadTaus);
      printCollection("fakeableHadTaus", fakeableHadTaus);
      printCollection("tightHadTaus",    tightHadTaus);
      printCollection("selHadTaus",      selHadTaus);
    }

//--- build collections of jets and select subset of jets passing b-tagging criteria
    std::vector<RecoJet> jets = jetReader->read();
    std::vector<const RecoJet*> jet_ptrs = convert_to_ptrs(jets);
    std::vector<const RecoJet*> cleanedJets = jetCleaner(jet_ptrs, fakeableHadTaus);
    std::vector<const RecoJet*> selJets = jetSelector(cleanedJets, isHigherPt);
    std::vector<const RecoJet*> selBJets_loose = jetSelectorBtagLoose(cleanedJets, isHigherPt);
    std::vector<const RecoJet*> selBJets_medium = jetSelectorBtagMedium(cleanedJets, isHigherPt);
    if(isDEBUG || run_lumi_eventSelector)
    {
      printCollection("uncleanedJets", jet_ptrs);
      printCollection("selJets",       selJets);
    }

//--- build collections of jets reconstructed by hep-top-tagger (HTTv2) algorithm
    std::vector<RecoJetHTTv2> jetsHTTv2 = jetReaderHTTv2->read();
    std::vector<const RecoJetHTTv2*> jet_ptrsHTTv2raw = convert_to_ptrs(jetsHTTv2);
    std::vector<const RecoJetHTTv2*> jet_ptrsHTTv2rawSel = jetSelectorHTTv2(jet_ptrsHTTv2raw, isHigherPt);
    std::vector<const RecoJetHTTv2*> sel_HTTv2 = jetCleanerHTTv2SubJets(jet_ptrsHTTv2rawSel, fakeableMuons, fakeableElectrons, selHadTaus);

//--- build collections of jets reconstructed by anti-kT algorithm with dR=0.8 (AK8)
    std::vector<RecoJetAK8> jetsAK8 = jetReaderAK8->read();
    std::vector<const RecoJetAK8*> jet_ptrsAK8raw1 = convert_to_ptrs(jetsAK8);
    std::vector<const RecoJetAK8*> jet_ptrsAK8raw = jetSelectorAK8(jet_ptrsAK8raw1, isHigherPt);;
    std::vector<const RecoJetAK8*> jet_ptrsAK8 = jetCleanerAK8SubJets(jet_ptrsAK8raw, fakeableMuons, fakeableElectrons, selHadTaus);
    std::vector<const RecoJet*> cleanedJets_fromAK8;
    cleanedJets_fromAK8 = jetCleaner_large8(selJets, jet_ptrsAK8);

//--- build collections of generator level particles (after some cuts are applied, to safe computing time)
    if ( isMC && redoGenMatching && !fillGenEvtHistograms ) {
      if ( genLeptonReader ) {
        genLeptons = genLeptonReader->read();
        for ( std::vector<GenLepton>::const_iterator genLepton = genLeptons.begin();
              genLepton != genLeptons.end(); ++genLepton ) {
          int abs_pdgId = std::abs(genLepton->pdgId());
          if      ( abs_pdgId == 11 ) genElectrons.push_back(*genLepton);
          else if ( abs_pdgId == 13 ) genMuons.push_back(*genLepton);
        }
      }
      if ( genHadTauReader ) {
        genHadTaus = genHadTauReader->read();
      }
      if ( genPhotonReader ) {
        genPhotons = genPhotonReader->read();
      }
      if ( genJetReader ) {
        genJets = genJetReader->read();
      }
    }

//--- match reconstructed to generator level particles
    if ( isMC && redoGenMatching ) {
      muonGenMatcher.addGenLeptonMatch(preselMuons, genLeptons, 0.2);
      muonGenMatcher.addGenHadTauMatch(preselMuons, genHadTaus, 0.2);
      muonGenMatcher.addGenJetMatch(preselMuons, genJets, 0.2);

      electronGenMatcher.addGenLeptonMatch(preselElectrons, genLeptons, 0.2);
      electronGenMatcher.addGenHadTauMatch(preselElectrons, genHadTaus, 0.2);
      electronGenMatcher.addGenPhotonMatch(preselElectrons, genPhotons, 0.2);
      electronGenMatcher.addGenJetMatch(preselElectrons, genJets, 0.2);

      hadTauGenMatcher.addGenLeptonMatch(preselHadTaus, genLeptons, 0.2);
      hadTauGenMatcher.addGenHadTauMatch(preselHadTaus, genHadTaus, 0.2);
      hadTauGenMatcher.addGenJetMatch(preselHadTaus, genJets, 0.2);

      jetGenMatcher.addGenLeptonMatch(selJets, genLeptons, 0.2);
      jetGenMatcher.addGenHadTauMatch(selJets, genHadTaus, 0.2);
      jetGenMatcher.addGenJetMatch(selJets, genJets, 0.2);
    }

//--- apply preselection
    // require presence of at least two hadronic taus passing loose preselection criteria
    // (do not veto events with more than two loosely selected hadronic tau candidates,
    //  as sample of hadronic tau candidates passing loose preselection criteria contains significant contamination from jets)
    if ( !(preselHadTaus.size() >= 2) ) continue;
    cutFlowTable.update(">= 2 presel taus");
    cutFlowHistManager->fillHistograms(">= 2 presel taus", lumiScale);
    const RecoHadTau* preselHadTau_lead = preselHadTaus[0];
    const RecoHadTau* preselHadTau_sublead = preselHadTaus[1];
    const hadTauGenMatchEntry& preselHadTau_genMatch = getHadTauGenMatch(hadTauGenMatch_definitions, preselHadTau_lead, preselHadTau_sublead);
    int idxPreselHadTau_genMatch = preselHadTau_genMatch.idx_;
    assert(idxPreselHadTau_genMatch != kGen_HadTauUndefined2);

    // apply requirement on jets (incl. b-tagged jets) on preselection level
    if ( !(selJets.size() >= 2) ) continue;
    cutFlowTable.update(">= 2 jets");
    cutFlowHistManager->fillHistograms(">= 2 jets", lumiScale);
    if ( !(selBJets_loose.size() >= 2 || selBJets_medium.size() >= 1) ) continue;
    cutFlowTable.update(">= 2 loose b-jets || 1 medium b-jet (1)");
    cutFlowHistManager->fillHistograms(">= 2 loose b-jets || 1 medium b-jet (1)", lumiScale);

//--- compute MHT and linear MET discriminant (met_LD)
    RecoMEt met = metReader->read();
    Particle::LorentzVector mht_p4 = compMHT({}, fakeableHadTaus, selJets);
    double met_LD = compMEt_LD(met.p4(), mht_p4);

//--- apply final event selection
    // require presence of exactly two hadronic taus passing tight selection criteria of final event selection
    if ( !(selHadTaus.size() >= 2) ) continue;
    cutFlowTable.update(">= 2 sel taus", lumiScale);
    cutFlowHistManager->fillHistograms(">= 2 sel taus", lumiScale);
    const RecoHadTau* selHadTau_lead = selHadTaus[0];
    const RecoHadTau* selHadTau_sublead = selHadTaus[1];
    const hadTauGenMatchEntry& selHadTau_genMatch = getHadTauGenMatch(hadTauGenMatch_definitions, selHadTau_lead, selHadTau_sublead);
    int idxSelHadTau_genMatch = selHadTau_genMatch.idx_;
    assert(idxSelHadTau_genMatch != kGen_HadTauUndefined2);

//--- compute event-level weight for data/MC correction of b-tagging efficiency and mistag rate
//   (using the method "Event reweighting using scale factors calculated with a tag and probe method",
//    described on the BTV POG twiki https://twiki.cern.ch/twiki/bin/view/CMS/BTagShapeCalibration )
    double evtWeight = 1.;
    double btagWeight = 1.;
    if ( isMC ) {
      if ( apply_DYMCNormScaleFactors ) evtWeight_inclusive *= dyNormScaleFactors->getWeight(genTauLeptons, selJets.size(), selBJets_loose.size(), selBJets_medium.size());
      evtWeight *= evtWeight_inclusive;
      btagWeight = get_BtagWeight(selJets);
      evtWeight *= btagWeight;
      if ( isDEBUG ) {
        std::cout << "lumiScale = " << lumiScale << std::endl;
        if ( apply_genWeight ) std::cout << "genWeight = " << boost::math::sign(eventInfo.genWeight) << std::endl;
        std::cout << "pileupWeight = " << eventInfo.pileupWeight << std::endl;
        std::cout << "btagWeight = " << btagWeight << std::endl;
      }
    }

    double weight_data_to_MC_correction = 1.;
    double triggerWeight = 1.;
    double weight_hadTauEff = 1.;
    double tauSF_weight = 1.;
    if ( isMC ) {
      int selHadTau_lead_genPdgId = getHadTau_genPdgId(selHadTau_lead);
      int selHadTau_sublead_genPdgId = getHadTau_genPdgId(selHadTau_sublead);

      dataToMCcorrectionInterface->setHadTaus(
        selHadTau_lead_genPdgId, selHadTau_lead->pt(), selHadTau_lead->eta(),
        selHadTau_sublead_genPdgId, selHadTau_sublead->pt(), selHadTau_sublead->eta());

      if(era == kEra_2016)
      {
        dataToMCcorrectionInterface_0l_2tau_trigger->setHadTaus(
          selHadTau_lead_genPdgId,    selHadTau_lead->pt(),    selHadTau_lead->eta(),    selHadTau_lead->decayMode(),
          selHadTau_sublead_genPdgId, selHadTau_sublead->pt(), selHadTau_sublead->eta(), selHadTau_sublead->decayMode()
        );
      }
      else if(era == kEra_2017)
      {
        dataToMCcorrectionInterface_0l_2tau_trigger->setHadTaus(
          selHadTau_lead->pt(),    selHadTau_lead->eta(),    selHadTau_lead->phi(),
          selHadTau_sublead->pt(), selHadTau_sublead->eta(), selHadTau_sublead->phi()
        );
      }
      else if(era == kEra_2018)
      {
        throw cmsException("analyze_0l_2tau", __LINE__) << "Invalid era = " << era;
      }
      dataToMCcorrectionInterface_0l_2tau_trigger->setTriggerBits(isTriggered_2tau);

//--- apply data/MC corrections for trigger efficiency
      double sf_triggerEff = dataToMCcorrectionInterface_0l_2tau_trigger->getSF_triggerEff();
      if ( isDEBUG ) {
        std::cout << "sf_triggerEff = " << sf_triggerEff << std::endl;
      }
      triggerWeight *= sf_triggerEff;
      weight_data_to_MC_correction *= sf_triggerEff;

//--- apply data/MC corrections for hadronic tau identification efficiency
//    and for e->tau and mu->tau misidentification rates
      double sf_hadTauEff = 1.;
      sf_hadTauEff *= dataToMCcorrectionInterface->getSF_hadTauID_and_Iso();
      sf_hadTauEff *= dataToMCcorrectionInterface->getSF_eToTauFakeRate();
      sf_hadTauEff *= dataToMCcorrectionInterface->getSF_muToTauFakeRate();
      if ( isDEBUG ) {
        std::cout << "sf_hadTauEff = " << sf_hadTauEff << std::endl;
      }
      weight_hadTauEff *= sf_hadTauEff;
      tauSF_weight *= weight_hadTauEff;
      weight_data_to_MC_correction *= sf_hadTauEff;
      if ( isDEBUG ) {
        std::cout << "weight_data_to_MC_correction = " << weight_data_to_MC_correction << std::endl;
      }
      evtWeight *= weight_data_to_MC_correction;
    }

    // veto events that contain leptons passing tight selection criteria, to avoid overlap with other channels
    if ( !(tightLeptons.size() <= 0) ) {
      if ( run_lumi_eventSelector ) {
        std::cout << "event " << eventInfo.str() << " FAILS tightLeptons selection." << std::endl;
        printCollection("tightLeptons", tightLeptons);
      }
      continue;
    }
    cutFlowTable.update("no tight leptons", evtWeight);
    cutFlowHistManager->fillHistograms("no tight leptons", evtWeight);

//--- apply HLT filter
    if(apply_hlt_filter)
    {
      if(! hltFilter({{ hltPathsE::trigger_2tau, selTrigger_2tau }}, {}, fakeableHadTaus))
      {
        if(run_lumi_eventSelector || isDEBUG)
        {
          std::cout << "event " << eventInfo.str() << " FAILS HLT filter matching\n";
        }
        continue;
      }
    }
    cutFlowTable.update("HLT filter matching", evtWeight);
    cutFlowHistManager->fillHistograms("HLT filter matching", evtWeight);

    double weight_fakeRate = 1.;
    if ( applyFakeRateWeights == kFR_2tau) {
      double prob_fake_hadTau_lead = jetToTauFakeRateInterface->getWeight_lead(selHadTau_lead->pt(), selHadTau_lead->absEta());
      bool passesTight_hadTau_lead = isMatched(*selHadTau_lead, tightHadTausFull);
      double prob_fake_hadTau_sublead = jetToTauFakeRateInterface->getWeight_sublead(selHadTau_sublead->pt(), selHadTau_sublead->absEta());
      bool passesTight_hadTau_sublead = isMatched(*selHadTau_sublead, tightHadTausFull);

      weight_fakeRate = getWeight_2L(
        prob_fake_hadTau_lead, passesTight_hadTau_lead,
        prob_fake_hadTau_sublead, passesTight_hadTau_sublead
      );

      if ( isDEBUG ) {
        std::cout << "weight_fakeRate = " << weight_fakeRate << std::endl;
      }
      evtWeight *= weight_fakeRate;
    }
    if ( isDEBUG ) {
      std::cout << "evtWeight = " << evtWeight << std::endl;
    }

    double mTauTauVis = (selHadTau_lead->p4() + selHadTau_sublead->p4()).mass();

    // apply requirement on jets (incl. b-tagged jets) on level of final event selection
    if ( !(selJets.size() >= 4) ) continue;
    cutFlowTable.update(">= 4 jets", evtWeight);
    cutFlowHistManager->fillHistograms(">= 4 jets", evtWeight);
    if ( !(selBJets_loose.size() >= 2 || selBJets_medium.size() >= 1) ) continue;
    cutFlowTable.update(">= 2 loose b-jets || 1 medium b-jet (2)", evtWeight);
    cutFlowHistManager->fillHistograms(">= 2 loose b-jets || 1 medium b-jet (2)", evtWeight);

    bool failsLowMassVeto = false;
    for ( std::vector<const RecoLepton*>::const_iterator lepton1 = preselLeptons.begin();
      lepton1 != preselLeptons.end(); ++lepton1 ) {
      for ( std::vector<const RecoLepton*>::const_iterator lepton2 = lepton1 + 1;
        lepton2 != preselLeptons.end(); ++lepton2 ) {
        double mass = ((*lepton1)->p4() + (*lepton2)->p4()).mass();
        if ( mass < 12. ) {
          failsLowMassVeto = true;
        }
      }
    }
    if ( failsLowMassVeto ) {
      if ( run_lumi_eventSelector ) {
        std::cout << "event " << eventInfo.str() << " FAILS low mass lepton pair veto." << std::endl;
      }
      continue;
    }
    cutFlowTable.update("m(ll) > 12 GeV", evtWeight);
    cutFlowHistManager->fillHistograms("m(ll) > 12 GeV", evtWeight);

    if ( !(selHadTau_lead->pt() > minPt_hadTau_lead && selHadTau_lead->absEta() < 2.1) ) continue;
    cutFlowTable.update(Form("lead hadTau pT > %.0f GeV && abs(eta) < 2.1", minPt_hadTau_lead), evtWeight);
    cutFlowHistManager->fillHistograms(Form("lead hadTau pT > %.0f GeV && abs(eta) < 2.1", minPt_hadTau_lead), evtWeight);

    if ( !(selHadTau_sublead->pt() > minPt_hadTau_sublead && selHadTau_sublead->absEta() < 2.1) ) continue;
    cutFlowTable.update(Form("sublead hadTau pT > %.0f GeV && abs(eta) < 2.1", minPt_hadTau_sublead), evtWeight);
    cutFlowHistManager->fillHistograms(Form("sublead hadTau pT > %.0f GeV && abs(eta) < 2.1", minPt_hadTau_sublead), evtWeight);

    bool isCharge_SS = selHadTau_lead->charge()*selHadTau_sublead->charge() > 0;
    bool isCharge_OS = selHadTau_lead->charge()*selHadTau_sublead->charge() < 0;
    if ( hadTauChargeSelection == kOS && isCharge_SS )
    {
      if(run_lumi_eventSelector || isDEBUG)
      {
        std::cout << "event " << eventInfo.str() << " FAILS OS tau-pair selection\n";
      }
      continue;
    }
    if ( hadTauChargeSelection == kSS && isCharge_OS )
    {
      if(run_lumi_eventSelector || isDEBUG)
      {
        std::cout << "event " << eventInfo.str() << " FAILS SS tau-pair selection\n";
      }
      continue;
    }
    cutFlowTable.update(Form("tau-pair %s charge", hadTauChargeSelection_string.data()), evtWeight);
    cutFlowHistManager->fillHistograms("tau-pair OS/SS charge", evtWeight);

    if ( apply_met_filters ) {
      if ( !metFilterSelector(metFilters) ) {
        if ( run_lumi_eventSelector ) {
          std::cout << "event " << eventInfo.str() << " FAILS MEt filters." << std::endl;
        }
        continue;
      }
    }
    cutFlowTable.update("MEt filters", evtWeight);
    cutFlowHistManager->fillHistograms("MEt filters", evtWeight);

    bool failsSignalRegionVeto = false;
    if ( isMCClosure_t ) {
      bool applySignalRegionVeto = isMCClosure_t && countFakeHadTaus(selHadTaus) >= 1;
      if ( applySignalRegionVeto && tightHadTaus.size() >= 2 ) failsSignalRegionVeto = true;
    } else if ( hadTauSelection == kFakeable ) {
      if ( tightHadTaus.size() >= 2 ) failsSignalRegionVeto = true;
    }
    if ( failsSignalRegionVeto ) {
      if ( run_lumi_eventSelector ) {
        std::cout << "event " << eventInfo.str() << " FAILS overlap w/ the SR: "
                     "# tight taus = " << tightHadTaus.size() << " >= 2\n"
        ;
        printCollection("tightHadTaus", tightHadTaus);
      }
      continue; // CV: avoid overlap with signal region
    }
    cutFlowTable.update("signal region veto", evtWeight);
    cutFlowHistManager->fillHistograms("signal region veto", evtWeight);

    //--- compute output of hadronic top tagger BDT
    // it returns the gen-triplets organized in top/anti-top
    bool calculate_matching = isMC && selectBDT && !applyAdditionalEvtWeight; // DY has not matching info
    std::map<int, Particle::LorentzVector> genVar;
    std::map<int, Particle::LorentzVector> genVarAnti;
    if (calculate_matching) {
      genVar = isGenMatchedJetTripletVar(genTopQuarks, genBJets, genWBosons, genQuarkFromTop, kGenTop);
      genVarAnti = isGenMatchedJetTripletVar(genTopQuarks, genBJets, genWBosons, genQuarkFromTop, kGenAntiTop);
    }

    // resolved HTT

    double max_mvaOutput_HTT_CSVsort4rd = 0.;
    bool max_truth_HTT_CSVsort4rd = false;
    double HadTop_pt_CSVsort4rd = 0.;
    double HadTop_eta_CSVsort4rd = 0.;
    double genTopPt_CSVsort4rd = 0.;
    double b_pt_1 = 0.1;
    double Wj1_pt_1 = 0.1;
    double Wj2_pt_1 = 0.1;
    double max_mvaOutput_HTT_CSVsort4rd_2 = 0.;
    bool max_truth_HTT_CSVsort4rd_2 = false;
    double HadTop_pt_CSVsort4rd_2 = 0.;
    double genTopPt_CSVsort4rd_2 = 0.;

    bool hadtruth = false;
    bool hadtruth_2 = false;
    for ( std::vector<const RecoJet*>::const_iterator selBJet = selJets.begin(); selBJet != selJets.end(); ++selBJet ) {
      //btag_iterator++;
      for ( std::vector<const RecoJet*>::const_iterator selWJet1 = selJets.begin(); selWJet1 != selJets.end(); ++selWJet1 ) {
       if ( &(*selWJet1) == &(*selBJet) ) continue;
       for ( std::vector<const RecoJet*>::const_iterator selWJet2 = selWJet1 + 1; selWJet2 != selJets.end(); ++selWJet2 ) {
    if ( &(*selWJet2) == &(*selBJet) ) continue;
    if ( &(*selWJet2) == &(*selWJet1) ) continue;
    bool isGenMatched = false;
    double genTopPt_teste = 0.;
    const std::map<int, double> bdtResult = (*hadTopTagger)(**selBJet, **selWJet1, **selWJet2, calculate_matching, isGenMatched, genTopPt_teste, genVar, genVarAnti );
    // genTopPt_teste is filled with the result of gen-matching
    if ( isGenMatched ) hadtruth = true;
    // save genpt of all options
    double HadTop_pt = ((*selBJet)->p4() + (*selWJet1)->p4() + (*selWJet2)->p4()).pt();

    if ( bdtResult.at(kXGB_CSVsort4rd) > max_mvaOutput_HTT_CSVsort4rd ) {
      max_truth_HTT_CSVsort4rd = isGenMatched;
      max_mvaOutput_HTT_CSVsort4rd = bdtResult.at(kXGB_CSVsort4rd);
      HadTop_pt_CSVsort4rd = HadTop_pt;
      genTopPt_CSVsort4rd = genTopPt_teste;
      HadTop_eta_CSVsort4rd = std::fabs(((*selBJet)->p4() + (*selWJet1)->p4() + (*selWJet2)->p4()).eta());
      Wj1_pt_1 = (*selWJet1)->pt();
      Wj2_pt_1 = (*selWJet2)->pt();
      b_pt_1   = (*selBJet)->pt();
    }

    }
      }
    }
    ///--- the second res-HTT
    if ( selJets.size() > 5 ){
    for ( std::vector<const RecoJet*>::const_iterator selBJet = selJets.begin(); selBJet != selJets.end(); ++selBJet ) {
      if (b_pt_1 == (*selBJet)->pt() || Wj1_pt_1 == (*selBJet)->pt() || Wj2_pt_1 == (*selBJet)->pt()) continue;
      for ( std::vector<const RecoJet*>::const_iterator selWJet1 = selJets.begin(); selWJet1 != selJets.end(); ++selWJet1 ) {
       if ( &(*selWJet1) == &(*selBJet) ) continue;
       if (b_pt_1 == (*selWJet1)->pt() || Wj1_pt_1 == (*selWJet1)->pt() || Wj2_pt_1 == (*selWJet1)->pt()) continue;
       for ( std::vector<const RecoJet*>::const_iterator selWJet2 = selWJet1 + 1; selWJet2 != selJets.end(); ++selWJet2 ) {
    if (b_pt_1 == (*selWJet2)->pt() || Wj1_pt_1 == (*selWJet2)->pt() || Wj2_pt_1 == (*selWJet2)->pt()) continue;
    if ( &(*selWJet2) == &(*selBJet) ) continue;
    if ( &(*selWJet2) == &(*selWJet1) ) continue;
    bool isGenMatched = false;
    double genTopPt_teste = 0.;
    const std::map<int, double> bdtResult = (*hadTopTagger)(**selBJet, **selWJet1, **selWJet2, calculate_matching, isGenMatched, genTopPt_teste, genVar, genVarAnti );
    // genTopPt_teste is filled with the result of gen-matching
    if ( isGenMatched ) hadtruth_2 = true;
    // save genpt of all options
    double HadTop_pt = ((*selBJet)->p4() + (*selWJet1)->p4() + (*selWJet2)->p4()).pt();

    if ( bdtResult.at(kXGB_CSVsort4rd) > max_mvaOutput_HTT_CSVsort4rd_2 ) {
      max_truth_HTT_CSVsort4rd_2 = isGenMatched;
      max_mvaOutput_HTT_CSVsort4rd_2 = bdtResult.at(kXGB_CSVsort4rd);
      HadTop_pt_CSVsort4rd_2 = HadTop_pt;
      genTopPt_CSVsort4rd_2 = genTopPt_teste;
    }
    }
        }
      } // close loop on jetS
    } // close if 6 jets
    //std::cout<< max_mvaOutput_HTT_CSVsort4rd_2 << " " << max_mvaOutput_HTT_CSVsort4rd << std::endl;

    // compute overlaps semi-boosted resolved / semi-boosted and boosted / ...
    bool resolved_and_semi_AK8 = false;
    bool boosted_and_semi_AK8 = false;
    bool resolved_and_boosted = false;

    //--- boosted hTT
    double HTT_boosted = 0.;
    bool bWj1Wj2_isGenMatched_boosted = false;
    double genTopPt_boosted = 0.;
    double HadTop_pt_boosted = 0.;
    bool hadtruth_boosted = false;
    double minDR_HTTv2_lep = -1.;
    double minDR_HTTv2subjets_lep = -1.;

    for ( std::vector<const RecoJetHTTv2*>::const_iterator jetIter = sel_HTTv2.begin();
    jetIter != sel_HTTv2.end(); ++jetIter ) {
    bool isGenMatched = false;
    double genTopPt_teste = 0.;
    const std::map<int, double> bdtResult = (*hadTopTagger_boosted)(**jetIter, calculate_matching, isGenMatched, genTopPt_teste, genVar, genVarAnti);
    if (isGenMatched) {hadtruth_boosted = true;}

    if ( bdtResult.at(kXGB_boosted_no_kinFit) > HTT_boosted ) {
      bWj1Wj2_isGenMatched_boosted = isGenMatched;
      HTT_boosted = bdtResult.at(kXGB_boosted_no_kinFit);
      HadTop_pt_boosted = (*jetIter)->pt();
      genTopPt_boosted = genTopPt_teste;

      minDR_HTTv2_lep = std::min(
        deltaR(selHadTau_lead->p4(), (*jetIter)->p4()),
        deltaR(selHadTau_sublead->p4(), (*jetIter)->p4())
      );

      minDR_HTTv2subjets_lep =
      std::min(
      std::min(
      std::min(
        deltaR(selHadTau_lead->p4(), (*jetIter)->subJet1()->p4()),
        deltaR(selHadTau_sublead->p4(), (*jetIter)->subJet1()->p4())
      ),
      std::min(
        deltaR(selHadTau_lead->p4(), (*jetIter)->subJet2()->p4()),
        deltaR(selHadTau_sublead->p4(), (*jetIter)->subJet2()->p4())
      )
     ),
     std::min(
       deltaR(selHadTau_lead->p4(), (*jetIter)->subJet3()->p4()),
       deltaR(selHadTau_sublead->p4(), (*jetIter)->subJet3()->p4())
     )
     );

    }
    }
    if (genTopPt_CSVsort4rd == genTopPt_boosted) resolved_and_boosted = true;

    // -- semi-boosted hTT -- AK8
    double HTT_semi_boosted_fromAK8 = 0.;
    bool bWj1Wj2_isGenMatched_semi_boosted_fromAK8 = false;
    double genTopPt_semi_boosted_fromAK8 = 0.;
    double HadTop_pt_semi_boosted_fromAK8 = 0.;
    bool hadtruth_semi_boosted_fromAK8 = false;
    double minDR_AK8_lep = -1.;
    double minDR_AK8subjets_lep = -1.;
    for ( std::vector<const RecoJet*>::const_iterator selBJet = cleanedJets_fromAK8.begin(); selBJet != cleanedJets_fromAK8.end(); ++selBJet )  {
    for ( std::vector<const RecoJetAK8*>::const_iterator jetIter = jet_ptrsAK8.begin();
          jetIter != jet_ptrsAK8.end(); ++jetIter ) {

        bool isGenMatched = false;
        double genTopPt_teste = 0.;
        double HadTop_pt = ((*jetIter)->p4() + (*selBJet)->p4()).pt();
        const std::map<int, double> bdtResult = (*hadTopTagger_semi_boosted_fromAK8)(**jetIter, **selBJet, calculate_matching, isGenMatched, genTopPt_teste, genVar, genVarAnti);
        if (isGenMatched) {hadtruth_semi_boosted_fromAK8 = true;}

        if ( bdtResult.at(kXGB_semi_boosted_AK8_no_kinFit) > HTT_semi_boosted_fromAK8 ) {
          bWj1Wj2_isGenMatched_semi_boosted_fromAK8 = isGenMatched;
          HTT_semi_boosted_fromAK8 = bdtResult.at(kXGB_semi_boosted_AK8_no_kinFit);
          HadTop_pt_semi_boosted_fromAK8 = HadTop_pt;
          genTopPt_semi_boosted_fromAK8 = genTopPt_teste;
          minDR_AK8_lep = std::min(
            deltaR(selHadTau_lead->p4(), (*jetIter)->p4()),
            deltaR(selHadTau_sublead->p4(), (*jetIter)->p4())
          );

          minDR_AK8subjets_lep =
          std::min(
          std::min(
            deltaR(selHadTau_lead->p4(), (*jetIter)->subJet1()->p4()),
            deltaR(selHadTau_sublead->p4(), (*jetIter)->subJet1()->p4())
          ),
          std::min(
            deltaR(selHadTau_lead->p4(), (*jetIter)->subJet2()->p4()),
            deltaR(selHadTau_sublead->p4(), (*jetIter)->subJet2()->p4())
          )
         );
        }

      }
    }
    if (genTopPt_CSVsort4rd == genTopPt_semi_boosted_fromAK8)  resolved_and_semi_AK8 = true;
    if (genTopPt_semi_boosted_fromAK8 == genTopPt_boosted)  boosted_and_semi_AK8 = true;

//--- reconstruct mass of tau-pair using SVfit algorithm
//
//    NOTE: SVfit needs to be run after all event selection cuts are applied,
//          because the algorithm takes O(1 second per event) to run
//
    std::vector<classic_svFit::MeasuredTauLepton> measuredTauLeptons;
    classic_svFit::MeasuredTauLepton::kDecayType leg1Type = classic_svFit::MeasuredTauLepton::kTauToHadDecay;
    double leg1Mass = selHadTau_lead->mass();
    if ( leg1Mass < classic_svFit::chargedPionMass ) leg1Mass = classic_svFit::chargedPionMass;
    if ( leg1Mass > 1.5                            ) leg1Mass = 1.5;
    classic_svFit::MeasuredTauLepton::kDecayType leg2Type = classic_svFit::MeasuredTauLepton::kTauToHadDecay;
    double leg2Mass = selHadTau_sublead->mass();
    if ( leg2Mass < classic_svFit::chargedPionMass ) leg2Mass = classic_svFit::chargedPionMass;
    if ( leg2Mass > 1.5                            ) leg2Mass = 1.5;
    measuredTauLeptons.push_back(classic_svFit::MeasuredTauLepton(leg1Type, selHadTau_lead->pt(), selHadTau_lead->eta(), selHadTau_lead->phi(), leg1Mass));
    measuredTauLeptons.push_back(classic_svFit::MeasuredTauLepton(leg2Type, selHadTau_sublead->pt(), selHadTau_sublead->eta(), selHadTau_sublead->phi(), leg2Mass));
    ClassicSVfit svFitAlgo;
    svFitAlgo.addLogM_dynamic(false);
    svFitAlgo.addLogM_fixed(true, 5.);
    svFitAlgo.integrate(measuredTauLeptons, met.p4().px(), met.p4().py(), met.cov());
    //double mTauTau = -1.; // CV: temporarily comment-out the following line, to make code compile with "old" and "new" version of ClassicSVfit
    double mTauTau   = ( svFitAlgo.isValidSolution() ) ? static_cast<classic_svFit::HistogramAdapterDiTau*>(svFitAlgo.getHistogramAdapter())->getMass() : -1.;
    double mT_tau1   = comp_MT_met_hadTau1(*selHadTau_lead, met.pt(), met.phi());
    double mT_tau2   = comp_MT_met_hadTau2(*selHadTau_sublead, met.pt(), met.phi());
    double pZeta     = comp_pZeta(selHadTau_lead -> p4(), selHadTau_sublead -> p4(), met.p4().px(), met.p4().py());
    double pZetaVis  = comp_pZetaVis(selHadTau_lead -> p4(), selHadTau_sublead -> p4());
    double pZetaComb = comp_pZetaComb(selHadTau_lead -> p4(), selHadTau_sublead -> p4(), met.p4().px(), met.p4().py());

    //compute di-b-jet mass
    const double mbb             = selBJets_medium.size() > 1 ? (selBJets_medium[0]->p4() + selBJets_medium[1]->p4()).mass() : -1.;
    const double mbb_loose       = selBJets_loose.size() > 1 ? (selBJets_loose[0]->p4() + selBJets_loose[1]->p4()).mass() : -1.;
//--- compute output of BDTs used to discriminate ttH vs. ttbar trained by Arun for 1l_2tau category
    mvaInputs_ttbar["nJet"]                 = selJets.size();
    mvaInputs_ttbar["nBJetLoose"]           = selBJets_loose.size();
    mvaInputs_ttbar["nBJetMedium"]          = selBJets_medium.size();
    mvaInputs_ttbar["mindr_tau1_jet"]       = TMath::Min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets));
    mvaInputs_ttbar["mindr_tau2_jet"]       = TMath::Min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets));
    mvaInputs_ttbar["avg_dr_jet"]           = comp_avg_dr_jet(selJets);
    mvaInputs_ttbar["ptmiss"]               = met.pt();
    mvaInputs_ttbar["mT_tau1"]              = comp_MT_met_hadTau1(*selHadTau_lead, met.pt(), met.phi());
    mvaInputs_ttbar["mT_tau2"]              = comp_MT_met_hadTau2(*selHadTau_sublead, met.pt(), met.phi());
    mvaInputs_ttbar["htmiss"]               = mht_p4.pt();
    mvaInputs_ttbar["tau1_pt"]              = selHadTau_lead->pt();
    mvaInputs_ttbar["tau2_pt"]              = selHadTau_sublead->pt();
    mvaInputs_ttbar["TMath::Abs(tau1_eta)"] = selHadTau_lead->absEta();
    mvaInputs_ttbar["TMath::Abs(tau2_eta)"] = selHadTau_sublead->absEta();
    mvaInputs_ttbar["dr_taus"]              = deltaR(selHadTau_lead->p4(), selHadTau_sublead->p4());
    mvaInputs_ttbar["mTauTauVis"]           = mTauTauVis;
    mvaInputs_ttbar["mTauTau"]              = mTauTau;

    check_mvaInputs(mvaInputs_ttbar, eventInfo);

    double mvaOutput_0l_2tau_ttbar = mva_0l_2tau_ttbar(mvaInputs_ttbar);

    //--- compute output of BDTs used to discriminate ttH vs. ttbar and ttV training using XGB
    xgbInputs_ttbar["mindr_tau1_jet"]       = TMath::Min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets));
    xgbInputs_ttbar["mindr_tau2_jet"]       = TMath::Min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets));
    xgbInputs_ttbar["avg_dr_jet"]           = comp_avg_dr_jet(selJets);
    xgbInputs_ttbar["ptmiss"]               = met.pt();
    xgbInputs_ttbar["htmiss"]               = mht_p4.pt();
    xgbInputs_ttbar["tau1_pt"]              = selHadTau_lead->pt();
    xgbInputs_ttbar["tau2_pt"]              = selHadTau_sublead->pt();
    xgbInputs_ttbar["tau1_eta"]             = selHadTau_lead->absEta();
    xgbInputs_ttbar["tau2_eta"]             = selHadTau_sublead->absEta();
    xgbInputs_ttbar["dr_taus"]              = deltaR(selHadTau_lead->p4(), selHadTau_sublead->p4());
    xgbInputs_ttbar["mT_tau1"]              = comp_MT_met_hadTau1(*selHadTau_lead, met.pt(), met.phi());
    xgbInputs_ttbar["mT_tau2"]              = comp_MT_met_hadTau2(*selHadTau_sublead, met.pt(), met.phi());
    xgbInputs_ttbar["mTauTauVis"]           = mTauTauVis;
    xgbInputs_ttbar["mTauTau"]           = mTauTau;
    xgbInputs_ttbar["HTT_wKinFit_top1"]     = max_mvaOutput_HTT_CSVsort4rd;
    xgbInputs_ttbar["HadTop1_pt"]           = HadTop_pt_CSVsort4rd;
    xgbInputs_ttbar["HadTop1_eta"]          = std::fabs(HadTop_eta_CSVsort4rd);
    xgbInputs_ttbar["HTT_wKinFit_top2"]     = max_mvaOutput_HTT_CSVsort4rd_2;
    xgbInputs_ttbar["HadTop2_pt"]           = HadTop_pt_CSVsort4rd;
    xgbInputs_ttbar["nJet"]                 = selJets.size();
    double mvaOutput_0l_2tau_HTT_tt = xgb_0l_2tau_ttbar(xgbInputs_ttbar);
    double mvaOutput_0l_2tau_HTT_sum = xgb_0l_2tau_sum(xgbInputs_ttbar);

    xgbInputs_ttv["mindr_tau1_jet"]       = TMath::Min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets));
    xgbInputs_ttv["mindr_tau2_jet"]       = TMath::Min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets));
    xgbInputs_ttv["avg_dr_jet"]           = comp_avg_dr_jet(selJets);
    xgbInputs_ttv["ptmiss"]               = met.pt();
    xgbInputs_ttv["htmiss"]               = mht_p4.pt();
    xgbInputs_ttv["tau1_pt"]              = selHadTau_lead->pt();
    xgbInputs_ttv["tau2_pt"]              = selHadTau_sublead->pt();
    xgbInputs_ttv["tau1_eta"]             = selHadTau_lead->absEta();
    xgbInputs_ttv["tau2_eta"]             = selHadTau_sublead->absEta();
    xgbInputs_ttv["dr_taus"]              = deltaR(selHadTau_lead->p4(), selHadTau_sublead->p4());
    xgbInputs_ttv["mT_tau1"]              = comp_MT_met_hadTau1(*selHadTau_lead, met.pt(), met.phi());
    xgbInputs_ttv["mT_tau2"]              = comp_MT_met_hadTau2(*selHadTau_sublead, met.pt(), met.phi());
    xgbInputs_ttv["mTauTauVis"]           = mTauTauVis;
    xgbInputs_ttv["mTauTau"]           = mTauTau;
    xgbInputs_ttv["HTT_wKinFit_top1"]     = max_mvaOutput_HTT_CSVsort4rd;
    xgbInputs_ttv["HTT_wKinFit_top2"]     = max_mvaOutput_HTT_CSVsort4rd_2;
    xgbInputs_ttv["nJet"]                 = selJets.size();
    double mvaOutput_0l_2tau_HTT_ttv = xgb_0l_2tau_ttv(xgbInputs_ttv);

    //Get 2D map values
    int ibin = hTargetBinning->FindBin(mvaOutput_0l_2tau_HTT_tt, mvaOutput_0l_2tau_HTT_ttv);
    float mvaDiscr_0l_2tau_HTT = hTargetBinning->GetBinContent(ibin);

    //--- compute output of BDTs used to discriminate ttH vs. ttbar+ttV+DY training using XGB
    xgbInputs_dy["mindr_tau1_jet"]       = TMath::Min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets));
    xgbInputs_dy["mindr_tau2_jet"]       = TMath::Min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets));
    xgbInputs_dy["avg_dr_jet"]           = comp_avg_dr_jet(selJets);
    xgbInputs_dy["ptmiss"]               = met.pt();
    xgbInputs_dy["htmiss"]               = mht_p4.pt();
    xgbInputs_dy["tau1_pt"]              = selHadTau_lead->pt();
    xgbInputs_dy["tau2_pt"]              = selHadTau_sublead->pt();
    xgbInputs_dy["tau1_eta"]             = selHadTau_lead->absEta();
    xgbInputs_dy["tau2_eta"]             = selHadTau_sublead->absEta();
    xgbInputs_dy["dr_taus"]              = deltaR(selHadTau_lead->p4(), selHadTau_sublead->p4());
    xgbInputs_dy["mT_tau1"]              = comp_MT_met_hadTau1(*selHadTau_lead, met.pt(), met.phi());
    xgbInputs_dy["mT_tau2"]              = comp_MT_met_hadTau2(*selHadTau_sublead, met.pt(), met.phi());
    xgbInputs_dy["mTauTauVis"]           = mTauTauVis;
    xgbInputs_dy["mTauTau"]           = mTauTau;
    xgbInputs_dy["HTT_wKinFit_top1"]     = max_mvaOutput_HTT_CSVsort4rd;
    xgbInputs_dy["HadTop1_pt"]           = HadTop_pt_CSVsort4rd;
    xgbInputs_dy["HadTop1_eta"]          = std::fabs(HadTop_eta_CSVsort4rd);
    xgbInputs_dy["HTT_wKinFit_top2"]     = max_mvaOutput_HTT_CSVsort4rd_2;
    xgbInputs_dy["HadTop2_pt"]           = HadTop_pt_CSVsort4rd;
    xgbInputs_dy["nJet"]                 = selJets.size();
    xgbInputs_dy["nBJetLoose"]           = selBJets_loose.size();
    xgbInputs_dy["nBJetMedium"]          = selBJets_medium.size();
    double mvaOutput_0l_2tau_HTT_sum_dy = xgb_0l_2tau_sum_dy(xgbInputs_dy);

    // --- BDTs calculated by Xanda
    //mvaInputs_XGB_Boosted_AK8
    mvaInputs_XGB_Boosted_AK8["mindr_tau1_jet"] = TMath::Min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets));
    mvaInputs_XGB_Boosted_AK8["mindr_tau2_jet"] = TMath::Min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets));
    mvaInputs_XGB_Boosted_AK8["avg_dr_jet"] = comp_avg_dr_jet(selJets);
    mvaInputs_XGB_Boosted_AK8["ptmiss"] = met.pt();
    mvaInputs_XGB_Boosted_AK8["tau1_pt"] = selHadTau_lead->pt();
    mvaInputs_XGB_Boosted_AK8["tau2_pt"] = selHadTau_sublead->pt();
    mvaInputs_XGB_Boosted_AK8["tau1_eta"] = selHadTau_lead->absEta();
    mvaInputs_XGB_Boosted_AK8["tau2_eta"] = selHadTau_sublead->absEta();
    mvaInputs_XGB_Boosted_AK8["dr_taus"] = deltaR(selHadTau_lead->p4(), selHadTau_sublead->p4());
    mvaInputs_XGB_Boosted_AK8["mT_tau1"] = comp_MT_met_hadTau1(*selHadTau_lead, met.pt(), met.phi());
    mvaInputs_XGB_Boosted_AK8["mT_tau2"] = comp_MT_met_hadTau2(*selHadTau_sublead, met.pt(), met.phi());
    mvaInputs_XGB_Boosted_AK8["mTauTauVis"] = mTauTauVis;
    mvaInputs_XGB_Boosted_AK8["mTauTau"] = mTauTau;
    mvaInputs_XGB_Boosted_AK8["nJet"] = selJets.size();
    mvaInputs_XGB_Boosted_AK8["nBJetLoose"] = selBJets_loose.size();
    mvaInputs_XGB_Boosted_AK8["nBJetMedium"] = selBJets_medium.size();
    mvaInputs_XGB_Boosted_AK8["res-HTT_CSVsort4rd_2"] = max_mvaOutput_HTT_CSVsort4rd_2;
    mvaInputs_XGB_Boosted_AK8["res-HTT_CSVsort4rd"] = max_mvaOutput_HTT_CSVsort4rd;
    mvaInputs_XGB_Boosted_AK8["HadTop_pt_CSVsort4rd"] = HadTop_pt_CSVsort4rd;
    mvaInputs_XGB_Boosted_AK8["resolved_and_semi_AK8"] = resolved_and_semi_AK8;
    mvaInputs_XGB_Boosted_AK8["boosted_and_semi_AK8"] = boosted_and_semi_AK8;
    mvaInputs_XGB_Boosted_AK8["minDR_HTTv2_lep"] = minDR_HTTv2_lep;
    mvaInputs_XGB_Boosted_AK8["minDR_AK8_lep"] = minDR_AK8_lep;
    mvaInputs_XGB_Boosted_AK8["HTT_boosted"] = HTT_boosted;
    mvaInputs_XGB_Boosted_AK8["HTT_semi_boosted_fromAK8"] = HTT_semi_boosted_fromAK8;
    double mva_Boosted_AK8 = mva_XGB_Boosted_AK8(mvaInputs_XGB_Boosted_AK8);
    //std::cout<<" mva_Boosted_AK8 "<<mva_Boosted_AK8<<std::endl;

    // mvaInputs_XGB_Updated
    mvaInputs_XGB_Updated["mindr_tau1_jet"] = TMath::Min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets));
    mvaInputs_XGB_Updated["mindr_tau2_jet"] = TMath::Min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets));
    mvaInputs_XGB_Updated["avg_dr_jet"] = comp_avg_dr_jet(selJets);
    mvaInputs_XGB_Updated["ptmiss"] = met.pt();
    mvaInputs_XGB_Updated["tau1_pt"] = selHadTau_lead->pt();
    mvaInputs_XGB_Updated["tau2_pt"] = selHadTau_sublead->pt();
    mvaInputs_XGB_Updated["tau1_eta"] = selHadTau_lead->absEta();
    mvaInputs_XGB_Updated["tau2_eta"] = selHadTau_sublead->absEta();
    mvaInputs_XGB_Updated["dr_taus"] = deltaR(selHadTau_lead->p4(), selHadTau_sublead->p4());
    mvaInputs_XGB_Updated["mT_tau1"] = comp_MT_met_hadTau1(*selHadTau_lead, met.pt(), met.phi());
    mvaInputs_XGB_Updated["mT_tau2"] = comp_MT_met_hadTau2(*selHadTau_sublead, met.pt(), met.phi());
    mvaInputs_XGB_Updated["mTauTauVis"] = mTauTauVis;
    mvaInputs_XGB_Updated["mTauTau"] = mTauTau;
    mvaInputs_XGB_Updated["nJet"] = selJets.size();
    mvaInputs_XGB_Updated["nBJetLoose"] = selBJets_loose.size();
    mvaInputs_XGB_Updated["nBJetMedium"] = selBJets_medium.size();
    mvaInputs_XGB_Updated["res-HTT_CSVsort4rd_2"] = max_mvaOutput_HTT_CSVsort4rd_2;
    mvaInputs_XGB_Updated["res-HTT_CSVsort4rd"] = max_mvaOutput_HTT_CSVsort4rd;
    mvaInputs_XGB_Updated["HadTop_pt_CSVsort4rd_2"] = HadTop_pt_CSVsort4rd_2;
    mvaInputs_XGB_Updated["HadTop_pt_CSVsort4rd"] = HadTop_pt_CSVsort4rd;
    double mva_Updated = mva_XGB_Updated(mvaInputs_XGB_Updated);
    //std::cout<<" mva_Updated "<<mva_Updated<<std::endl;

//--- fill histograms with events passing final selection
    selHistManagerType* selHistManager = selHistManagers[idxSelHadTau_genMatch];
    assert(selHistManager != 0);
    selHistManager->electrons_->fillHistograms(preselElectrons, evtWeight);
    selHistManager->muons_->fillHistograms(preselMuons, evtWeight);
    selHistManager->hadTaus_->fillHistograms({ selHadTau_lead, selHadTau_sublead }, evtWeight);
    selHistManager->leadHadTau_->fillHistograms({ selHadTau_lead }, evtWeight);
    selHistManager->subleadHadTau_->fillHistograms({ selHadTau_sublead }, evtWeight);
    selHistManager->jets_->fillHistograms(selJets, evtWeight);
    selHistManager->leadJet_->fillHistograms(selJets, evtWeight);
    selHistManager->subleadJet_->fillHistograms(selJets, evtWeight);
    selHistManager->BJets_loose_->fillHistograms(selBJets_loose, evtWeight);
    selHistManager->leadBJet_loose_->fillHistograms(selBJets_loose, evtWeight);
    selHistManager->subleadBJet_loose_->fillHistograms(selBJets_loose, evtWeight);
    selHistManager->BJets_medium_->fillHistograms(selBJets_medium, evtWeight);
    selHistManager->met_->fillHistograms(met, mht_p4, met_LD, evtWeight);
    selHistManager->metFilters_->fillHistograms(metFilters, evtWeight);
    selHistManager->mvaInputVariables_ttbar_->fillHistograms(mvaInputs_ttbar, evtWeight);
    //selHistManager->mvaInputVariables_ttV_->fillHistograms(mvaInputs_ttV, evtWeight);
    //selHistManager->xgbInputVariables_ttbar_->fillHistograms(xgbInputs_ttbar, evtWeight);
    selHistManager->evt_->fillHistograms(
      preselElectrons.size(), preselMuons.size(), selHadTaus.size(),
      selJets.size(), selBJets_loose.size(), selBJets_medium.size(),
      mvaOutput_0l_2tau_ttbar, mvaOutput_0l_2tau_HTT_tt, mvaOutput_0l_2tau_HTT_ttv,
      mvaOutput_0l_2tau_HTT_sum, mvaOutput_0l_2tau_HTT_sum_dy, mvaDiscr_0l_2tau_HTT,
      mva_Boosted_AK8, mva_Updated, mTauTauVis, mTauTau,
      pZeta, pZetaVis, pZetaComb, mT_tau1, mT_tau2, mbb, mbb_loose, evtWeight);
    if ( isSignal ) {
      const std::string decayModeStr = eventInfo.getDecayModeString();
      if(! decayModeStr.empty())
      {
        selHistManager->evt_in_decayModes_[decayModeStr]->fillHistograms(
          preselElectrons.size(),
          preselMuons.size(),
          selHadTaus.size(),
          selJets.size(),
          selBJets_loose.size(),
          selBJets_medium.size(),
          mvaOutput_0l_2tau_ttbar,
	  mvaOutput_0l_2tau_HTT_tt,
	  mvaOutput_0l_2tau_HTT_ttv,
	  mvaOutput_0l_2tau_HTT_sum,
	  mvaOutput_0l_2tau_HTT_sum_dy,
	  mvaDiscr_0l_2tau_HTT,
	  mva_Boosted_AK8,
	  mva_Updated,
          mTauTauVis,
          mTauTau,
          pZeta,
	  pZetaVis,
	  pZetaComb,
	  mT_tau1,
	  mT_tau2,
	  mbb,
          mbb_loose,
	  evtWeight
        );
      }
    }
    selHistManager->evtYield_->fillHistograms(eventInfo, evtWeight);
    selHistManager->weights_->fillHistograms("genWeight", eventInfo.genWeight);
    selHistManager->weights_->fillHistograms("pileupWeight", eventInfo.pileupWeight);
    selHistManager->weights_->fillHistograms("data_to_MC_correction", weight_data_to_MC_correction);
    selHistManager->weights_->fillHistograms("triggerWeight", triggerWeight);
    selHistManager->weights_->fillHistograms("hadTauEff", weight_hadTauEff);
    selHistManager->weights_->fillHistograms("fakeRate", weight_fakeRate);
    /*
    std::string category;
    if   ( selBJets_medium.size() >= 1 ) category = "0l_2tau_btight";
    else                                 category = "0l_2tau_bloose";
    selHistManager->evt_in_categories_[category]->fillHistograms(
      preselElectrons.size(), preselMuons.size(), selHadTaus.size(),
      selJets.size(), selBJets_loose.size(), selBJets_medium.size(),
      mvaOutput_0l_2tau_ttbar, mvaOutput_0l_2tau_HTT_tt, mvaOutput_0l_2tau_HTT_ttv,
      mvaOutput_0l_2tau_HTT_sum, mvaOutput_0l_2tau_HTT_sum_dy, mvaDiscr_0l_2tau_HTT,
      mva_Boosted_AK8, mva_Updated, mTauTauVis, mTauTau,
      pZeta, pZetaVis, pZetaComb, mT_tau1, mT_tau2, mbb, mbb_loose, evtWeight);
    */
    std::vector<std::string> categories;
    if(selJets.size() >= 4){
      if   ( selBJets_medium.size() >= 2 ) categories.push_back("0l_2tau_2bM_2j");
      if   ( selBJets_medium.size() >= 1 ) categories.push_back("0l_2tau_1bM_2j");
      else                                 categories.push_back("0l_2tau_0bM_2j");
    }
    if(selJets.size() >= 3){
      if   ( selBJets_medium.size() >= 2 ) categories.push_back("0l_2tau_2bM_1j");
      if   ( selBJets_medium.size() >= 1 ) categories.push_back("0l_2tau_1bM_1j");
      else                                 categories.push_back("0l_2tau_0bM_1j");
    }
    if(selJets.size() >= 2){
      if   ( selBJets_medium.size() >= 2 ) categories.push_back("0l_2tau_2bM_0j");
      if   ( selBJets_medium.size() >= 1 ) categories.push_back("0l_2tau_1bM_0j");
      else                                 categories.push_back("0l_2tau_0bM_0j");
    }
    for ( std::vector<std::string>::const_iterator category = categories.begin();
          category != categories.end(); ++category ) {
      selHistManager->evt_in_categories_[*category]->fillHistograms(
	preselElectrons.size(), preselMuons.size(), selHadTaus.size(),
	selJets.size(), selBJets_loose.size(), selBJets_medium.size(),
	mvaOutput_0l_2tau_ttbar, mvaOutput_0l_2tau_HTT_tt, mvaOutput_0l_2tau_HTT_ttv,
	mvaOutput_0l_2tau_HTT_sum, mvaOutput_0l_2tau_HTT_sum_dy, mvaDiscr_0l_2tau_HTT,
	mva_Boosted_AK8, mva_Updated, mTauTauVis, mTauTau,
	pZeta, pZetaVis, pZetaComb, mT_tau1, mT_tau2, mbb, mbb_loose, evtWeight);
    }

    if ( isMC ) {
      genEvtHistManager_afterCuts->fillHistograms(genElectrons, genMuons, genHadTaus, genPhotons, genJets, evtWeight_inclusive);
      lheInfoHistManager->fillHistograms(*lheInfoReader, evtWeight);
      if(eventWeightManager)
      {
        genEvtHistManager_afterCuts->fillHistograms(eventWeightManager, evtWeight_inclusive);
      }
    }

    if ( selEventsFile ) {
      (*selEventsFile) << eventInfo.run << ':' << eventInfo.lumi << ':' << eventInfo.event << '\n';
    }

    const bool isGenMatched = isMC &&
      ((apply_hadTauGenMatching && selHadTau_genMatch.numGenMatchedJets_ == 0) || ! apply_hadTauGenMatching)
    ;

    if(bdt_filler)
    {
      bdt_filler -> operator()({ eventInfo.run, eventInfo.lumi, eventInfo.event })
          ("mindr_tau1_jet", TMath::Min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets)))
          ("mindr_tau2_jet", TMath::Min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets)))
          ("avg_dr_jet",     comp_avg_dr_jet(selJets))
          ("ptmiss",         met.pt())
          ("htmiss",         mht_p4.pt())
          ("tau1_mva",       selHadTau_lead -> raw_mva_dR03())
          ("tau2_mva",       selHadTau_sublead -> raw_mva_dR03())
          ("tau1_pt",        selHadTau_lead -> pt())
          ("tau2_pt",        selHadTau_sublead -> pt())
          ("tau1_eta",       selHadTau_lead -> eta())
          ("tau2_eta",       selHadTau_sublead -> eta())
          ("dr_taus",        deltaR(selHadTau_lead -> p4(), selHadTau_sublead -> p4()))
          ("mT_tau1",        mT_tau1)
          ("mT_tau2",        mT_tau2)
          //("pZeta",          pZeta)
          //("pZetaVis",       pZetaVis)
          //("pZetaComb",      pZetaComb)
          ("mTauTauVis",     mTauTauVis)
          ("mTauTau",        mTauTau)
          ("lumiScale",      lumiScale)
          ("genWeight",      eventInfo.genWeight)
          ("evtWeight",      evtWeight)
          ("nJet",           selJets.size())
          ("nBJetLoose",     selBJets_loose.size())
          ("nBJetMedium",    selBJets_medium.size())

          ("hadtruth",               hadtruth)
          ("hadtruth_2",               hadtruth_2)
          ("res-HTT_CSVsort4rd",                 max_mvaOutput_HTT_CSVsort4rd)
          ("res-HTT_CSVsort4rd_2",                 max_mvaOutput_HTT_CSVsort4rd_2)
          ("bWj1Wj2_isGenMatched_CSVsort4rd",              max_truth_HTT_CSVsort4rd)
          ("bWj1Wj2_isGenMatched_CSVsort4rd_2",              max_truth_HTT_CSVsort4rd_2)
          ("HadTop_pt_CSVsort4rd",            HadTop_pt_CSVsort4rd)
          ("HadTop_pt_CSVsort4rd_2",            HadTop_pt_CSVsort4rd_2)
          ("genTopPt_CSVsort4rd",             genTopPt_CSVsort4rd)
          ("genTopPt_CSVsort4rd_2",             genTopPt_CSVsort4rd_2)

          ("resolved_and_semi_AK8",     resolved_and_semi_AK8)
          ("boosted_and_semi_AK8",      boosted_and_semi_AK8)
          ("resolved_and_boosted",      resolved_and_boosted)

          ("N_jetAK8",     jet_ptrsAK8.size())
          ("cleanedJets_fromAK8",       cleanedJets_fromAK8.size())
          ("minDR_AK8_lep",                minDR_AK8_lep)
          ("minDR_AK8subjets_lep",         minDR_AK8subjets_lep)
          ("HTT_semi_boosted_fromAK8",                     HTT_semi_boosted_fromAK8)
          ("bWj1Wj2_isGenMatched_semi_boosted_fromAK8",    bWj1Wj2_isGenMatched_semi_boosted_fromAK8)
          ("genTopPt_semi_boosted_fromAK8",            genTopPt_semi_boosted_fromAK8)
          ("HadTop_pt_semi_boosted_fromAK8",           HadTop_pt_semi_boosted_fromAK8)
          ("hadtruth_semi_boosted_fromAK8",          hadtruth_semi_boosted_fromAK8)

          ("nHTTv2",                         sel_HTTv2.size())
          ("minDR_HTTv2_lep",                minDR_HTTv2_lep)
          ("minDR_HTTv2subjets_lep",         minDR_HTTv2subjets_lep)
          ("HTT_boosted",                     HTT_boosted)
          ("bWj1Wj2_isGenMatched_boosted",    bWj1Wj2_isGenMatched_boosted)
          ("genTopPt_boosted",            genTopPt_boosted)
          ("HadTop_pt_boosted",           HadTop_pt_boosted)
          ("hadtruth_boosted",               hadtruth_boosted)
          // Xanda: I still did not added those to datacards making
          ("mva_Boosted_AK8", mva_Boosted_AK8)
          ("mva_Updated",     mva_Updated)

        .fill()
      ;
    }

    if(snm)
    {
      const double avg_dr_jet      = comp_avg_dr_jet(selJets);
      const double max_dr_jet      = comp_max_dr_jet(selJets);
      //const double mbb             = selBJets_medium.size() > 1 ? (selBJets_medium[0]->p4() + selBJets_medium[1]->p4()).mass() : -1.;
      //const double mbb_loose       = selBJets_loose.size() > 1 ? (selBJets_loose[0]->p4() + selBJets_loose[1]->p4()).mass() : -1.;
      const double mindr_tau1_jet  = std::min(10., comp_mindr_hadTau1_jet(*selHadTau_lead, selJets));
      const double mindr_tau2_jet  = std::min(10., comp_mindr_hadTau2_jet(*selHadTau_sublead, selJets));
      const double min_dr_tau_jet  = std::min(mindr_tau1_jet, mindr_tau2_jet);
      const double dr_taus         = deltaR(selHadTau_lead->p4(), selHadTau_sublead->p4());

      snm->read(eventInfo);
      snm->read(preselMuons,     fakeableMuons,     tightMuons);
      snm->read(preselElectrons, fakeableElectrons, tightElectrons);
      snm->read(preselHadTausFull);
      snm->read(selJets);

      snm->read({ triggers_2tau });
      snm->read(isGenMatched, selBJets_medium.size(), selBJets_loose.size());

      snm->read(met.pt(),                               FloatVariableType::PFMET);
      snm->read(met.phi(),                              FloatVariableType::PFMETphi);
      snm->read(mht_p4.pt(),                            FloatVariableType::MHT);
      snm->read(met_LD,                                 FloatVariableType::metLD);

      // mindr_lep_jet not filled
      // mindr_lep2_jet not filled
      // mindr_lep3_jet not filled
      // mindr_lep4_jet not filled

      snm->read(mindr_tau1_jet,                         FloatVariableType::mindr_tau1_jet);
      snm->read(mindr_tau2_jet,                         FloatVariableType::mindr_tau2_jet);

      snm->read(avg_dr_jet,                             FloatVariableType::avg_dr_jet);
      // avr_dr_lep_tau not filled
      snm->read(max_dr_jet,                             FloatVariableType::max_dr_jet);
      // max_dr_lep_tau not filled
      snm->read(min_dr_tau_jet,                         FloatVariableType::min_dr_tau_jet);
      // min_dr_lep_tau not filled
      // min_dr_lep_jet not filled

      // dr_leps not filled
      snm->read(dr_taus,                                FloatVariableType::dr_taus);

      // dr_lep_tau_ss not filled
      // dr_lep1_tau1 not filled
      // dr_lep1_tau2 not filled
      // dr_lep2_tau1 not filled
      // dr_lep3_tau1 not filled
      // dr_lep2_tau2 not filled

      // max_lep_eta not filled

      // mT_met_lep1 not filled
      // mT_met_lep2 not filled
      // mT_met_lep3 not filled
      // mT_met_lep4 not filled

      snm->read(mTauTauVis,                             FloatVariableType::mTauTauVis);
      // mvis_l1tau not filled
      // mvis_l2tau not filled

      snm->read(mbb,                                    FloatVariableType::mbb);
      snm->read(mbb_loose,                              FloatVariableType::mbb_loose);

      // cosThetaS_hadTau not filled
      // HTT not filled
      // HadTop_pt not filled
      // Hj_tagger not filled

      // mvaOutput_plainKin_ttV not filled
      // mvaOutput_plainKin_tt not filled
      // mvaOutput_plainKin_1B_VT not filled
      // mvaOutput_HTT_SUM_VT not filled
      // mvaOutput_plainKin_SUM_VT not filled

      // mvaOutput_plainKin_SUM_VT not filled

      // mvaOutput_2lss_ttV not filled
      // mvaOutput_2lss_tt not filled
      // mvaOutput_2lss_1tau_plainKin_tt not filled
      // mvaOutput_2lss_1tau_plainKin_ttV not filled
      // mvaOutput_2lss_1tau_plainKin_1B_M not filled
      // mvaOutput_2lss_1tau_plainKin_SUM_M not filled
      // mvaOutput_2lss_1tau_HTT_SUM_M not filled
      // mvaOutput_2lss_1tau_HTTMEM_SUM_M not filled

      // mvaOutput_3l_ttV not filled
      // mvaOutput_3l_ttbar not filled
      // mvaOutput_plainKin_SUM_M not filled
      // mvaOutput_plainKin_1B_M not filled

      snm->read(weight_fakeRate,                        FloatVariableType::FR_weight);
      snm->read(triggerWeight,                          FloatVariableType::triggerSF_weight);
      // weight_leptonEff not filled
      snm->read(tauSF_weight,                           FloatVariableType::tauSF_weight);
      snm->read(btagWeight,                             FloatVariableType::bTagSF_weight);
      snm->read(eventInfo.pileupWeight,                 FloatVariableType::PU_weight);
      snm->read(boost::math::sign(eventInfo.genWeight), FloatVariableType::MC_weight);

      // Integral_ttH not filled
      // Integral_ttZ not filled
      // Integral_ttZ_Zll not filled
      // Integral_ttbar not filled
      // integration_type not filled
      // MEM_LR not filled

      snm->read(eventInfo.genWeight,                    FloatVariableType::genWeight);

      if((sync_requireGenMatching && isGenMatched) || ! sync_requireGenMatching)
      {
        snm->fill();
      }
      else
      {
        snm->reset();
      }
    }

    ++selectedEntries;
    selectedEntries_weighted += evtWeight;
    histogram_selectedEntries->Fill(0.);
  }

  if(snm)
  {
    snm->write();
  }

  std::cout << "max num. Entries = " << inputTree -> getCumulativeMaxEventCount()
            << " (limited by " << maxEvents << ") processed in "
            << inputTree -> getProcessedFileCount() << " file(s) (out of "
            << inputTree -> getFileCount() << ")\n"
            << " analyzed = " << analyzedEntries << '\n'
            << " selected = " << selectedEntries << " (weighted = " << selectedEntries_weighted << ")\n\n"
            << "cut-flow table" << std::endl;
  cutFlowTable.print(std::cout);
  std::cout << std::endl;

  std::cout << "sel. Entries by gen. matching:" << std::endl;
  for ( std::vector<hadTauGenMatchEntry>::const_iterator hadTauGenMatch_definition = hadTauGenMatch_definitions.begin();
        hadTauGenMatch_definition != hadTauGenMatch_definitions.end(); ++hadTauGenMatch_definition ) {

    std::string process_and_genMatch = process_string;
    if ( apply_hadTauGenMatching ) process_and_genMatch += hadTauGenMatch_definition->name_;

    int idxHadTau = hadTauGenMatch_definition->idx_;

    const TH1* histogram_EventCounter = selHistManagers[idxHadTau]->evt_->getHistogram_EventCounter();
    std::cout << " " << process_and_genMatch << " = " << histogram_EventCounter->GetEntries()
              << " (weighted = " << histogram_EventCounter->Integral() << ")" << std::endl;
  }
  std::cout << std::endl;

  delete dataToMCcorrectionInterface;

  delete jetToTauFakeRateInterface;

  delete run_lumi_eventSelector;

  delete selEventsFile;
  delete bdt_filler;

  delete muonReader;
  delete electronReader;
  delete hadTauReader;
  delete jetReader;
  delete metReader;
  delete metFilterReader;
  delete genLeptonReader;
  delete genHadTauReader;
  delete genPhotonReader;
  delete genJetReader;
  delete lheInfoReader;

  delete hadTopTagger;

  delete genEvtHistManager_beforeCuts;
  delete genEvtHistManager_afterCuts;
  delete lheInfoHistManager;
  delete cutFlowHistManager;
  delete eventWeightManager;

  hltPaths_delete(triggers_2tau);

  delete inputTree;
  delete snm;

  fmap->Close();

  clock.Show("analyze_0l_2tau");

  return EXIT_SUCCESS;
}
