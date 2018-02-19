#include "FWCore/ParameterSet/interface/ParameterSet.h" // edm::ParameterSet
#include "FWCore/PythonParameterSet/interface/MakeParameterSets.h" // edm::readPSetsFrom()
#include "FWCore/Utilities/interface/Exception.h" // cms::Exception
#include "PhysicsTools/FWLite/interface/TFileService.h" // fwlite::TFileService
#include "DataFormats/FWLite/interface/InputSource.h" // fwlite::InputSource
#include "DataFormats/FWLite/interface/OutputFiles.h" // fwlite::OutputFiles
#include "DataFormats/Math/interface/LorentzVector.h" // math::PtEtaPhiMLorentzVector
#include "DataFormats/Math/interface/deltaR.h" // deltaR

#include <TBenchmark.h> // TBenchmark
#include <TString.h> // TString, Form
#include <TMatrixD.h> // TMatrixD
#include <TError.h> // gErrorAbortLevel, kError

#include "tthAnalysis/HiggsToTauTau/interface/RecoLepton.h" // RecoLepton
#include "tthAnalysis/HiggsToTauTau/interface/RecoJet.h" // RecoJet
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetHTTv2.h" // RecoJetHTTv2
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetAK12.h" // RecoJetAK12
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTau.h" // RecoHadTau
#include "tthAnalysis/HiggsToTauTau/interface/GenLepton.h" // GenLepton
#include "tthAnalysis/HiggsToTauTau/interface/GenJet.h" // GenJet
#include "tthAnalysis/HiggsToTauTau/interface/GenHadTau.h" // GenHadTau
#include "tthAnalysis/HiggsToTauTau/interface/RecoMEt.h" // RecoMEt
#include "tthAnalysis/HiggsToTauTau/interface/MEMOutput_2lss_1tau.h" // MEMOutput_2lss_1tau
#include "tthAnalysis/HiggsToTauTau/interface/TMVAInterface.h" // TMVAInterface
#include "tthAnalysis/HiggsToTauTau/interface/mvaAuxFunctions.h" // check_mvaInputs, get_mvaInputVariables
#include "tthAnalysis/HiggsToTauTau/interface/mvaInputVariables.h" // auxiliary functions for computing input variables of the MVA used for signal extraction in the 2lss_1tau category
#include "tthAnalysis/HiggsToTauTau/interface/LeptonFakeRateInterface.h" // LeptonFakeRateInterface
#include "tthAnalysis/HiggsToTauTau/interface/JetToTauFakeRateInterface.h" // JetToTauFakeRateInterface
#include "tthAnalysis/HiggsToTauTau/interface/RecoElectronReader.h" // RecoElectronReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoMuonReader.h" // RecoMuonReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTauReader.h" // RecoHadTauReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetReader.h" // RecoJetReader
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetReaderHTTv2.h" // RecoJetReaderHTTv2
#include "tthAnalysis/HiggsToTauTau/interface/RecoJetReaderAK12.h" // RecoJetReaderAK12
#include "tthAnalysis/HiggsToTauTau/interface/RecoMEtReader.h" // RecoMEtReader
#include "tthAnalysis/HiggsToTauTau/interface/MEMOutputReader_2lss_1tau.h" // MEMOutputReader_2lss_1tau
#include "tthAnalysis/HiggsToTauTau/interface/GenLeptonReader.h" // GenLeptonReader
#include "tthAnalysis/HiggsToTauTau/interface/GenHadTauReader.h" // GenHadTauReader
#include "tthAnalysis/HiggsToTauTau/interface/GenJetReader.h" // GenJetReader
#include "tthAnalysis/HiggsToTauTau/interface/GenParticleReader.h" // GenParticleReader
#include "tthAnalysis/HiggsToTauTau/interface/LHEInfoReader.h" // LHEInfoReader
#include "tthAnalysis/HiggsToTauTau/interface/EventInfoReader.h" // EventInfoReader, EventInfo
#include "tthAnalysis/HiggsToTauTau/interface/convert_to_ptrs.h" // convert_to_ptrs
#include "tthAnalysis/HiggsToTauTau/interface/ParticleCollectionCleaner.h" // RecoElectronCollectionCleaner, RecoMuonCollectionCleaner, RecoHadTauCollectionCleaner, RecoJetCollectionCleaner
#include "tthAnalysis/HiggsToTauTau/interface/ParticleCollectionGenMatcher.h" // RecoElectronCollectionGenMatcher, RecoMuonCollectionGenMatcher, RecoHadTauCollectionGenMatcher, RecoJetCollectionGenMatcher
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
#include "tthAnalysis/HiggsToTauTau/interface/RunLumiEventSelector.h" // RunLumiEventSelector
#include "tthAnalysis/HiggsToTauTau/interface/ElectronHistManager.h" // ElectronHistManager
#include "tthAnalysis/HiggsToTauTau/interface/MuonHistManager.h" // MuonHistManager
#include "tthAnalysis/HiggsToTauTau/interface/HadTauHistManager.h" // HadTauHistManager
#include "tthAnalysis/HiggsToTauTau/interface/JetHistManager.h" // JetHistManager
#include "tthAnalysis/HiggsToTauTau/interface/JetHistManagerHTTv2.h" // JetHistManagerHTTv2
#include "tthAnalysis/HiggsToTauTau/interface/JetHistManagerAK12.h" // JetHistManagerAK12
#include "tthAnalysis/HiggsToTauTau/interface/MEtHistManager.h" // MEtHistManager
#include "tthAnalysis/HiggsToTauTau/interface/MVAInputVarHistManager.h" // MVAInputVarHistManager
#include "tthAnalysis/HiggsToTauTau/interface/EvtHistManager_2lss_1tau.h" // EvtHistManager_2lss_1tau
#include "tthAnalysis/HiggsToTauTau/interface/WeightHistManager.h" // WeightHistManager
#include "tthAnalysis/HiggsToTauTau/interface/GenEvtHistManager.h" // GenEvtHistManager
#include "tthAnalysis/HiggsToTauTau/interface/LHEInfoHistManager.h" // LHEInfoHistManager
#include "tthAnalysis/HiggsToTauTau/interface/leptonTypes.h" // getLeptonType, kElectron, kMuon
#include "tthAnalysis/HiggsToTauTau/interface/analysisAuxFunctions.h" // getBranchName_bTagWeight, getHadTau_genPdgId, isHigherPt, isMatched
#include "tthAnalysis/HiggsToTauTau/interface/HistManagerBase.h" // HistManagerBase
#include "tthAnalysis/HiggsToTauTau/interface/histogramAuxFunctions.h" // fillWithOverFlow2d
#include "tthAnalysis/HiggsToTauTau/interface/hadTopTaggerAuxFunctions.h" // isGenMatchedJetTriplet
#include "tthAnalysis/HiggsToTauTau/interface/leptonGenMatchingAuxFunctions.h" // getLeptonGenMatch_definitions_1lepton, getLeptonGenMatch_string, getLeptonGenMatch_int
#include "tthAnalysis/HiggsToTauTau/interface/hadTauGenMatchingAuxFunctions.h" // getHadTauGenMatch_definitions_1tau, getHadTauGenMatch_string, getHadTauGenMatch_int
#include "tthAnalysis/HiggsToTauTau/interface/fakeBackgroundAuxFunctions.h" // getWeight_2L, getWeight_3L
#include "tthAnalysis/HiggsToTauTau/interface/backgroundEstimation.h" // prob_chargeMisId
#include "tthAnalysis/HiggsToTauTau/interface/hltPath.h" // hltPath, create_hltPaths, hltPaths_setBranchAddresses, hltPaths_isTriggered, hltPaths_delete
#include "tthAnalysis/HiggsToTauTau/interface/Data_to_MC_CorrectionInterface.h" // Data_to_MC_CorrectionInterface
#include "tthAnalysis/HiggsToTauTau/interface/lutAuxFunctions.h" // loadTH2, getSF_from_TH2
#include "tthAnalysis/HiggsToTauTau/interface/cutFlowTable.h" // cutFlowTableType
#include "tthAnalysis/HiggsToTauTau/interface/NtupleFillerBDT.h" // NtupleFillerBDT
#include "tthAnalysis/HiggsToTauTau/interface/HadTopTagger.h" // HadTopTagger
#include "tthAnalysis/HiggsToTauTau/interface/TTreeWrapper.h" // TTreeWrapper

#include <boost/math/special_functions/sign.hpp> // boost::math::sign()

#include <iostream> // std::cerr, std::fixed
#include <iomanip> // std::setprecision(), std::setw()
#include <string> // std::string
#include <vector> // std::vector<>
#include <cstdlib> // EXIT_SUCCESS, EXIT_FAILURE
#include <algorithm> // std::sort
#include <fstream> // std::ofstream
#include <assert.h> // assert

typedef math::PtEtaPhiMLorentzVector LV;
typedef std::vector<std::string> vstring;

//const int hadTauSelection_antiElectron = 1; // vLoose
//const int hadTauSelection_antiMuon = 1; // Loose
const int hadTauSelection_antiElectron = -1; // not applied
const int hadTauSelection_antiMuon = -1; // not applied

void dumpGenParticles(const std::string& label, const std::vector<GenParticle>& particles)
{
  for ( size_t idxParticle = 0; idxParticle < particles.size(); ++idxParticle ) {
    std::cout << label << " #" << idxParticle << ":" << std::endl;
    std::cout << particles[idxParticle];
  }
}

double square(double x)
{
  return x*x;
}

/**
 * @brief Check why only 25% of ttH signal events selected in 2lss_1tau category
 *        contain a reconstructible hadronic top
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

  std::cout << "<analyze_hadTopTagger_gen>:" << std::endl;

//--- keep track of time it takes the macro to execute
  TBenchmark clock;
  clock.Start("analyze_hadTopTagger_gen");

//--- read python configuration parameters
  if ( !edm::readPSetsFrom(argv[1])->existsAs<edm::ParameterSet>("process") )
    throw cms::Exception("analyze_hadTopTagger_gen")
      << "No ParameterSet 'process' found in configuration file = " << argv[1] << " !!\n";

  edm::ParameterSet cfg = edm::readPSetsFrom(argv[1])->getParameter<edm::ParameterSet>("process");

  edm::ParameterSet cfg_analyze = cfg.getParameter<edm::ParameterSet>("analyze_hadTopTagger_gen");

  std::string treeName = cfg_analyze.getParameter<std::string>("treeName");

  std::string process_string = cfg_analyze.getParameter<std::string>("process");
  bool isSignal = ( process_string == "signal" ) ? true : false;

  std::string histogramDir = cfg_analyze.getParameter<std::string>("histogramDir");

  std::string era_string = cfg_analyze.getParameter<std::string>("era");
  int era = -1;
  if      ( era_string == "2017" ) era = kEra_2017;
  else throw cms::Exception("analyze_hadTopTagger_gen")
    << "Invalid Configuration parameter 'era' = " << era_string << " !!\n";

  vstring triggerNames_1e = cfg_analyze.getParameter<vstring>("triggers_1e");
  std::vector<hltPath*> triggers_1e = create_hltPaths(triggerNames_1e);
  bool use_triggers_1e = cfg_analyze.getParameter<bool>("use_triggers_1e");
  vstring triggerNames_2e = cfg_analyze.getParameter<vstring>("triggers_2e");
  std::vector<hltPath*> triggers_2e = create_hltPaths(triggerNames_2e);
  bool use_triggers_2e = cfg_analyze.getParameter<bool>("use_triggers_2e");
  vstring triggerNames_1mu = cfg_analyze.getParameter<vstring>("triggers_1mu");
  std::vector<hltPath*> triggers_1mu = create_hltPaths(triggerNames_1mu);
  bool use_triggers_1mu = cfg_analyze.getParameter<bool>("use_triggers_1mu");
  vstring triggerNames_2mu = cfg_analyze.getParameter<vstring>("triggers_2mu");
  std::vector<hltPath*> triggers_2mu = create_hltPaths(triggerNames_2mu);
  bool use_triggers_2mu = cfg_analyze.getParameter<bool>("use_triggers_2mu");
  vstring triggerNames_1e1mu = cfg_analyze.getParameter<vstring>("triggers_1e1mu");
  std::vector<hltPath*> triggers_1e1mu = create_hltPaths(triggerNames_1e1mu);
  bool use_triggers_1e1mu = cfg_analyze.getParameter<bool>("use_triggers_1e1mu");

  bool apply_offline_e_trigger_cuts_1e = cfg_analyze.getParameter<bool>("apply_offline_e_trigger_cuts_1e");
  bool apply_offline_e_trigger_cuts_2e = cfg_analyze.getParameter<bool>("apply_offline_e_trigger_cuts_2e");
  bool apply_offline_e_trigger_cuts_1mu = cfg_analyze.getParameter<bool>("apply_offline_e_trigger_cuts_1mu");
  bool apply_offline_e_trigger_cuts_2mu = cfg_analyze.getParameter<bool>("apply_offline_e_trigger_cuts_2mu");
  bool apply_offline_e_trigger_cuts_1e1mu = cfg_analyze.getParameter<bool>("apply_offline_e_trigger_cuts_1e1mu");

  enum { kOS, kSS };
  std::string leptonChargeSelection_string = cfg_analyze.getParameter<std::string>("leptonChargeSelection");
  int leptonChargeSelection = -1;
  if      ( leptonChargeSelection_string == "OS" ) leptonChargeSelection = kOS;
  else if ( leptonChargeSelection_string == "SS" ) leptonChargeSelection = kSS;
  else throw cms::Exception("analyze_hadTopTagger_gen")
    << "Invalid Configuration parameter 'leptonChargeSelection' = " << leptonChargeSelection_string << " !!\n";

  std::string leptonSelection_string = cfg_analyze.getParameter<std::string>("leptonSelection").data();
  std::cout << "leptonSelection_string = " << leptonSelection_string << std::endl;
  int leptonSelection = -1;
  if      ( leptonSelection_string == "Loose"                                                      ) leptonSelection = kLoose;
  else if ( leptonSelection_string == "Fakeable" || leptonSelection_string == "Fakeable_mcClosure" ) leptonSelection = kFakeable;
  else if ( leptonSelection_string == "Tight"                                                      ) leptonSelection = kTight;
  else throw cms::Exception("analyze_hadTopTagger_gen")
    << "Invalid Configuration parameter 'leptonSelection' = " << leptonSelection_string << " !!\n";

  bool apply_leptonGenMatching = cfg_analyze.getParameter<bool>("apply_leptonGenMatching");
  std::vector<leptonGenMatchEntry> leptonGenMatch_definitions = getLeptonGenMatch_definitions_2lepton(apply_leptonGenMatching);
  std::cout << "leptonGenMatch_definitions:" << std::endl;
  std::cout << leptonGenMatch_definitions;
  bool apply_leptonGenMatching_ttZ_workaround = cfg_analyze.getParameter<bool>("apply_leptonGenMatching_ttZ_workaround");
  std::cout << "apply_leptonGenMatching_ttZ_workaround = " << apply_leptonGenMatching_ttZ_workaround << std::endl;

  TString hadTauSelection_string = cfg_analyze.getParameter<std::string>("hadTauSelection").data();
  TObjArray* hadTauSelection_parts = hadTauSelection_string.Tokenize("|");
  assert(hadTauSelection_parts->GetEntries() >= 1);
  std::string hadTauSelection_part1 = (dynamic_cast<TObjString*>(hadTauSelection_parts->At(0)))->GetString().Data();
  int hadTauSelection = -1;
  if      ( hadTauSelection_part1 == "Loose"                                                     ) hadTauSelection = kLoose;
  else if ( hadTauSelection_part1 == "Fakeable" || hadTauSelection_part1 == "Fakeable_mcClosure" ) hadTauSelection = kFakeable;
  else if ( hadTauSelection_part1 == "Tight"                                                     ) hadTauSelection = kTight;
  else throw cms::Exception("analyze_hadTopTagger_gen")
    << "Invalid Configuration parameter 'hadTauSelection' = " << hadTauSelection_string << " !!\n";
  std::string hadTauSelection_part2 = ( hadTauSelection_parts->GetEntries() == 2 ) ? (dynamic_cast<TObjString*>(hadTauSelection_parts->At(1)))->GetString().Data() : "";
  delete hadTauSelection_parts;

  bool apply_hadTauGenMatching = cfg_analyze.getParameter<bool>("apply_hadTauGenMatching");
  std::vector<hadTauGenMatchEntry> hadTauGenMatch_definitions = getHadTauGenMatch_definitions_1tau(apply_hadTauGenMatching);
  std::cout << "hadTauGenMatch_definitions:" << std::endl;
  std::cout << hadTauGenMatch_definitions;

  std::string chargeSumSelection_string = cfg_analyze.getParameter<std::string>("chargeSumSelection");
  int chargeSumSelection = -1;
  if      ( chargeSumSelection_string == "OS" ) chargeSumSelection = kOS;
  else if ( chargeSumSelection_string == "SS" ) chargeSumSelection = kSS;
  else throw cms::Exception("analyze_hadTopTagger_gen")
    << "Invalid Configuration parameter 'chargeSumSelection' = " << chargeSumSelection_string << " !!\n";

  bool use_HIP_mitigation_mediumMuonId = cfg_analyze.getParameter<bool>("use_HIP_mitigation_mediumMuonId");
  std::cout << "use_HIP_mitigation_mediumMuonId = " << use_HIP_mitigation_mediumMuonId << std::endl;

  bool apply_lepton_and_hadTauCharge_cut = cfg_analyze.getParameter<bool>("apply_lepton_and_hadTauCharge_cut");
  std::cout << "apply_lepton_and_hadTauCharge_cut = " << apply_lepton_and_hadTauCharge_cut << std::endl;

  bool isMC = cfg_analyze.getParameter<bool>("isMC");
  bool isMC_tH = ( process_string == "tH" ) ? true : false;
  std::string central_or_shift = cfg_analyze.getParameter<std::string>("central_or_shift");
  double lumiScale = ( process_string != "data_obs" ) ? cfg_analyze.getParameter<double>("lumiScale") : 1.;
  bool apply_genWeight = cfg_analyze.getParameter<bool>("apply_genWeight");
  bool apply_trigger_bits = cfg_analyze.getParameter<bool>("apply_trigger_bits");
  
  bool isDEBUG = ( cfg_analyze.exists("isDEBUG") ) ? cfg_analyze.getParameter<bool>("isDEBUG") : false;
  if ( isDEBUG ) std::cout << "Warning: DEBUG mode enabled -> trigger selection will not be applied for data !!" << std::endl;

  std::string jet_btagWeight_branch;
  if ( isMC ) {
    if ( era == kEra_2017 ) jet_btagWeight_branch = "Jet_btagSF_csvv2";
    else assert(0);
  }

  int jetPt_option = RecoJetReader::kJetPt_central;
  int met_option = RecoMEtReader::kMEt_central;
  int hadTauPt_option = RecoHadTauReader::kHadTauPt_central;
  int lheScale_option = kLHE_scale_central;
  if ( central_or_shift != "central" ) {
    TString central_or_shift_tstring = central_or_shift.data();
    std::string shiftUp_or_Down = "";
    if      ( central_or_shift_tstring.EndsWith("Up")   ) shiftUp_or_Down = "Up";
    else if ( central_or_shift_tstring.EndsWith("Down") ) shiftUp_or_Down = "Down";
    else throw cms::Exception("analyze_hadTopTagger_gen")
      << "Invalid Configuration parameter 'central_or_shift' = " << central_or_shift << " !!\n";
    if ( central_or_shift_tstring.BeginsWith("CMS_ttHl_btag") ) {
      if ( isMC ) jet_btagWeight_branch = getBranchName_bTagWeight(era, central_or_shift);
      else throw cms::Exception("analyze_hadTopTagger_gen")
	<< "Configuration parameter 'central_or_shift' = " << central_or_shift << " not supported for data !!\n";
    } else if ( central_or_shift_tstring.BeginsWith("CMS_ttHl_JES") ) {
      if ( isMC ) {
	jet_btagWeight_branch = getBranchName_bTagWeight(era, central_or_shift);
	if      ( shiftUp_or_Down == "Up"   ) {
	  jetPt_option = RecoJetReader::kJetPt_jecUp;
	  met_option = RecoMEtReader::kMEt_shifted_JetEnUp;
	} else if ( shiftUp_or_Down == "Down" ) {
	  jetPt_option = RecoJetReader::kJetPt_jecDown;
	  met_option = RecoMEtReader::kMEt_shifted_JetEnDown;
	} else assert(0);
      } else throw cms::Exception("analyze_hadTopTagger_gen")
	  << "Configuration parameter 'central_or_shift' = " << central_or_shift << " not supported for data !!\n";
    } else if ( central_or_shift_tstring.BeginsWith("CMS_ttHl_JER") ) {
      if ( central_or_shift_tstring.EndsWith("Up") ) met_option = RecoMEtReader::kMEt_shifted_JetResUp;
      else if ( central_or_shift_tstring.EndsWith("Down") ) met_option = RecoMEtReader::kMEt_shifted_JetResDown;
      else assert(0);
    } else if ( central_or_shift_tstring.BeginsWith("CMS_ttHl_UnclusteredEn") ) {
      if ( central_or_shift_tstring.EndsWith("Up") ) met_option = RecoMEtReader::kMEt_shifted_UnclusteredEnUp;
      else if ( central_or_shift_tstring.EndsWith("Down") ) met_option = RecoMEtReader::kMEt_shifted_UnclusteredEnDown;
      else assert(0);
    } else if ( central_or_shift_tstring.BeginsWith("CMS_ttHl_tauES") ) {
      if ( isMC ) {
	if      ( shiftUp_or_Down == "Up"   ) hadTauPt_option = RecoHadTauReader::kHadTauPt_shiftUp;
	else if ( shiftUp_or_Down == "Down" ) hadTauPt_option = RecoHadTauReader::kHadTauPt_shiftDown;
	else assert(0);
      } else throw cms::Exception("analyze_hadTopTagger_gen")
	  << "Configuration parameter 'central_or_shift' = " << central_or_shift << " not supported for data !!\n";
    } else if ( central_or_shift_tstring.BeginsWith("CMS_ttHl_thu_shape") ) {
      if ( isMC ) {
	if      ( central_or_shift_tstring.EndsWith("x1Down") ) lheScale_option = kLHE_scale_xDown;
	else if ( central_or_shift_tstring.EndsWith("x1Up")   ) lheScale_option = kLHE_scale_xUp;
	else if ( central_or_shift_tstring.EndsWith("y1Down") ) lheScale_option = kLHE_scale_yDown;
	else if ( central_or_shift_tstring.EndsWith("y1Up")   ) lheScale_option = kLHE_scale_yUp;
	else assert(0);
      } else throw cms::Exception("analyze_hadTopTagger_gen")
	  << "Configuration parameter 'central_or_shift' = " << central_or_shift << " not supported for data !!\n";
    } else if ( !(central_or_shift_tstring.BeginsWith("CMS_ttHl_FRet") ||
		  central_or_shift_tstring.BeginsWith("CMS_ttHl_FRmt")) ) {
      throw cms::Exception("analyze_hadTopTagger_gen")
	<< "Invalid Configuration parameter 'central_or_shift' = " << central_or_shift << " !!\n";
    }
  }

  edm::ParameterSet cfg_dataToMCcorrectionInterface;
  cfg_dataToMCcorrectionInterface.addParameter<std::string>("era", era_string);
  cfg_dataToMCcorrectionInterface.addParameter<std::string>("hadTauSelection", hadTauSelection_part2);
  cfg_dataToMCcorrectionInterface.addParameter<int>("hadTauSelection_antiElectron", hadTauSelection_antiElectron);
  cfg_dataToMCcorrectionInterface.addParameter<int>("hadTauSelection_antiMuon", hadTauSelection_antiMuon);
  cfg_dataToMCcorrectionInterface.addParameter<std::string>("central_or_shift", central_or_shift);
  Data_to_MC_CorrectionInterface* dataToMCcorrectionInterface = new Data_to_MC_CorrectionInterface(cfg_dataToMCcorrectionInterface);

  std::string branchName_electrons = cfg_analyze.getParameter<std::string>("branchName_electrons");
  std::string branchName_muons = cfg_analyze.getParameter<std::string>("branchName_muons");
  std::string branchName_hadTaus = cfg_analyze.getParameter<std::string>("branchName_hadTaus");
  std::string branchName_jets = cfg_analyze.getParameter<std::string>("branchName_jets");
  std::string branchName_jetsHTTv2 = cfg_analyze.getParameter<std::string>("branchName_jetsHTTv2");
  std::string branchName_subjetsHTTv2 = cfg_analyze.getParameter<std::string>("branchName_subjetsHTTv2");
  std::string branchName_jetsAK12 = cfg_analyze.getParameter<std::string>("branchName_jetsAK12");
  std::string branchName_subjetsAK12 = cfg_analyze.getParameter<std::string>("branchName_subjetsAK12");
  std::string branchName_met = cfg_analyze.getParameter<std::string>("branchName_met");

  std::string branchName_genLeptons1 = cfg_analyze.getParameter<std::string>("branchName_genLeptons1");
  std::string branchName_genLeptons2 = cfg_analyze.getParameter<std::string>("branchName_genLeptons2");
  std::string branchName_genHadTaus = cfg_analyze.getParameter<std::string>("branchName_genHadTaus");
  std::string branchName_genJets = cfg_analyze.getParameter<std::string>("branchName_genJets");

  std::string branchName_genTopQuarks = cfg_analyze.getParameter<std::string>("branchName_genTopQuarks");
  std::string branchName_genBJets = cfg_analyze.getParameter<std::string>("branchName_genBJets");
  std::string branchName_genWBosons = cfg_analyze.getParameter<std::string>("branchName_genWBosons");
  std::string branchName_genWJets = cfg_analyze.getParameter<std::string>("branchName_genWJets");

  bool redoGenMatching = cfg_analyze.getParameter<bool>("redoGenMatching");

  fwlite::InputSource inputFiles(cfg);
  int maxEvents = inputFiles.maxEvents();
  std::cout << " maxEvents = " << maxEvents << std::endl;
  unsigned reportEvery = inputFiles.reportAfter();

  fwlite::OutputFiles outputFile(cfg);
  fwlite::TFileService fs = fwlite::TFileService(outputFile.file().data());

  TTreeWrapper * inputTree = new TTreeWrapper(treeName.data(), inputFiles.files(), maxEvents);

  std::cout << "Loaded " << inputTree -> getFileCount() << " file(s).\n";

//--- declare event-level variables
  EventInfo eventInfo(isSignal, isMC, isMC_tH);
  EventInfoReader eventInfoReader(&eventInfo);
  inputTree -> registerReader(&eventInfoReader);

  for ( const std::vector<hltPath*> hltPaths: { triggers_1e, triggers_2e, triggers_1mu, triggers_2mu, triggers_1e1mu } ) {
    inputTree -> registerReader(hltPaths);
  }

//--- declare particle collections
  const bool readGenObjects = isMC && !redoGenMatching;
  RecoMuonReader* muonReader = new RecoMuonReader(era, branchName_muons, readGenObjects);
  inputTree -> registerReader(muonReader);
  RecoMuonCollectionGenMatcher muonGenMatcher;
  RecoMuonCollectionSelectorLoose preselMuonSelector(era);
  RecoMuonCollectionSelectorFakeable fakeableMuonSelector(era);
  RecoMuonCollectionSelectorTight tightMuonSelector(era);

  RecoElectronReader* electronReader = new RecoElectronReader(era, branchName_electrons, readGenObjects);
  inputTree -> registerReader(electronReader);
  RecoElectronCollectionGenMatcher electronGenMatcher;
  RecoElectronCollectionCleaner electronCleaner(0.3);
  RecoElectronCollectionSelectorLoose preselElectronSelector(era);
  RecoElectronCollectionSelectorFakeable fakeableElectronSelector(era);
  RecoElectronCollectionSelectorTight tightElectronSelector(era);

  RecoHadTauReader* hadTauReader = new RecoHadTauReader(era, branchName_hadTaus, readGenObjects);
  hadTauReader->setHadTauPt_central_or_shift(hadTauPt_option);
  inputTree -> registerReader(hadTauReader);
  RecoHadTauCollectionGenMatcher hadTauGenMatcher;
  RecoHadTauCollectionCleaner hadTauCleaner(0.3);
  RecoHadTauCollectionSelectorLoose preselHadTauSelector(era);
  if ( hadTauSelection_part2 == "dR03mvaVLoose" || hadTauSelection_part2 == "dR03mvaVVLoose" ) preselHadTauSelector.set(hadTauSelection_part2);
  preselHadTauSelector.set_min_antiElectron(hadTauSelection_antiElectron);
  preselHadTauSelector.set_min_antiMuon(hadTauSelection_antiMuon);
  RecoHadTauCollectionSelectorFakeable fakeableHadTauSelector(era);
  if ( hadTauSelection_part2 == "dR03mvaVLoose" || hadTauSelection_part2 == "dR03mvaVVLoose" ) fakeableHadTauSelector.set(hadTauSelection_part2);
  fakeableHadTauSelector.set_min_antiElectron(hadTauSelection_antiElectron);
  fakeableHadTauSelector.set_min_antiMuon(hadTauSelection_antiMuon);
  RecoHadTauCollectionSelectorTight tightHadTauSelector(era);
  if ( hadTauSelection_part2 != "" ) tightHadTauSelector.set(hadTauSelection_part2);
  tightHadTauSelector.set_min_antiElectron(hadTauSelection_antiElectron);
  tightHadTauSelector.set_min_antiMuon(hadTauSelection_antiMuon);
  RecoHadTauSelectorTight tightHadTauFilter(era);
  tightHadTauFilter.set("dR03mvaMedium");
  tightHadTauFilter.set_min_antiElectron(hadTauSelection_antiElectron);
  tightHadTauFilter.set_min_antiMuon(hadTauSelection_antiMuon);

  RecoJetReader* jetReader = new RecoJetReader(era, isMC, branchName_jets, readGenObjects);
  jetReader->setJetPt_central_or_shift(jetPt_option);
  jetReader->setBranchName_BtagWeight(jet_btagWeight_branch);
  inputTree -> registerReader(jetReader);
  RecoJetCollectionGenMatcher jetGenMatcher;
  RecoJetCollectionCleaner jetCleaner(0.4);
  RecoJetCollectionSelector jetSelector(era);
  RecoJetCollectionSelectorBtagLoose jetSelectorBtagLoose(era);
  RecoJetCollectionSelectorBtagMedium jetSelectorBtagMedium(era);

  RecoJetReaderHTTv2* jetReaderHTTv2 = new RecoJetReaderHTTv2(era, branchName_jetsHTTv2, branchName_subjetsHTTv2);
  inputTree -> registerReader(jetReaderHTTv2);

  RecoJetReaderAK12* jetReaderAK12 = new RecoJetReaderAK12(era, branchName_jetsAK12, branchName_subjetsAK12);
  inputTree -> registerReader(jetReaderAK12);

//--- declare missing transverse energy
  RecoMEtReader* metReader = new RecoMEtReader(era, isMC, branchName_met);
  metReader->setMEt_central_or_shift(met_option);
  inputTree -> registerReader(metReader);

//--- declare generator level information
  GenLeptonReader* genLeptonReader = 0;
  GenHadTauReader* genHadTauReader = 0;
  GenJetReader* genJetReader = 0;
  LHEInfoReader* lheInfoReader = 0;
  if ( isMC ) {
    if ( !readGenObjects ) {
      if ( branchName_genLeptons1 != "" || branchName_genLeptons2 != "" ) {
        //genLeptonReader = new GenLeptonReader(branchName_genLeptons1, branchName_genLeptons2);
	genLeptonReader = new GenLeptonReader(branchName_genLeptons1);
        inputTree -> registerReader(genLeptonReader);
      }
      if ( branchName_genHadTaus != "" ) {
        genHadTauReader = new GenHadTauReader(branchName_genHadTaus);
        inputTree -> registerReader(genHadTauReader);
      }
      if ( branchName_genJets != "" ) {
        genJetReader = new GenJetReader(branchName_genJets);
        inputTree -> registerReader(genJetReader);
      }
    }
    lheInfoReader = new LHEInfoReader();
    inputTree -> registerReader(lheInfoReader);
  }

  GenParticleReader* genTopQuarkReader = new GenParticleReader(branchName_genTopQuarks);
  GenParticleReader* genBJetReader = new GenParticleReader(branchName_genBJets);
  GenParticleReader* genWBosonReader = new GenParticleReader(branchName_genWBosons);
  GenParticleReader* genWJetReader = new GenParticleReader(branchName_genWJets);

  if ( isMC ) {
    inputTree->registerReader(genTopQuarkReader);
    inputTree->registerReader(genBJetReader);
    inputTree->registerReader(genWBosonReader);
    inputTree->registerReader(genWJetReader);
  }

  int analyzedEntries = 0;
  int selectedEntries = 0;
  double selectedEntries_weighted = 0.;
  TH1* histogram_analyzedEntries = fs.make<TH1D>("analyzedEntries", "analyzedEntries", 1, -0.5, +0.5);
  TH1* histogram_selectedEntries = fs.make<TH1D>("selectedEntries", "selectedEntries", 1, -0.5, +0.5);
  cutFlowTableType cutFlowTable_2lss_1tau;
  cutFlowTableType cutFlowTable_2lss_1tau_HTTv2;
  cutFlowTableType cutFlowTable_2lss_1tau_AK12;
  cutFlowTableType cutFlowTable_2lss_1tau_resolved;

  TH1* histogram_ptTop = fs.make<TH1D>("ptTop", "ptTop", 100, 0., 500.);
  TH1* histogram_etaTop = fs.make<TH1D>("etaTop", "etaTop", 100, -5.0, +5.0);
  TH1* histogram_dRmaxTop = fs.make<TH1D>("dRmaxTop", "dRmaxTop", 200, -0.01, 9.99);
  TH1* histogram_ptW = fs.make<TH1D>("ptW", "ptW", 100, 0., 500.);
  TH1* histogram_etaW = fs.make<TH1D>("etaW", "etaW", 100, -5.0, +5.0);
  TH1* histogram_dRmaxW = fs.make<TH1D>("dRmaxW", "dRmaxW", 200, -0.01, 9.99);
  TH1* histogram_dRmaxW_dRmaxTopGt1p2 = fs.make<TH1D>("dRmaxW_dRmaxTopGt1p2", "dRmaxW_dRmaxTopGt1p2", 200, -0.01, 9.99);
  TH1* histogram_dRmaxW_dRmaxTopGt1p5 = fs.make<TH1D>("dRmaxW_dRmaxTopGt1p5", "dRmaxW_dRmaxTopGt1p5", 200, -0.01, 9.99);
  TH1* histogram_ptB = fs.make<TH1D>("ptB", "ptB", 100, 0., 500.);
  TH1* histogram_etaB = fs.make<TH1D>("etaB", "etaB", 100, -5.0, +5.0);

  JetHistManagerHTTv2* histManager_jetsHTTv2 = new JetHistManagerHTTv2(makeHistManager_cfg(process_string,
    Form("%s/sel/jetsHTTv2", histogramDir.data()), central_or_shift));
  histManager_jetsHTTv2->bookHistograms(fs);
  TH1* histogram_HTTv2_W_ptRec_div_ptGen = fs.make<TH1D>("HTTv2_W_ptRec_div_ptGen", "HTTv2_W_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_HTTv2_mW = fs.make<TH1D>("HTTv2_mW", "HTTv2_mW", 200, 0., 200.);
  TH1* histogram_HTTv2_Top_ptRec_div_ptGen = fs.make<TH1D>("HTTv2_Top_ptRec_div_ptGen", "HTTv2_Top_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_HTTv2_mTop = fs.make<TH1D>("HTTv2_mTop", "HTTv2_mTop", 300, 0., 300.);
  TH1* histogram_HTTv2_WJet1_ptRec_div_ptGen = fs.make<TH1D>("HTTv2_WJet1_ptRec_div_ptGen", "HTTv2_WJet1_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_HTTv2_WJet1_dRmatch = fs.make<TH1D>("HTTv2_WJet1_dRmatch", "HTTv2_WJet1_dRmatch", 100, 0., 1.);
  TH1* histogram_HTTv2_WJet2_ptRec_div_ptGen = fs.make<TH1D>("HTTv2_WJet2_ptRec_div_ptGen", "HTTv2_WJet2_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_HTTv2_WJet2_dRmatch = fs.make<TH1D>("HTTv2_WJet2_dRmatch", "HTTv2_WJet2_dRmatch", 100, 0., 1.);
  TH1* histogram_HTTv2_BJet_ptRec_div_ptGen = fs.make<TH1D>("HTTv2_BJet_ptRec_div_ptGen", "HTTv2_BJet_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_HTTv2_BJet_dRmatch = fs.make<TH1D>("HTTv2_BJet_dRmatch", "HTTv2_BJet_dRmatch", 100, 0., 1.);
  
  JetHistManagerAK12* histManager_jetsAK12 = new JetHistManagerAK12(makeHistManager_cfg(process_string,
    Form("%s/sel/jetsAK12", histogramDir.data()), central_or_shift));
  histManager_jetsAK12->bookHistograms(fs);
  JetHistManagerAK12* histManager_jetsAK12_notHTTv2 = new JetHistManagerAK12(makeHistManager_cfg(process_string,
    Form("%s/sel/jetsAK12_notHTTv2", histogramDir.data()), central_or_shift));
  histManager_jetsAK12_notHTTv2->bookHistograms(fs);
  TH1* histogram_AK12_W_ptRec_div_ptGen = fs.make<TH1D>("AK12_W_ptRec_div_ptGen", "AK12_W_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_AK12_mW = fs.make<TH1D>("AK12_mW", "AK12_mW", 200, 0., 200.);
  TH1* histogram_AK12_WJet1_ptRec_div_ptGen = fs.make<TH1D>("AK12_WJet1_ptRec_div_ptGen", "AK12_WJet1_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_AK12_WJet1_dRmatch = fs.make<TH1D>("AK12_WJet1_dRmatch", "AK12_WJet1_dRmatch", 100, 0., 1.);
  TH1* histogram_AK12_WJet2_ptRec_div_ptGen = fs.make<TH1D>("AK12_WJet2_ptRec_div_ptGen", "AK12_WJet2_ptRec_div_ptGen", 200, 0., 2.);
  TH1* histogram_AK12_WJet2_dRmatch = fs.make<TH1D>("AK12_WJet2_dRmatch", "AK12_WJet2_dRmatch", 100, 0., 1.);
  
  while ( inputTree -> hasNextEvent() )
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

    bool isTriggered_1e = hltPaths_isTriggered(triggers_1e) || (isMC && !apply_trigger_bits);
    bool isTriggered_2e = hltPaths_isTriggered(triggers_2e) || (isMC && !apply_trigger_bits);
    bool isTriggered_1mu = hltPaths_isTriggered(triggers_1mu) || (isMC && !apply_trigger_bits);
    bool isTriggered_2mu = hltPaths_isTriggered(triggers_2mu) || (isMC && !apply_trigger_bits);
    bool isTriggered_1e1mu = hltPaths_isTriggered(triggers_1e1mu) || (isMC && !apply_trigger_bits);

    bool selTrigger_1e = use_triggers_1e && isTriggered_1e;
    bool selTrigger_2e = use_triggers_2e && isTriggered_2e;
    bool selTrigger_1mu = use_triggers_1mu && isTriggered_1mu;
    bool selTrigger_2mu = use_triggers_2mu && isTriggered_2mu;
    bool selTrigger_1e1mu = use_triggers_1e1mu && isTriggered_1e1mu;
    if ( !(selTrigger_1e || selTrigger_2e || selTrigger_1mu || selTrigger_2mu || selTrigger_1e1mu) ) {
      continue;
    }

//--- rank triggers by priority and ignore triggers of lower priority if a trigger of higher priority has fired for given event;
//    the ranking of the triggers is as follows: 2mu, 1e1mu, 2e, 1mu, 1e
// CV: this logic is necessary to avoid that the same event is selected multiple times when processing different primary datasets
    if ( !isMC && !isDEBUG ) {
      if ( selTrigger_1e && (isTriggered_2e || isTriggered_1mu || isTriggered_2mu || isTriggered_1e1mu) ) {
	continue;
      }
      if ( selTrigger_2e && (isTriggered_2mu || isTriggered_1e1mu) ) {
	continue;
      }
      if ( selTrigger_1mu && (isTriggered_2e || isTriggered_2mu || isTriggered_1e1mu) ) {
	continue;
      }
      if ( selTrigger_1e1mu && isTriggered_2mu ) {
	continue;
      }
    }
    cutFlowTable_2lss_1tau.update("trigger");

    if ( (selTrigger_2mu   && !apply_offline_e_trigger_cuts_2mu)   ||
	 (selTrigger_1mu   && !apply_offline_e_trigger_cuts_1mu)   ||
	 (selTrigger_2e    && !apply_offline_e_trigger_cuts_2e)    ||
	 (selTrigger_1e1mu && !apply_offline_e_trigger_cuts_1e1mu) ||
	 (selTrigger_1e    && !apply_offline_e_trigger_cuts_1e)    ) {
      fakeableElectronSelector.disable_offline_e_trigger_cuts();
      tightElectronSelector.disable_offline_e_trigger_cuts();
    } else {
      fakeableElectronSelector.enable_offline_e_trigger_cuts();
      tightElectronSelector.enable_offline_e_trigger_cuts();
    }

//--- build collections of electrons, muons and hadronic taus;
//    resolve overlaps in order of priority: muon, electron,
    std::vector<RecoMuon> muons = muonReader->read();
    std::vector<const RecoMuon*> muon_ptrs = convert_to_ptrs(muons);
    std::vector<const RecoMuon*> cleanedMuons = muon_ptrs; // CV: no cleaning needed for muons, as they have the highest priority in the overlap removal
    std::vector<const RecoMuon*> preselMuons = preselMuonSelector(cleanedMuons);
    std::vector<const RecoMuon*> fakeableMuons = fakeableMuonSelector(preselMuons);
    std::vector<const RecoMuon*> tightMuons = tightMuonSelector(preselMuons);
    std::vector<const RecoMuon*> selMuons;
    if      ( leptonSelection == kLoose    ) selMuons = preselMuons;
    else if ( leptonSelection == kFakeable ) selMuons = fakeableMuons;
    else if ( leptonSelection == kTight    ) selMuons = tightMuons;
    else assert(0);
    if ( isDEBUG ) {
      for ( size_t idxPreselMuon = 0; idxPreselMuon < preselMuons.size(); ++idxPreselMuon ) {
        std::cout << "preselMuon #" << idxPreselMuon << ":" << std::endl;
        std::cout << (*preselMuons[idxPreselMuon]);
      }
      for ( size_t idxSelMuon = 0; idxSelMuon < selMuons.size(); ++idxSelMuon ) {
        std::cout << "selMuon #" << idxSelMuon << ":" << std::endl;
        std::cout << (*selMuons[idxSelMuon]);
      }
    }

    std::vector<RecoElectron> electrons = electronReader->read();
    std::vector<const RecoElectron*> electron_ptrs = convert_to_ptrs(electrons);
    std::vector<const RecoElectron*> cleanedElectrons = electronCleaner(electron_ptrs, selMuons);
    std::vector<const RecoElectron*> preselElectrons = preselElectronSelector(cleanedElectrons);
    std::vector<const RecoElectron*> fakeableElectrons = fakeableElectronSelector(preselElectrons);
    std::vector<const RecoElectron*> tightElectrons = tightElectronSelector(preselElectrons);
    std::vector<const RecoElectron*> selElectrons;
    if      ( leptonSelection == kLoose    ) selElectrons = preselElectrons;
    else if ( leptonSelection == kFakeable ) selElectrons = fakeableElectrons;
    else if ( leptonSelection == kTight    ) selElectrons = tightElectrons;
    else assert(0);
    if ( isDEBUG ) {
      for ( size_t idxPreselElectron = 0; idxPreselElectron < preselElectrons.size(); ++idxPreselElectron ) {
        std::cout << "preselElectron #" << idxPreselElectron << ":" << std::endl;
        std::cout << (*preselElectrons[idxPreselElectron]);
      }
      for ( size_t idxSelElectron = 0; idxSelElectron < selElectrons.size(); ++idxSelElectron ) {
        std::cout << "selElectron #" << idxSelElectron << ":" << std::endl;
        std::cout << (*selElectrons[idxSelElectron]);
      }
    }

    std::vector<const RecoLepton*> selLeptons;
    selLeptons.reserve(selElectrons.size() + selMuons.size());
    selLeptons.insert(selLeptons.end(), selElectrons.begin(), selElectrons.end());
    selLeptons.insert(selLeptons.end(), selMuons.begin(), selMuons.end());
    std::sort(selLeptons.begin(), selLeptons.end(), isHigherPt);
    std::vector<RecoHadTau> hadTaus = hadTauReader->read();
    std::vector<const RecoHadTau*> hadTau_ptrs = convert_to_ptrs(hadTaus);
    std::vector<const RecoHadTau*> cleanedHadTaus = hadTauCleaner(hadTau_ptrs, preselMuons, preselElectrons);
    std::vector<const RecoHadTau*> preselHadTaus = preselHadTauSelector(cleanedHadTaus);
    std::vector<const RecoHadTau*> fakeableHadTaus = fakeableHadTauSelector(cleanedHadTaus);
    std::vector<const RecoHadTau*> tightHadTaus = tightHadTauSelector(cleanedHadTaus);
    std::vector<const RecoHadTau*> selHadTaus;
    if      ( hadTauSelection == kLoose    ) selHadTaus = preselHadTaus;
    else if ( hadTauSelection == kFakeable ) selHadTaus = fakeableHadTaus;
    else if ( hadTauSelection == kTight    ) selHadTaus = tightHadTaus;
    else assert(0);
    if ( isDEBUG ) {
      for ( size_t idxPreselHadTau = 0; idxPreselHadTau < preselHadTaus.size(); ++idxPreselHadTau ) {
        std::cout << "preselHadTau #" << idxPreselHadTau << ":" << std::endl;
        std::cout << (*preselHadTaus[idxPreselHadTau]);
      }
      for ( size_t idxSelHadTau = 0; idxSelHadTau < selHadTaus.size(); ++idxSelHadTau ) {
        std::cout << "selHadTau #" << idxSelHadTau << ":" << std::endl;
        std::cout << (*selHadTaus[idxSelHadTau]);
      }
    }
    selHadTaus = pickFirstNobjects(selHadTaus, 1);

//--- build collections of jets and select subset of jets passing b-tagging criteria
    std::vector<RecoJet> jets = jetReader->read();
    std::vector<const RecoJet*> jet_ptrs = convert_to_ptrs(jets);
    std::vector<const RecoJet*> cleanedJets = jetCleaner(jet_ptrs, selHadTaus, selLeptons, fakeableElectrons, fakeableMuons);
    //std::vector<const RecoJet*> cleanedJets = jetCleaner(jet_ptrs, selLeptons, fakeableElectrons, fakeableMuons);
    //std::vector<const RecoJet*> cleanedJets = jetCleaner(jet_ptrs, selLeptons);
    // selLeptons for BDT training is loose, and loose>fakeable
    // this has no effect on datacards making as there selLeptons are tight and tight<fakeable
    std::vector<const RecoJet*> selJets = jetSelector(cleanedJets);
    std::vector<const RecoJet*> selBJets_loose = jetSelectorBtagLoose(cleanedJets);
    std::vector<const RecoJet*> selBJets_medium = jetSelectorBtagMedium(cleanedJets);

//--- build collections of jets reconstructed by hep-top-tagger (HTTv2) algorithm
    std::vector<RecoJetHTTv2> jetsHTTv2 = jetReaderHTTv2->read();
    std::vector<const RecoJetHTTv2*> jet_ptrsHTTv2 = convert_to_ptrs(jetsHTTv2);

//--- build collections of jets reconstructed by anti-kT algorithm with dR=1.2 (AK12)
    std::vector<RecoJetAK12> jetsAK12 = jetReaderAK12->read();
    std::vector<const RecoJetAK12*> jet_ptrsAK12 = convert_to_ptrs(jetsAK12);

//--- build collections of generator level particles (after some cuts are applied, to safe computing time)
    std::vector<GenLepton> genLeptons;
    std::vector<GenLepton> genElectrons;
    std::vector<GenLepton> genMuons;
    std::vector<GenHadTau> genHadTaus;
    std::vector<GenJet> genJets;
    if ( isMC && redoGenMatching ) {
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
      electronGenMatcher.addGenJetMatch(preselElectrons, genJets, 0.2);

      hadTauGenMatcher.addGenLeptonMatch(selHadTaus, genLeptons, 0.2);
      hadTauGenMatcher.addGenHadTauMatch(selHadTaus, genHadTaus, 0.2);
      hadTauGenMatcher.addGenJetMatch(selHadTaus, genJets, 0.2);

      jetGenMatcher.addGenLeptonMatch(selJets, genLeptons, 0.2);
      jetGenMatcher.addGenHadTauMatch(selJets, genHadTaus, 0.2);
      jetGenMatcher.addGenJetMatch(selJets, genJets, 0.2);
    }

//--- apply preselection
    std::vector<const RecoLepton*> preselLeptons;
    preselLeptons.reserve(preselElectrons.size() + preselMuons.size());
    preselLeptons.insert(preselLeptons.end(), preselElectrons.begin(), preselElectrons.end());
    preselLeptons.insert(preselLeptons.end(), preselMuons.begin(), preselMuons.end());
    std::sort(preselLeptons.begin(), preselLeptons.end(), isHigherConePt);
    // require at least two leptons passing loose preselection criteria
    if ( !(preselLeptons.size() >= 2) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(">= 2 presel leptons");
    const RecoLepton* preselLepton_lead = preselLeptons[0];
    const RecoLepton* preselLepton_sublead = preselLeptons[1];
    const leptonGenMatchEntry& preselLepton_genMatch = getLeptonGenMatch(leptonGenMatch_definitions, preselLepton_lead, preselLepton_sublead);
    int idxPreselLepton_genMatch = preselLepton_genMatch.idx_;
    if ( apply_leptonGenMatching_ttZ_workaround ) idxPreselLepton_genMatch = kGen_2l0j;
    assert(idxPreselLepton_genMatch != kGen_LeptonUndefined2);

    // require that trigger paths match event category (with event category based on preselLeptons)
    if ( !((preselElectrons.size() >= 2 &&                            (selTrigger_2e    || selTrigger_1e                  )) ||
	   (preselElectrons.size() >= 1 && preselMuons.size() >= 1 && (selTrigger_1e1mu || selTrigger_1mu || selTrigger_1e)) ||
	   (                               preselMuons.size() >= 2 && (selTrigger_2mu   || selTrigger_1mu                 ))) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("presel lepton trigger match");

    // apply requirement on jets (incl. b-tagged jets) and hadronic taus on preselection level
    if ( !(selJets.size() >= 2) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(">= 2 jets");
    if ( !(selBJets_loose.size() >= 2 || selBJets_medium.size() >= 1) ) {
    }
    cutFlowTable_2lss_1tau.update(">= 2 loose b-jets || 1 medium b-jet (1)");

    if ( !(selHadTaus.size() >= 1) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(">= 1 sel tau (1)");
    const RecoHadTau* selHadTau = selHadTaus[0];
    const hadTauGenMatchEntry& selHadTau_genMatch = getHadTauGenMatch(hadTauGenMatch_definitions, selHadTau);
    int idxSelHadTau_genMatch = selHadTau_genMatch.idx_;
    assert(idxSelHadTau_genMatch != kGen_HadTauUndefined1);

//--- compute MHT and linear MET discriminant (met_LD)
    RecoMEt met = metReader->read();
    std::vector<const RecoLepton*> fakeableLeptons = mergeLeptonCollections(fakeableElectrons, fakeableMuons);
    Particle::LorentzVector mht_p4 = compMHT(fakeableLeptons, selHadTaus, selJets);
    double met_LD = compMEt_LD(met.p4(), mht_p4);

//--- apply final event selection
    if ( !(selLeptons.size() >= 2) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(">= 2 sel leptons", 1.);
    const RecoLepton* selLepton_lead = selLeptons[0];
    int selLepton_lead_type = getLeptonType(selLepton_lead->pdgId());
    const RecoLepton* selLepton_sublead = selLeptons[1];
    int selLepton_sublead_type = getLeptonType(selLepton_sublead->pdgId());
    const leptonGenMatchEntry& selLepton_genMatch = getLeptonGenMatch(leptonGenMatch_definitions, selLepton_lead, selLepton_sublead);
    int idxSelLepton_genMatch = selLepton_genMatch.idx_;
    if ( apply_leptonGenMatching_ttZ_workaround ) idxSelLepton_genMatch = kGen_2l0j;
    assert(idxSelLepton_genMatch != kGen_LeptonUndefined2);

    if ( isMC ) {
      lheInfoReader->read();
    }

//--- compute event-level weight for data/MC correction of b-tagging efficiency and mistag rate
//   (using the method "Event reweighting using scale factors calculated with a tag and probe method",
//    described on the BTV POG twiki https://twiki.cern.ch/twiki/bin/view/CMS/BTagShapeCalibration )
    double evtWeight = 1.;
    if ( isMC ) {
      evtWeight *= lumiScale;
      if ( apply_genWeight ) evtWeight *= boost::math::sign(eventInfo.genWeight);
      if ( isMC_tH ) evtWeight *= eventInfo.genWeight_tH;
      evtWeight *= eventInfo.pileupWeight;
      if ( lheScale_option != kLHE_scale_central ) {
	if      ( lheScale_option == kLHE_scale_xDown ) evtWeight *= lheInfoReader->getWeight_scale_xDown();
	else if ( lheScale_option == kLHE_scale_xUp   ) evtWeight *= lheInfoReader->getWeight_scale_xUp();
	else if ( lheScale_option == kLHE_scale_yDown ) evtWeight *= lheInfoReader->getWeight_scale_yDown();
	else if ( lheScale_option == kLHE_scale_yUp   ) evtWeight *= lheInfoReader->getWeight_scale_yUp();
      }
      double btagWeight = 1.;
      for ( std::vector<const RecoJet*>::const_iterator jet = selJets.begin();
	    jet != selJets.end(); ++jet ) {
	btagWeight *= (*jet)->BtagWeight();
      }
      evtWeight *= btagWeight;
    }

    double weight_data_to_MC_correction = 1.;
    double triggerWeight = 1.;
    if ( isMC ) {
      dataToMCcorrectionInterface->setLeptons(
        selLepton_lead_type, selLepton_lead->pt(), selLepton_lead->eta(),
	selLepton_sublead_type, selLepton_sublead->pt(), selLepton_sublead->eta());

//--- apply trigger efficiency turn-on curves to Spring16 non-reHLT MC
      if ( !apply_trigger_bits ) {
	triggerWeight = dataToMCcorrectionInterface->getWeight_leptonTriggerEff();
	evtWeight *= triggerWeight;
      }

//--- apply data/MC corrections for trigger efficiency
      double sf_triggerEff = dataToMCcorrectionInterface->getSF_leptonTriggerEff();
      triggerWeight *= sf_triggerEff;
      weight_data_to_MC_correction *= sf_triggerEff;

//--- apply data/MC corrections for efficiencies for lepton to pass loose identification and isolation criteria
      weight_data_to_MC_correction *= dataToMCcorrectionInterface->getSF_leptonID_and_Iso_loose();

//--- apply data/MC corrections for efficiencies of leptons passing the loose identification and isolation criteria
//    to also pass the tight identification and isolation criteria
      if ( leptonSelection == kFakeable ) {
	weight_data_to_MC_correction = dataToMCcorrectionInterface->getSF_leptonID_and_Iso_fakeable_to_loose();
      } else if ( leptonSelection == kTight ) {
        weight_data_to_MC_correction = dataToMCcorrectionInterface->getSF_leptonID_and_Iso_tight_to_loose_wTightCharge();
      }

//--- apply data/MC corrections for hadronic tau identification efficiency
//    and for e->tau and mu->tau misidentification rates
      int selHadTau_genPdgId = getHadTau_genPdgId(selHadTau);
      dataToMCcorrectionInterface->setHadTaus(selHadTau_genPdgId, selHadTau->pt(), selHadTau->eta());
      weight_data_to_MC_correction *= dataToMCcorrectionInterface->getSF_hadTauID_and_Iso();
      weight_data_to_MC_correction *= dataToMCcorrectionInterface->getSF_eToTauFakeRate();
      weight_data_to_MC_correction *= dataToMCcorrectionInterface->getSF_muToTauFakeRate();

      evtWeight *= weight_data_to_MC_correction;
    }

    // require exactly two leptons passing tight selection criteria, to avoid overlap with other channels
    std::vector<const RecoLepton*> tightLeptons;
    tightLeptons.reserve(tightElectrons.size() + tightMuons.size());
    tightLeptons.insert(tightLeptons.end(), tightElectrons.begin(), tightElectrons.end());
    tightLeptons.insert(tightLeptons.end(), tightMuons.begin(), tightMuons.end());
    std::sort(tightLeptons.begin(), tightLeptons.end(), isHigherPt);
    if ( !(tightLeptons.size() <= 2) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("<= 2 tight leptons", evtWeight);
    
    // require that trigger paths match event category (with event category based on selLeptons)
    if ( !((selElectrons.size() >= 2 &&                         (selTrigger_2e    || selTrigger_1e                  )) ||
	   (selElectrons.size() >= 1 && selMuons.size() >= 1 && (selTrigger_1e1mu || selTrigger_1mu || selTrigger_1e)) ||
	   (                            selMuons.size() >= 2 && (selTrigger_2mu   || selTrigger_1mu                 ))) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("sel lepton trigger match", evtWeight);

    // apply requirement on jets (incl. b-tagged jets) and hadronic taus on level of final event selection
    if ( !(selJets.size() >= 3) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(">= 3 jets", evtWeight);

    if ( !(selBJets_loose.size() >= 2 || selBJets_medium.size() >= 1) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(">= 2 loose b-jets || 1 medium b-jet (2)", evtWeight);

    if ( !(selHadTaus.size() >= 1) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(">= 1 sel tau (2)", evtWeight);

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
      continue;
    }
    cutFlowTable_2lss_1tau.update("m(ll) > 12 GeV", evtWeight);

    double minPt_lead = -1.;
    if ( era == kEra_2017 ) minPt_lead = 25.; // CV: increase minimum lepton pT cut to 25 GeV to keep-up with higher trigger thresholds in 2016 data
    else assert(0);
    double minPt_sublead = selLepton_sublead->is_electron() ? 15. : 10.;
    if ( !(selLepton_lead->pt() > minPt_lead && selLepton_sublead->pt() > minPt_sublead) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("lead lepton pT > 25 GeV && sublead lepton pT > 15(e)/10(mu) GeV", evtWeight);

    bool failsTightChargeCut = false;
    for ( std::vector<const RecoLepton*>::const_iterator lepton = selLeptons.begin();
	  lepton != selLeptons.end(); ++lepton ) {
      if ( (*lepton)->is_electron() ) {
	const RecoElectron* electron = dynamic_cast<const RecoElectron*>(*lepton);
	assert(electron);
	if ( electron->tightCharge() < 2 ) failsTightChargeCut = true;
      }
      if ( (*lepton)->is_muon() ) {
	const RecoMuon* muon = dynamic_cast<const RecoMuon*>(*lepton);
	assert(muon);
	if ( muon->tightCharge() < 2 ) failsTightChargeCut = true;
      }
    }
    if ( failsTightChargeCut ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("tight lepton charge", evtWeight);

    bool isLeptonCharge_SS = selLepton_lead->charge()*selLepton_sublead->charge() > 0;
    bool isLeptonCharge_OS = selLepton_lead->charge()*selLepton_sublead->charge() < 0;
    if ( leptonChargeSelection == kOS && isLeptonCharge_SS ) {
      continue;
    }
    if ( leptonChargeSelection == kSS && isLeptonCharge_OS ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update(Form("sel lepton-pair %s charge", leptonChargeSelection_string.data()), evtWeight);

    if ( apply_lepton_and_hadTauCharge_cut ) {
      if ( !((chargeSumSelection == kOS && std::abs(selLepton_lead->charge() + selLepton_sublead->charge() + selHadTau->charge()) == 1) ||
	     (chargeSumSelection == kSS && std::abs(selLepton_lead->charge() + selLepton_sublead->charge() + selHadTau->charge()) != 1)) ) {
	continue;
      }
      cutFlowTable_2lss_1tau.update(Form("sel lepton+tau %s charge", chargeSumSelection_string.data()), evtWeight);
    }

    bool failsZbosonMassVeto = false;
    for ( std::vector<const RecoLepton*>::const_iterator lepton1 = fakeableLeptons.begin();
	  lepton1 != fakeableLeptons.end(); ++lepton1 ) {
      for ( std::vector<const RecoLepton*>::const_iterator lepton2 = lepton1 + 1;
	    lepton2 != fakeableLeptons.end(); ++lepton2 ) {
	double mass = ((*lepton1)->p4() + (*lepton2)->p4()).mass();
	if ( (*lepton1)->is_electron() && (*lepton2)->is_electron() && std::fabs(mass - z_mass) < z_window ) {
	  failsZbosonMassVeto = true;
	}
      }
    }
    if ( failsZbosonMassVeto ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("Z-boson mass veto", evtWeight);

    if ( !(fakeableMuons.size() >= 1 || met_LD >= 0.2) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("met LD > 0.2", evtWeight);

//--- build collections of generator level particles
    std::vector<GenParticle> genTopQuarks = genTopQuarkReader->read();
    std::vector<GenParticle> genBJets = genBJetReader->read();
    std::vector<GenParticle> genWBosons = genWBosonReader->read();
    std::vector<GenParticle> genWJets = genWJetReader->read();

    if ( isDEBUG ) {
      dumpGenParticles("genTopQuark", genTopQuarks);
      dumpGenParticles("genBJet", genBJets);
      dumpGenParticles("genWBoson", genWBosons);
      dumpGenParticles("genWJet", genWJets);
      std::cout << std::endl;
    }

    if ( !(genTopQuarks.size() == 2) ) continue;
    cutFlowTable_2lss_1tau.update("2 genTopQuarks");
    if ( !(genBJets.size() == 2) ) continue;
    cutFlowTable_2lss_1tau.update("2 genBJets");
    if ( !(genWBosons.size() >= 2) ) continue; // CV: do not veto events in which Higgs boson decays into W bosons
    cutFlowTable_2lss_1tau.update(">= 2 genWBosons");
    if ( !(genWJets.size() >= 2) ) continue;
    cutFlowTable_2lss_1tau.update(">= 2 genWJets");

    const GenParticle* genTopQuark = 0;
    const GenParticle* genAntiTopQuark = 0;
    for ( std::vector<GenParticle>::const_iterator it = genTopQuarks.begin();
	  it != genTopQuarks.end(); ++it ) {
      if ( it->pdgId() == +6 && !genTopQuark     ) genTopQuark = &(*it);
      if ( it->pdgId() == -6 && !genAntiTopQuark ) genAntiTopQuark = &(*it);
    }
    if ( !(genTopQuark && genAntiTopQuark) ) continue;
    cutFlowTable_2lss_1tau.update("genTopQuark && genAntiTopQuark");
    
    const GenParticle* genBJetFromTop = 0;
    const GenParticle* genBJetFromAntiTop = 0;
    for ( std::vector<GenParticle>::const_iterator it = genBJets.begin();
	  it != genBJets.end(); ++it ) {
      if ( it->pdgId() == +5 && !genBJetFromTop     ) genBJetFromTop = &(*it);
      if ( it->pdgId() == -5 && !genBJetFromAntiTop ) genBJetFromAntiTop = &(*it);
    }
    if ( !(genBJetFromTop && genBJetFromAntiTop) ) continue;
    cutFlowTable_2lss_1tau.update("genBJetFromTop && genBJetFromAntiTop");
    
    const GenParticle* genWBosonFromTop = 0;
    const GenParticle* genWBosonFromAntiTop = 0;
    for ( std::vector<GenParticle>::const_iterator it = genWBosons.begin();
	  it != genWBosons.end(); ++it ) {
      if ( it->pdgId() == +24 && !genWBosonFromTop     ) genWBosonFromTop = &(*it);
      if ( it->pdgId() == -24 && !genWBosonFromAntiTop ) genWBosonFromAntiTop = &(*it);
    }
    if ( !(genWBosonFromTop && genWBosonFromAntiTop) ) continue;
    cutFlowTable_2lss_1tau.update("genWBosonFromTop && genWBosonFromAntiTop");
    if ( !(std::fabs((genBJetFromTop->p4() + genWBosonFromTop->p4()).mass() - genTopQuark->mass()) < 15.) ) continue;
    cutFlowTable_2lss_1tau.update("genTopQuark mass");
    if ( !(std::fabs((genBJetFromAntiTop->p4() + genWBosonFromAntiTop->p4()).mass() - genAntiTopQuark->mass()) < 15.) ) continue;
    cutFlowTable_2lss_1tau.update("genAntiTopQuark mass");

    std::vector<const GenParticle*> genWJetsFromTop;
    double genWJetsFromTop_mass = -1.;
    std::vector<const GenParticle*> genWJetsFromAntiTop;
    double genWJetsFromAntiTop_mass = -1.;
    for ( std::vector<GenParticle>::const_iterator it1 = genWJets.begin(); it1 != genWJets.end(); ++it1 ) {
      for ( std::vector<GenParticle>::const_iterator it2 = it1 + 1;
	    it2 != genWJets.end(); ++it2 ) {
	if ( ((it1->charge() + it2->charge()) - genWBosonFromTop->charge()) < 1.e-2 ) {
	  if ( genWJetsFromTop_mass == -1. ||
	       std::fabs((it1->p4() + it2->p4()).mass() - genWBosonFromTop->mass()) < std::fabs(genWJetsFromTop_mass - genWBosonFromTop->mass()) ) {
	    genWJetsFromTop.clear();
	    genWJetsFromTop.push_back(&(*it1));
	    genWJetsFromTop.push_back(&(*it2));
	    genWJetsFromTop_mass = (it1->p4() + it2->p4()).mass();
	  }
	}
	if ( ((it1->charge() + it2->charge()) - genWBosonFromAntiTop->charge()) < 1.e-2 ) {
	  if ( genWJetsFromAntiTop_mass == -1. ||
	       std::fabs((it1->p4() + it2->p4()).mass() - genWBosonFromAntiTop->mass()) < std::fabs(genWJetsFromAntiTop_mass - genWBosonFromAntiTop->mass()) ) {
	    genWJetsFromAntiTop.clear();
	    genWJetsFromAntiTop.push_back(&(*it1));
	    genWJetsFromAntiTop.push_back(&(*it2));
	    genWJetsFromAntiTop_mass = (it1->p4() + it2->p4()).mass();
	  }
	}
      }
    }
    if ( !(genWJetsFromTop.size() == 2 || genWJetsFromAntiTop.size() == 2) ) continue;
    cutFlowTable_2lss_1tau.update("2 genWJetsFromTop || 2 genWJetsFromAntiTop");

    const GenParticle* genWJetFromTop_lead = 0;
    const GenParticle* genWJetFromTop_sublead = 0;
    bool failsWbosonMassVeto_top = false;
    if ( genWJetsFromTop.size() == 2 ) {
      std::sort(genWJetsFromTop.begin(), genWJetsFromTop.end(), isHigherPt);
      genWJetFromTop_lead = genWJetsFromTop[0];
      genWJetFromTop_sublead = genWJetsFromTop[1];
      if ( !(std::fabs((genWJetFromTop_lead->p4() + genWJetFromTop_sublead->p4()).mass() - genWBosonFromTop->mass()) < 15.) ) failsWbosonMassVeto_top = true;
    }
    if ( failsWbosonMassVeto_top ) continue;
    cutFlowTable_2lss_1tau.update("genWBosonFromTop mass");

    const GenParticle* genWJetFromAntiTop_lead = 0;
    const GenParticle* genWJetFromAntiTop_sublead = 0;
    bool failsWbosonMassVeto_antiTop = false;
    if ( genWJetsFromAntiTop.size() == 2 ) {
      std::sort(genWJetsFromAntiTop.begin(), genWJetsFromAntiTop.end(), isHigherPt);
      genWJetFromAntiTop_lead = genWJetsFromAntiTop[0];
      genWJetFromAntiTop_sublead = genWJetsFromAntiTop[1];
      if ( !(std::fabs((genWJetFromAntiTop_lead->p4() + genWJetFromAntiTop_sublead->p4()).mass() - genWBosonFromAntiTop->mass()) < 15.) ) failsWbosonMassVeto_antiTop = true;
    }
    if ( failsWbosonMassVeto_antiTop ) continue;
    cutFlowTable_2lss_1tau.update("genWBosonFromAntiTop mass");

    if ( isDEBUG ) {
      std::cout << "top:" << (*genTopQuark);
      std::cout << " b:" << (*genBJetFromTop);
      std::cout << " W:" << (*genWBosonFromTop);
      if ( genWJetFromTop_lead && genWJetFromTop_sublead ) {
	std::cout << " Wj1:" << (*genWJetFromTop_lead);
	std::cout << " Wj2:" << (*genWJetFromTop_sublead);
      } else {
	std::cout << "(leptonic W decay)" << std::endl;
      }
      std::cout << "anti-top:" << (*genAntiTopQuark);
      std::cout << " b:" << (*genBJetFromAntiTop);
      std::cout << " W:" << (*genWBosonFromAntiTop);
      if ( genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead ) {
	std::cout << " Wj1:" << (*genWJetFromAntiTop_lead);
	std::cout << " Wj2:" << (*genWJetFromAntiTop_sublead);
      } else {
	std::cout << "(leptonic W decay)" << std::endl;
      }
      std::cout << std::endl;
    }

    if ( !((genBJetFromTop             && 
	    genWJetFromTop_lead        && 
	    genWJetFromTop_sublead    ) ||
	   (genBJetFromAntiTop         && 
	    genWJetFromAntiTop_lead    && 
	    genWJetFromAntiTop_sublead)) ) {
      continue;
    }
    cutFlowTable_2lss_1tau.update("genJet triplet");

    Particle::LorentzVector genWBosonFromTopP4;
    if ( genWJetFromTop_lead && genWJetFromTop_sublead ) {
      genWBosonFromTopP4 = genWJetFromTop_lead->p4() + genWJetFromTop_sublead->p4();
    }
    Particle::LorentzVector genWBosonFromAntiTopP4;
    if ( genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead ) {
      genWBosonFromAntiTopP4 = genWJetFromAntiTop_lead->p4() + genWJetFromAntiTop_sublead->p4();
    }

    Particle::LorentzVector genTopP4;
    if ( genBJetFromTop && genWJetFromTop_lead && genWJetFromTop_sublead ) {
      genTopP4 = genBJetFromTop->p4() + genWJetFromTop_lead->p4() + genWJetFromTop_sublead->p4();
    }
    Particle::LorentzVector genAntiTopP4;
    if ( genBJetFromAntiTop && genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead ) {
      genAntiTopP4 = genBJetFromAntiTop->p4() + genWJetFromAntiTop_lead->p4() + genWJetFromAntiTop_sublead->p4();
    }

    //-------------------------------------------------------------------------------------------------------------------
    // case 1: all three jets contained within dR=1.5 "fat" jet, 
    //         reconstructed by hep-top-tagger (HTTv2) algorithm

    cutFlowTable_2lss_1tau_HTTv2.update("genJet triplet");

    bool isHTTv2FromTop = false;
    bool isHTTv2FromAntiTop = false;

    if ( (genBJetFromTop     && genWJetFromTop_lead     && genWJetFromTop_sublead     && genTopP4.pt()     > 200.) ||
	 (genBJetFromAntiTop && genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead && genAntiTopP4.pt() > 200.) ) {
      cutFlowTable_2lss_1tau_HTTv2.update("genTop passes pT > 200 GeV");
      
      if ( (genBJetFromTop             && genBJetFromTop->absEta()          < 5.0 && 
	    genWJetFromTop_lead        && genWJetFromTop_lead->absEta()     < 5.0 &&
	    genWJetFromTop_sublead     && genWJetFromTop_lead->absEta()     < 5.0) ||
	   (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()      < 5.0 && 
	    genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->absEta() < 5.0 &&
	    genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->absEta() < 5.0) ) {
	cutFlowTable_2lss_1tau_HTTv2.update("genJet triplet passes abs(eta) < 5.0");
	
	if ( (genBJetFromTop             && genBJetFromTop->absEta()      < 2.4) ||
	     (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()  < 2.4) ) {
	  cutFlowTable_2lss_1tau_HTTv2.update("genBJet passes abs(eta) < 2.4");
	  
	  if ( (genBJetFromTop             && genBJetFromTop->absEta()          < 2.4 && 
		genWJetFromTop_lead        && genWJetFromTop_lead->absEta()     < 2.4 &&
		genWJetFromTop_sublead     && genWJetFromTop_lead->absEta()     < 2.4) ||
	       (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()      < 2.4 && 
		genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->absEta() < 2.4 &&
		genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->absEta() < 2.4) ) {
	    cutFlowTable_2lss_1tau_HTTv2.update("genJet triplet passes abs(eta) < 2.4");
	    
	    if ( (genBJetFromTop && genWJetFromTop_lead && genWJetFromTop_sublead             && 
		  deltaR(genTopP4, genBJetFromTop->p4())                                < 1.5 && 
		  deltaR(genTopP4, genWJetFromTop_lead->p4())                           < 1.5 && 
		  deltaR(genTopP4, genWJetFromTop_sublead->p4())                        < 1.5) ||
		 (genBJetFromAntiTop && genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead && 
		  deltaR(genAntiTopP4, genBJetFromAntiTop->p4())                        < 1.5 && 
		  deltaR(genAntiTopP4, genWJetFromAntiTop_lead->p4())                   < 1.5 && 
		  deltaR(genAntiTopP4, genWJetFromAntiTop_sublead->p4())                < 1.5) ) {
	      cutFlowTable_2lss_1tau_HTTv2.update("dR(genBJet, genWJet1, genWJet2) < 1.5");

	      const RecoJetHTTv2* recTop = 0;
	      const RecoJetHTTv2* recAntiTop = 0;
	      for ( std::vector<const RecoJetHTTv2*>::const_iterator jetHTTv2 = jet_ptrsHTTv2.begin();
		    jetHTTv2 != jet_ptrsHTTv2.end(); ++jetHTTv2 ) {
		if ( genBJetFromTop && genWJetFromTop_lead && genWJetFromTop_sublead && deltaR((*jetHTTv2)->p4(), genTopP4) < 0.75 ) {
		  recTop = (*jetHTTv2);
		  histManager_jetsHTTv2->fillHistograms({ recTop }, evtWeight);
		}
		if ( genBJetFromAntiTop && genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead && deltaR((*jetHTTv2)->p4(), genAntiTopP4) < 0.75 ) {
		  recAntiTop = (*jetHTTv2);
		  histManager_jetsHTTv2->fillHistograms({ recAntiTop }, evtWeight);
		}
	      }

	      if ( recTop && recTop->subJet1() && recTop->subJet2() && recTop->subJet3() ) {		
		const RecoSubjetHTTv2* recBJetFromTop = 0;
		const RecoSubjetHTTv2* recWJetFromTop_lead = 0;
		const RecoSubjetHTTv2* recWJetFromTop_sublead = 0;
		double dR_b_1 = deltaR(genBJetFromTop->p4(), recTop->subJet1()->p4());
		double dR_b_2 = deltaR(genBJetFromTop->p4(), recTop->subJet2()->p4());
		double dR_b_3 = deltaR(genBJetFromTop->p4(), recTop->subJet3()->p4());
		double dR_lead_1 = deltaR(genWJetFromTop_lead->p4(), recTop->subJet1()->p4());
		double dR_lead_2 = deltaR(genWJetFromTop_lead->p4(), recTop->subJet2()->p4());
		double dR_lead_3 = deltaR(genWJetFromTop_lead->p4(), recTop->subJet3()->p4());
		double dR_sublead_1 = deltaR(genWJetFromTop_sublead->p4(), recTop->subJet1()->p4());
		double dR_sublead_2 = deltaR(genWJetFromTop_sublead->p4(), recTop->subJet2()->p4());
		double dR_sublead_3 = deltaR(genWJetFromTop_sublead->p4(), recTop->subJet3()->p4());
		double dR2min = 1.e+3;
		if ( (square(dR_b_1) + square(dR_lead_2) + square(dR_sublead_3)) < dR2min ) {
		  if ( dR_b_1 < 0.1 && dR_lead_2 < 0.1 && dR_sublead_3 < 0.1 ) {
		    recBJetFromTop         = recTop->subJet1();
		    recWJetFromTop_lead    = recTop->subJet2();
		    recWJetFromTop_sublead = recTop->subJet3();
		    dR2min = (square(dR_b_1) + square(dR_lead_2) + square(dR_sublead_3));
		  }
		}
		if ( (square(dR_b_1) + square(dR_lead_3) + square(dR_sublead_2)) < dR2min ) {
		  if ( dR_b_1 < 0.1 && dR_lead_3 < 0.1 && dR_sublead_2 < 0.1 ) {
		    recBJetFromTop         = recTop->subJet1();
		    recWJetFromTop_lead    = recTop->subJet3();
		    recWJetFromTop_sublead = recTop->subJet2();
		    dR2min = (square(dR_b_1) + square(dR_lead_3) + square(dR_sublead_2));
		  }
		}
		if ( (square(dR_b_2) + square(dR_lead_1) + square(dR_sublead_3)) < dR2min ) {
		  if ( dR_b_2 < 0.1 && dR_lead_1 < 0.1 && dR_sublead_3 < 0.1 ) {
		    recBJetFromTop         = recTop->subJet2();
		    recWJetFromTop_lead    = recTop->subJet1();
		    recWJetFromTop_sublead = recTop->subJet3();
		    dR2min = (square(dR_b_2) + square(dR_lead_1) + square(dR_sublead_3));
		  }
		}
		if ( (square(dR_b_2) + square(dR_lead_3) + square(dR_sublead_1)) < dR2min ) {
		  if ( dR_b_2 < 0.1 && dR_lead_3 < 0.1 && dR_sublead_1 < 0.1 ) {
		    recBJetFromTop         = recTop->subJet2();
		    recWJetFromTop_lead    = recTop->subJet3();
		    recWJetFromTop_sublead = recTop->subJet1();
		    dR2min = (square(dR_b_2) + square(dR_lead_3) + square(dR_sublead_1));
		  }
		}
		if ( (square(dR_b_3) + square(dR_lead_1) + square(dR_sublead_2)) < dR2min ) {
		  if ( dR_b_3 < 0.1 && dR_lead_1 < 0.1 && dR_sublead_2 < 0.1 ) {
		    recBJetFromTop         = recTop->subJet3();
		    recWJetFromTop_lead    = recTop->subJet1();
		    recWJetFromTop_sublead = recTop->subJet2();
		    dR2min = (square(dR_b_3) + square(dR_lead_1) + square(dR_sublead_2));
		  }
		}
		if ( (square(dR_b_3) + square(dR_lead_2) + square(dR_sublead_1)) < dR2min ) {
		  if ( dR_b_3 < 0.1 && dR_lead_2 < 0.1 && dR_sublead_1 < 0.1 ) {
		    recBJetFromTop         = recTop->subJet3();
		    recWJetFromTop_lead    = recTop->subJet2();
		    recWJetFromTop_sublead = recTop->subJet1();
		    dR2min = (square(dR_b_3) + square(dR_lead_2) + square(dR_sublead_1));
		  }
		}
                if ( recBJetFromTop && recWJetFromTop_lead && recWJetFromTop_sublead ) {
		  Particle::LorentzVector recWBosonFromTopP4 = recWJetFromTop_lead->p4() + recWJetFromTop_sublead->p4();
		  if ( genWBosonFromTopP4.pt() > 100. ) {
		    fillWithOverFlow(histogram_HTTv2_W_ptRec_div_ptGen, recWBosonFromTopP4.pt()/genWBosonFromTopP4.pt(), evtWeight);
		  }
		  fillWithOverFlow(histogram_HTTv2_mW, recWBosonFromTopP4.mass(), evtWeight);
		  Particle::LorentzVector recTopP4 = recBJetFromTop->p4() + recWBosonFromTopP4;
		  if ( genTopP4.pt() > 200. ) {
		    fillWithOverFlow(histogram_HTTv2_Top_ptRec_div_ptGen, recTopP4.pt()/genTopP4.pt(), evtWeight);
		  }
		  fillWithOverFlow(histogram_HTTv2_mTop, recTopP4.mass(), evtWeight);
		  if ( genWJetFromTop_lead->pt() > 20. ) {
		    fillWithOverFlow(histogram_HTTv2_WJet1_ptRec_div_ptGen, recWJetFromTop_lead->pt()/genWJetFromTop_lead->pt(), evtWeight);
		    fillWithOverFlow(histogram_HTTv2_WJet1_dRmatch, deltaR(recWJetFromTop_lead->p4(), genWJetFromTop_lead->p4()), evtWeight);
		  }
		  if ( genWJetFromTop_sublead->pt() > 20. ) {
		    fillWithOverFlow(histogram_HTTv2_WJet2_ptRec_div_ptGen, recWJetFromTop_sublead->pt()/genWJetFromTop_sublead->pt(), evtWeight);
		    fillWithOverFlow(histogram_HTTv2_WJet2_dRmatch, deltaR(recWJetFromTop_sublead->p4(), genWJetFromTop_sublead->p4()), evtWeight);
		  }
		  if ( genBJetFromTop->pt() > 20. ) {
		    fillWithOverFlow(histogram_HTTv2_BJet_ptRec_div_ptGen, recBJetFromTop->pt()/genBJetFromTop->pt(), evtWeight);
		    fillWithOverFlow(histogram_HTTv2_BJet_dRmatch, deltaR(recBJetFromTop->p4(), genBJetFromTop->p4()), evtWeight);
		  }
		  isHTTv2FromTop = true;
		}
	      }

	      if ( recAntiTop && recAntiTop->subJet1() && recAntiTop->subJet2() && recAntiTop->subJet3() ) {		
		const RecoSubjetHTTv2* recBJetFromAntiTop = 0;
		const RecoSubjetHTTv2* recWJetFromAntiTop_lead = 0;
		const RecoSubjetHTTv2* recWJetFromAntiTop_sublead = 0;
		double dR_b_1 = deltaR(genBJetFromAntiTop->p4(), recAntiTop->subJet1()->p4());
		double dR_b_2 = deltaR(genBJetFromAntiTop->p4(), recAntiTop->subJet2()->p4());
		double dR_b_3 = deltaR(genBJetFromAntiTop->p4(), recAntiTop->subJet3()->p4());
		double dR_lead_1 = deltaR(genWJetFromAntiTop_lead->p4(), recAntiTop->subJet1()->p4());
		double dR_lead_2 = deltaR(genWJetFromAntiTop_lead->p4(), recAntiTop->subJet2()->p4());
		double dR_lead_3 = deltaR(genWJetFromAntiTop_lead->p4(), recAntiTop->subJet3()->p4());
		double dR_sublead_1 = deltaR(genWJetFromAntiTop_sublead->p4(), recAntiTop->subJet1()->p4());
		double dR_sublead_2 = deltaR(genWJetFromAntiTop_sublead->p4(), recAntiTop->subJet2()->p4());
		double dR_sublead_3 = deltaR(genWJetFromAntiTop_sublead->p4(), recAntiTop->subJet3()->p4());
		double dR2min = 1.e+3;
		if ( (square(dR_b_1) + square(dR_lead_2) + square(dR_sublead_3)) < dR2min ) {
		  if ( dR_b_1 < 0.1 && dR_lead_2 < 0.1 && dR_sublead_3 < 0.1 ) {
		    recBJetFromAntiTop         = recAntiTop->subJet1();
		    recWJetFromAntiTop_lead    = recAntiTop->subJet2();
		    recWJetFromAntiTop_sublead = recAntiTop->subJet3();
		    dR2min = (square(dR_b_1) + square(dR_lead_2) + square(dR_sublead_3));
		  }
		}
		if ( (square(dR_b_1) + square(dR_lead_3) + square(dR_sublead_2)) < dR2min ) {
		  if ( dR_b_1 < 0.1 && dR_lead_3 < 0.1 && dR_sublead_2 < 0.1 ) {
		    recBJetFromAntiTop         = recAntiTop->subJet1();
		    recWJetFromAntiTop_lead    = recAntiTop->subJet3();
		    recWJetFromAntiTop_sublead = recAntiTop->subJet2();
		    dR2min = (square(dR_b_1) + square(dR_lead_3) + square(dR_sublead_2));
		  }
		}
		if ( (square(dR_b_2) + square(dR_lead_1) + square(dR_sublead_3)) < dR2min ) {
		  if ( dR_b_2 < 0.1 && dR_lead_1 < 0.1 && dR_sublead_3 < 0.1 ) {
		    recBJetFromAntiTop         = recAntiTop->subJet2();
		    recWJetFromAntiTop_lead    = recAntiTop->subJet1();
		    recWJetFromAntiTop_sublead = recAntiTop->subJet3();
		    dR2min = (square(dR_b_2) + square(dR_lead_1) + square(dR_sublead_3));
		  }
		}
		if ( (square(dR_b_2) + square(dR_lead_3) + square(dR_sublead_1)) < dR2min ) {
		  if ( dR_b_2 < 0.1 && dR_lead_3 < 0.1 && dR_sublead_1 < 0.1 ) {
		    recBJetFromAntiTop         = recAntiTop->subJet2();
		    recWJetFromAntiTop_lead    = recAntiTop->subJet3();
		    recWJetFromAntiTop_sublead = recAntiTop->subJet1();
		    dR2min = (square(dR_b_2) + square(dR_lead_3) + square(dR_sublead_1));
		  }
		}
		if ( (square(dR_b_3) + square(dR_lead_1) + square(dR_sublead_2)) < dR2min ) {
		  if ( dR_b_3 < 0.1 && dR_lead_1 < 0.1 && dR_sublead_2 < 0.1 ) {
		    recBJetFromAntiTop         = recAntiTop->subJet3();
		    recWJetFromAntiTop_lead    = recAntiTop->subJet1();
		    recWJetFromAntiTop_sublead = recAntiTop->subJet2();
		    dR2min = (square(dR_b_3) + square(dR_lead_1) + square(dR_sublead_2));
		  }
		}
		if ( (square(dR_b_3) + square(dR_lead_2) + square(dR_sublead_1)) < dR2min ) {
		  if ( dR_b_3 < 0.1 && dR_lead_2 < 0.1 && dR_sublead_1 < 0.1 ) {
		    recBJetFromAntiTop         = recAntiTop->subJet3();
		    recWJetFromAntiTop_lead    = recAntiTop->subJet2();
		    recWJetFromAntiTop_sublead = recAntiTop->subJet1();
		    dR2min = (square(dR_b_3) + square(dR_lead_2) + square(dR_sublead_1));
		  }
		}
                if ( recBJetFromAntiTop && recWJetFromAntiTop_lead && recWJetFromAntiTop_sublead ) {
		  Particle::LorentzVector recWBosonFromAntiTopP4 = recWJetFromAntiTop_lead->p4() + recWJetFromAntiTop_sublead->p4();
		  if ( genWBosonFromAntiTopP4.pt() > 100. ) {
		    fillWithOverFlow(histogram_HTTv2_W_ptRec_div_ptGen, recWBosonFromAntiTopP4.pt()/genWBosonFromAntiTopP4.pt(), evtWeight);
		  }
		  fillWithOverFlow(histogram_HTTv2_mW, recWBosonFromAntiTopP4.mass(), evtWeight);
		  Particle::LorentzVector recAntiTopP4 = recBJetFromAntiTop->p4() + recWBosonFromAntiTopP4;
		  if ( genAntiTopP4.pt() > 200. ) {
		    fillWithOverFlow(histogram_HTTv2_Top_ptRec_div_ptGen, recAntiTopP4.pt()/genAntiTopP4.pt(), evtWeight);
		  }
		  fillWithOverFlow(histogram_HTTv2_mTop, recAntiTopP4.mass(), evtWeight);
		  if ( genWJetFromAntiTop_lead->pt() > 20. ) {
		    fillWithOverFlow(histogram_HTTv2_WJet1_ptRec_div_ptGen, recWJetFromAntiTop_lead->pt()/genWJetFromAntiTop_lead->pt(), evtWeight);
		    fillWithOverFlow(histogram_HTTv2_WJet1_dRmatch, deltaR(recWJetFromAntiTop_lead->p4(), genWJetFromAntiTop_lead->p4()), evtWeight);
		  }
		  if ( genWJetFromAntiTop_sublead->pt() > 20. ) {
		    fillWithOverFlow(histogram_HTTv2_WJet2_ptRec_div_ptGen, recWJetFromAntiTop_sublead->pt()/genWJetFromAntiTop_sublead->pt(), evtWeight);
		    fillWithOverFlow(histogram_HTTv2_WJet2_dRmatch, deltaR(recWJetFromAntiTop_sublead->p4(), genWJetFromAntiTop_sublead->p4()), evtWeight);
		  }
		  if ( genBJetFromAntiTop->pt() > 20. ) {
		    fillWithOverFlow(histogram_HTTv2_BJet_ptRec_div_ptGen, recBJetFromAntiTop->pt()/genBJetFromAntiTop->pt(), evtWeight);
		    fillWithOverFlow(histogram_HTTv2_BJet_dRmatch, deltaR(recBJetFromAntiTop->p4(), genBJetFromAntiTop->p4()), evtWeight);
		  }
		  isHTTv2FromAntiTop = true;
		}
	      }
	    }
	  }
	}
      }
    }
    //-------------------------------------------------------------------------------------------------------------------
    
    //-------------------------------------------------------------------------------------------------------------------
    // case 2: two jets from hadronic W boson decay contained within dR=1.2 "fat" jet, 
    //         reconstructed by by anti-kT algorithm with dR=1.2 (AK12),
    //         while b-jet from top decay is resolved as separate jets, 
    //         reconstructed by anti-kT algorithm with dR=0.4 (AK4)

    cutFlowTable_2lss_1tau_AK12.update("genJet triplet");
    
    if ( (genBJetFromTop                                        && genBJetFromTop->pt()         >  20. && 
	  genWJetFromTop_lead && genWJetFromTop_sublead         && genWBosonFromTopP4.pt()      > 100.) ||
	 (genBJetFromAntiTop                                    && genBJetFromAntiTop->pt()     >  20. && 
	  genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead && genWBosonFromAntiTopP4.pt()  > 100.) ) {
      cutFlowTable_2lss_1tau_AK12.update("genBJet passes pT > 20 GeV && genW passes pT > 100 GeV");

      if ( (genBJetFromTop             && genBJetFromTop->absEta()          < 5.0 && 
	    genWJetFromTop_lead        && genWJetFromTop_lead->absEta()     < 5.0 &&
	    genWJetFromTop_sublead     && genWJetFromTop_lead->absEta()     < 5.0) ||
	   (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()      < 5.0 && 
	    genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->absEta() < 5.0 &&
	    genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->absEta() < 5.0) ) {
	cutFlowTable_2lss_1tau_AK12.update("genJet triplet passes abs(eta) < 5.0");

	if ( (genBJetFromTop             && genBJetFromTop->absEta()      < 2.4) ||
	     (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()  < 2.4) ) {
	  cutFlowTable_2lss_1tau_AK12.update("genBJet passes abs(eta) < 2.4");

	  if ( (genBJetFromTop             && genBJetFromTop->absEta()          < 2.4 && 
		genWJetFromTop_lead        && genWJetFromTop_lead->absEta()     < 2.4 &&
		genWJetFromTop_sublead     && genWJetFromTop_lead->absEta()     < 2.4) ||
	       (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()      < 2.4 && 
		genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->absEta() < 2.4 &&
		genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->absEta() < 2.4) ) {
	    cutFlowTable_2lss_1tau_AK12.update("genJet triplet passes abs(eta) < 2.4");
	   
	    if ( (genWJetFromTop_lead && genWJetFromTop_sublead                          && 
		  deltaR(genWBosonFromTopP4, genWJetFromTop_lead->p4())            < 1.2 && 
		  deltaR(genWBosonFromTopP4, genWJetFromTop_sublead->p4())         < 1.2) ||
		 (genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead                  && 
		  deltaR(genWBosonFromAntiTopP4, genWJetFromAntiTop_lead->p4())    < 1.2 &&
		  deltaR(genWBosonFromAntiTopP4, genWJetFromAntiTop_sublead->p4()) < 1.2) ) {
	      cutFlowTable_2lss_1tau_AK12.update("dR(genWJet1, genWJet2) < 1.2");

	      const RecoJetAK12* recWBosonFromTop = 0;
	      const RecoJetAK12* recWBosonFromAntiTop = 0;
	      for ( std::vector<const RecoJetAK12*>::const_iterator jetAK12 = jet_ptrsAK12.begin();
		    jetAK12 != jet_ptrsAK12.end(); ++jetAK12 ) {
		if ( genWJetFromTop_lead && genWJetFromTop_sublead && deltaR((*jetAK12)->p4(), genWBosonFromTopP4) < 0.6 ) {
		  recWBosonFromTop = (*jetAK12);
		  histManager_jetsAK12->fillHistograms({ recWBosonFromTop }, evtWeight);
		  if ( !isHTTv2FromTop ) {
		    histManager_jetsAK12_notHTTv2->fillHistograms({ recWBosonFromTop }, evtWeight);
		  }
		}
		if ( genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead && deltaR((*jetAK12)->p4(), genWBosonFromAntiTopP4) < 0.6 ) {
		  recWBosonFromAntiTop = (*jetAK12);
		  histManager_jetsAK12->fillHistograms({ recWBosonFromAntiTop }, evtWeight);
		  if ( !isHTTv2FromAntiTop ) {
		    histManager_jetsAK12_notHTTv2->fillHistograms({ recWBosonFromAntiTop }, evtWeight);
		  }
		}
	      }

	      if ( recWBosonFromTop && recWBosonFromTop->subJet1() && recWBosonFromTop->subJet2() ) {		
		const RecoSubjetAK12* recWJetFromTop_lead = 0;
		const RecoSubjetAK12* recWJetFromTop_sublead = 0;
  		double dR_lead_1 = deltaR(genWJetFromTop_lead->p4(), recWBosonFromTop->subJet1()->p4());  
		double dR_lead_2 = deltaR(genWJetFromTop_lead->p4(), recWBosonFromTop->subJet2()->p4());
		double dR_sublead_1 = deltaR(genWJetFromTop_sublead->p4(), recWBosonFromTop->subJet1()->p4());
		double dR_sublead_2 = deltaR(genWJetFromTop_sublead->p4(), recWBosonFromTop->subJet2()->p4());
		if ( (square(dR_lead_1) + square(dR_sublead_2)) < (square(dR_lead_2) + square(dR_sublead_1)) ) {
		  if ( dR_lead_1 < 0.1 && dR_lead_2 < 0.1 ) {
		    recWJetFromTop_lead = recWBosonFromTop->subJet1();
		    recWJetFromTop_sublead = recWBosonFromTop->subJet2();
		  }
		} else {
		  if ( dR_lead_2 < 0.1 && dR_lead_1 < 0.1 ) {
		    recWJetFromTop_lead = recWBosonFromTop->subJet2();
		    recWJetFromTop_sublead = recWBosonFromTop->subJet1();
		  }
		}
                if ( recWJetFromTop_lead && recWJetFromTop_sublead ) {
		  Particle::LorentzVector recWBosonFromTopP4 = recWJetFromTop_lead->p4() + recWJetFromTop_sublead->p4();
                  if ( genWBosonFromTopP4.pt() > 100. ) {
		    fillWithOverFlow(histogram_AK12_W_ptRec_div_ptGen, recWBosonFromTopP4.pt()/genWBosonFromTopP4.pt(), evtWeight);
		  }
		  fillWithOverFlow(histogram_AK12_mW, recWBosonFromTopP4.mass(), evtWeight);
		  if ( genWJetFromTop_lead->pt() > 20. ) {
		    fillWithOverFlow(histogram_AK12_WJet1_ptRec_div_ptGen, recWJetFromTop_lead->pt()/genWJetFromTop_lead->pt(), evtWeight);
		    fillWithOverFlow(histogram_AK12_WJet1_dRmatch, deltaR(recWJetFromTop_lead->p4(), genWJetFromTop_lead->p4()), evtWeight);
		  }
		  if ( genWJetFromTop_sublead->pt() > 20. ) {
		    fillWithOverFlow(histogram_AK12_WJet2_ptRec_div_ptGen, recWJetFromTop_sublead->pt()/genWJetFromTop_sublead->pt(), evtWeight);
		    fillWithOverFlow(histogram_AK12_WJet2_dRmatch, deltaR(recWJetFromTop_sublead->p4(), genWJetFromTop_sublead->p4()), evtWeight);
		  }
		}
	      }

	      if ( recWBosonFromAntiTop && recWBosonFromAntiTop->subJet1() && recWBosonFromAntiTop->subJet2() ) {
		const RecoSubjetAK12* recWJetFromAntiTop_lead = 0;
		const RecoSubjetAK12* recWJetFromAntiTop_sublead = 0;
		double dR_lead_1 = deltaR(genWJetFromAntiTop_lead->p4(), recWBosonFromAntiTop->subJet1()->p4());
		double dR_lead_2 = deltaR(genWJetFromAntiTop_lead->p4(), recWBosonFromAntiTop->subJet2()->p4());
		double dR_sublead_1 = deltaR(genWJetFromAntiTop_sublead->p4(), recWBosonFromAntiTop->subJet1()->p4());
		double dR_sublead_2 = deltaR(genWJetFromAntiTop_sublead->p4(), recWBosonFromAntiTop->subJet2()->p4());
		if ( (square(dR_lead_1) + square(dR_sublead_2)) < (square(dR_lead_2) + square(dR_sublead_1)) ) {
		  if ( dR_lead_1 < 0.1 && dR_lead_2 < 0.1 ) {
		    recWJetFromAntiTop_lead = recWBosonFromAntiTop->subJet1();
		    recWJetFromAntiTop_sublead = recWBosonFromAntiTop->subJet2();
		  }
		} else {
		  if ( dR_lead_2 < 0.1 && dR_lead_1 < 0.1 ) {
		    recWJetFromAntiTop_lead = recWBosonFromAntiTop->subJet2();
		    recWJetFromAntiTop_sublead = recWBosonFromAntiTop->subJet1();
		  }
		}
		if ( recWJetFromAntiTop_lead && recWJetFromAntiTop_sublead ) {
		  Particle::LorentzVector recWBosonFromAntiTopP4 = recWJetFromAntiTop_lead->p4() + recWJetFromAntiTop_sublead->p4();
		  if ( genWBosonFromAntiTopP4.pt() > 100. ) {
		    fillWithOverFlow(histogram_AK12_W_ptRec_div_ptGen, recWBosonFromAntiTopP4.pt()/genWBosonFromAntiTopP4.pt(), evtWeight);
		  }
		  fillWithOverFlow(histogram_AK12_mW, recWBosonFromAntiTopP4.mass(), evtWeight);
		  if ( genWJetFromAntiTop_lead->pt() > 20. ) {
		    fillWithOverFlow(histogram_AK12_WJet1_ptRec_div_ptGen, recWJetFromAntiTop_lead->pt()/genWJetFromAntiTop_lead->pt(), evtWeight);
		    fillWithOverFlow(histogram_AK12_WJet1_dRmatch, deltaR(recWJetFromAntiTop_lead->p4(), genWJetFromAntiTop_lead->p4()), evtWeight);
		  }
		  if ( genWJetFromAntiTop_sublead->pt() > 20. ) {
		    fillWithOverFlow(histogram_AK12_WJet2_ptRec_div_ptGen, recWJetFromAntiTop_sublead->pt()/genWJetFromAntiTop_sublead->pt(), evtWeight);
		    fillWithOverFlow(histogram_AK12_WJet2_dRmatch, deltaR(recWJetFromAntiTop_sublead->p4(), genWJetFromAntiTop_sublead->p4()), evtWeight);
		  }
		}
	      }
	    }
	  }
	}
      }
    }
    //-------------------------------------------------------------------------------------------------------------------

    //-------------------------------------------------------------------------------------------------------------------
    // case 3: all three jets resolved as separate jets, 
    //         reconstructed by anti-kT algorithm with dR=0.4 (AK4)

    cutFlowTable_2lss_1tau_resolved.update("genJet triplet");

    if ( (genBJetFromTop             && genBJetFromTop->pt()          > 20. && 
	  genWJetFromTop_lead        && genWJetFromTop_lead->pt()     > 20. &&
	  genWJetFromTop_sublead     && genWJetFromTop_lead->pt()     > 20.) ||
	 (genBJetFromAntiTop         && genBJetFromAntiTop->pt()      > 20. && 
	  genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->pt() > 20. &&
	  genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->pt() > 20.) ) {
      cutFlowTable_2lss_1tau_resolved.update("genJet triplet passes pT > 20 GeV");

      if ( (genBJetFromTop             && genBJetFromTop->absEta()          < 5.0 && 
	    genWJetFromTop_lead        && genWJetFromTop_lead->absEta()     < 5.0 &&
	    genWJetFromTop_sublead     && genWJetFromTop_lead->absEta()     < 5.0) ||
	   (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()      < 5.0 && 
	    genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->absEta() < 5.0 &&
	    genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->absEta() < 5.0) ) {
	cutFlowTable_2lss_1tau_resolved.update("genJet triplet passes abs(eta) < 5.0");

	if ( (genBJetFromTop             && genBJetFromTop->absEta()      < 2.4) ||
	     (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()  < 2.4) ) {
	  cutFlowTable_2lss_1tau_resolved.update("genBJet passes abs(eta) < 2.4");

	  if ( (genBJetFromTop             && genBJetFromTop->pt()          > 25. && 
		genWJetFromTop_lead        && genWJetFromTop_lead->pt()     > 25. &&
		genWJetFromTop_sublead     && genWJetFromTop_lead->pt()     > 25.) ||
	       (genBJetFromAntiTop         && genBJetFromAntiTop->pt()      > 25. && 
		genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->pt() > 25. &&
		genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->pt() > 25.) ) {
	    cutFlowTable_2lss_1tau_resolved.update("genJet triplet passes pT > 25 GeV");

	    if ( (genBJetFromTop             && genBJetFromTop->absEta()          < 2.4 && 
		  genWJetFromTop_lead        && genWJetFromTop_lead->absEta()     < 2.4 &&
		  genWJetFromTop_sublead     && genWJetFromTop_lead->absEta()     < 2.4) ||
		 (genBJetFromAntiTop         && genBJetFromAntiTop->absEta()      < 2.4 && 
		  genWJetFromAntiTop_lead    && genWJetFromAntiTop_lead->absEta() < 2.4 &&
		  genWJetFromAntiTop_sublead && genWJetFromAntiTop_lead->absEta() < 2.4) ) {
	      cutFlowTable_2lss_1tau_resolved.update("genJet triplet passes abs(eta) < 2.4");

	      if ( genTopQuark && genWBosonFromTop && genBJetFromTop && genWJetFromTop_lead && genWJetFromTop_sublead ) {
		fillWithOverFlow(histogram_ptTop, genTopQuark->pt(), evtWeight);
		fillWithOverFlow(histogram_etaTop, genTopQuark->eta(), evtWeight);
		double dRmaxTop = -1.;
		dRmaxTop = TMath::Max(dRmaxTop, deltaR(genTopQuark->p4(), genBJetFromTop->p4()));
		dRmaxTop = TMath::Max(dRmaxTop, deltaR(genTopQuark->p4(), genWJetFromTop_lead->p4()));
		dRmaxTop = TMath::Max(dRmaxTop, deltaR(genTopQuark->p4(), genWJetFromTop_sublead->p4()));
		fillWithOverFlow(histogram_dRmaxTop, dRmaxTop, evtWeight);
		fillWithOverFlow(histogram_ptW, genWBosonFromTop->pt(), evtWeight);
		fillWithOverFlow(histogram_etaW, genWBosonFromTop->eta(), evtWeight);
		double dRmaxW = -1.;
		dRmaxW = TMath::Max(dRmaxW, deltaR(genWBosonFromTop->p4(), genWJetFromTop_lead->p4()));
		dRmaxW = TMath::Max(dRmaxW, deltaR(genWBosonFromTop->p4(), genWJetFromTop_sublead->p4()));
		fillWithOverFlow(histogram_dRmaxW, dRmaxW, evtWeight);
		if ( dRmaxTop > 1.2 ) fillWithOverFlow(histogram_dRmaxW_dRmaxTopGt1p2, dRmaxW, evtWeight);
		if ( dRmaxTop > 1.5 ) fillWithOverFlow(histogram_dRmaxW_dRmaxTopGt1p5, dRmaxW, evtWeight);
		fillWithOverFlow(histogram_ptB, genBJetFromTop->pt(), evtWeight);
		fillWithOverFlow(histogram_etaB, genBJetFromTop->eta(), evtWeight);
	      }
	      if ( genAntiTopQuark && genWBosonFromAntiTop && genBJetFromAntiTop && genWJetFromAntiTop_lead && genWJetFromAntiTop_sublead ) {
		fillWithOverFlow(histogram_ptTop, genAntiTopQuark->pt(), evtWeight);
		fillWithOverFlow(histogram_etaTop, genAntiTopQuark->eta(), evtWeight);
		double dRmaxAntiTop = -1.;
		dRmaxAntiTop = TMath::Max(dRmaxAntiTop, deltaR(genAntiTopQuark->p4(), genBJetFromAntiTop->p4()));
		dRmaxAntiTop = TMath::Max(dRmaxAntiTop, deltaR(genAntiTopQuark->p4(), genWJetFromAntiTop_lead->p4()));
		dRmaxAntiTop = TMath::Max(dRmaxAntiTop, deltaR(genAntiTopQuark->p4(), genWJetFromAntiTop_sublead->p4()));
		fillWithOverFlow(histogram_dRmaxTop, dRmaxAntiTop, evtWeight);
		fillWithOverFlow(histogram_ptW, genWBosonFromAntiTop->pt(), evtWeight);
		fillWithOverFlow(histogram_etaW, genWBosonFromAntiTop->eta(), evtWeight);
		double dRmaxW = -1.;
		dRmaxW = TMath::Max(dRmaxW, deltaR(genWBosonFromAntiTop->p4(), genWJetFromAntiTop_lead->p4()));
		dRmaxW = TMath::Max(dRmaxW, deltaR(genWBosonFromAntiTop->p4(), genWJetFromAntiTop_sublead->p4()));
		fillWithOverFlow(histogram_dRmaxW, dRmaxW, evtWeight);
		if ( dRmaxAntiTop > 1.2 ) fillWithOverFlow(histogram_dRmaxW_dRmaxTopGt1p2, dRmaxW, evtWeight);
		if ( dRmaxAntiTop > 1.5 ) fillWithOverFlow(histogram_dRmaxW_dRmaxTopGt1p5, dRmaxW, evtWeight);
		fillWithOverFlow(histogram_ptB, genBJetFromAntiTop->pt(), evtWeight);
		fillWithOverFlow(histogram_etaB, genBJetFromAntiTop->eta(), evtWeight);
	      }

	      if ( (genBJetFromTop                                                                && 
		    genWJetFromTop_lead                                                           && 
		    genWJetFromTop_sublead                                                        &&
		    deltaR(genBJetFromTop->p4(),          genWJetFromTop_lead->p4())        > 0.4 && 
		    deltaR(genBJetFromTop->p4(),          genWJetFromTop_sublead->p4())     > 0.4 && 
		    deltaR(genWJetFromTop_lead->p4(),     genWJetFromTop_sublead->p4())     > 0.4) ||
		   (genBJetFromAntiTop                                                            && 
		    genWJetFromAntiTop_lead                                                       && 
		    genWJetFromAntiTop_sublead                                                    &&
		    deltaR(genBJetFromAntiTop->p4(),      genWJetFromAntiTop_lead->p4())    > 0.4 && 
		    deltaR(genBJetFromAntiTop->p4(),      genWJetFromAntiTop_sublead->p4()) > 0.4 && 
		    deltaR(genWJetFromAntiTop_lead->p4(), genWJetFromAntiTop_sublead->p4()) > 0.4) ) {
		cutFlowTable_2lss_1tau_resolved.update("dR(jet1,jet2) > 0.4 for any pair of genJets in triplet");

		const RecoJet* selBJetFromTop = 0;
		double dRmin_selBJetFromTop = 1.e+3;
		const RecoJet* selWJetFromTop_lead = 0;
		double dRmin_selWJetFromTop_lead = 1.e+3;
		const RecoJet* selWJetFromTop_sublead = 0;
		double dRmin_selWJetFromTop_sublead = 1.e+3;
		const RecoJet* selBJetFromAntiTop = 0;
		double dRmin_selBJetFromAntiTop = 1.e+3;
		const RecoJet* selWJetFromAntiTop_lead = 0;
		double dRmin_selWJetFromAntiTop_lead = 1.e+3;
		const RecoJet* selWJetFromAntiTop_sublead = 0;
		double dRmin_selWJetFromAntiTop_sublead = 1.e+3; 
		for ( std::vector<const RecoJet*>::const_iterator selJet = selJets.begin(); selJet != selJets.end(); ++selJet ) {
		  //for ( std::vector<const RecoJet*>::const_iterator selJet = jet_ptrs.begin(); selJet != jet_ptrs.end(); ++selJet ) {
		  //if ( !((*selJet)->pt() > 25. && (*selJet)->absEta() < 2.4) ) continue;
		  if ( genBJetFromTop ) {
		    double dR_selBJetFromTop = deltaR((*selJet)->p4(), genBJetFromTop->p4());
		    if ( dR_selBJetFromTop < 0.3 && dR_selBJetFromTop < dRmin_selBJetFromTop ) {
		      selBJetFromTop = (*selJet);
		      dRmin_selBJetFromTop = dR_selBJetFromTop;
		    }
		  }
		  if ( genWJetFromTop_lead ) {
		    double dR_selWJetFromTop_lead = deltaR((*selJet)->p4(), genWJetFromTop_lead->p4());
		    if ( dR_selWJetFromTop_lead < 0.3 && dR_selWJetFromTop_lead < dRmin_selWJetFromTop_lead ) {
		      selWJetFromTop_lead = (*selJet);
		      dRmin_selWJetFromTop_lead = dR_selWJetFromTop_lead;
		    }
		  }
		  if ( genWJetFromTop_sublead ) {
		    double dR_selWJetFromTop_sublead = deltaR((*selJet)->p4(), genWJetFromTop_sublead->p4());
		    if ( dR_selWJetFromTop_sublead < 0.3 && dR_selWJetFromTop_sublead < dRmin_selWJetFromTop_sublead ) {
		      selWJetFromTop_sublead = (*selJet);
		      dRmin_selWJetFromTop_sublead = dR_selWJetFromTop_sublead;
		    }
		  }
		  if ( genBJetFromAntiTop ) {
		    double dR_selBJetFromAntiTop = deltaR((*selJet)->p4(), genBJetFromAntiTop->p4());
		    if ( dR_selBJetFromAntiTop < 0.3 && dR_selBJetFromAntiTop < dRmin_selBJetFromAntiTop ) {
		      selBJetFromAntiTop = (*selJet);
		      dRmin_selBJetFromAntiTop = dR_selBJetFromAntiTop;
		    }
		  }
		  if ( genWJetFromAntiTop_lead ) {
		    double dR_selWJetFromAntiTop_lead = deltaR((*selJet)->p4(), genWJetFromAntiTop_lead->p4());
		    if ( dR_selWJetFromAntiTop_lead < 0.3 && dR_selWJetFromAntiTop_lead < dRmin_selWJetFromAntiTop_lead ) {
		      selWJetFromAntiTop_lead = (*selJet);
		      dRmin_selWJetFromAntiTop_lead = dR_selWJetFromAntiTop_lead;
		    }
		  }
		  if ( genWJetFromAntiTop_sublead ) {
		    double dR_selWJetFromAntiTop_sublead = deltaR((*selJet)->p4(), genWJetFromAntiTop_sublead->p4());
		    if ( dR_selWJetFromAntiTop_sublead < 0.3 && dR_selWJetFromAntiTop_sublead < dRmin_selWJetFromAntiTop_sublead ) {
		      selWJetFromAntiTop_sublead = (*selJet);
		      dRmin_selWJetFromAntiTop_sublead = dR_selWJetFromAntiTop_sublead;
		    }
		  }
		}
		if ( (selBJetFromTop             && 
		      selWJetFromTop_lead        && 
		      selWJetFromTop_sublead    ) ||
		     (selBJetFromAntiTop         && 
		      selWJetFromAntiTop_lead    && 
		      selWJetFromAntiTop_sublead) ) {
		  continue;
		}
		cutFlowTable_2lss_1tau_resolved.update("selJet triplet");

		if ( (selBJetFromTop                                                                && 
		      selWJetFromTop_lead                                                           && 
		      selWJetFromTop_sublead                                                        &&
		      deltaR(selBJetFromTop->p4(),          selWJetFromTop_lead->p4())        > 0.3 && 
		      deltaR(selBJetFromTop->p4(),          selWJetFromTop_sublead->p4())     > 0.3 && 
		      deltaR(selWJetFromTop_lead->p4(),     selWJetFromTop_sublead->p4())     > 0.3) ||
		     (selBJetFromAntiTop                                                            && 
		      selWJetFromAntiTop_lead                                                       && 
		      selWJetFromAntiTop_sublead                                                    &&
		      deltaR(selBJetFromAntiTop->p4(),      selWJetFromAntiTop_lead->p4())    > 0.3 && 
		      deltaR(selBJetFromAntiTop->p4(),      selWJetFromAntiTop_sublead->p4()) > 0.3 && 
		      deltaR(selWJetFromAntiTop_lead->p4(), selWJetFromAntiTop_sublead->p4()) > 0.3) ) {
		  cutFlowTable_2lss_1tau_resolved.update("dR(jet1,jet2) > 0.3 for any pair of selJets in triplet");

		  bool selBJetFromTop_passesLoose = false;
		  bool selBJetFromAntiTop_passesLoose = false;
		  for ( std::vector<const RecoJet*>::const_iterator selBJet_loose = selBJets_loose.begin();
			selBJet_loose != selBJets_loose.end(); ++selBJet_loose ) {
		    if ( selBJetFromTop && deltaR(selBJetFromTop->p4(), (*selBJet_loose)->p4()) < 0.3 ) {
		      selBJetFromTop_passesLoose = true;
		    }
		    if ( selBJetFromAntiTop && deltaR(selBJetFromAntiTop->p4(), (*selBJet_loose)->p4()) < 0.3 ) {
		      selBJetFromAntiTop_passesLoose = true;
		    }
		  }
		  if ( !(selBJetFromTop_passesLoose || selBJetFromAntiTop_passesLoose) ) {
		    continue;
		  }
		  cutFlowTable_2lss_1tau_resolved.update(">= 1 selBJet passes loose b-tagging working-point");
		}
	      }
	    }
	  }
	}
      }
    }
    //-------------------------------------------------------------------------------------------------------------------

    ++selectedEntries;
    selectedEntries_weighted += evtWeight;
    histogram_selectedEntries->Fill(0.);
  }

  std::cout << "max num. Entries = " << inputTree -> getCumulativeMaxEventCount()
            << " (limited by " << maxEvents << ") processed in "
            << inputTree -> getProcessedFileCount() << " file(s) (out of "
            << inputTree -> getFileCount() << ")\n"
            << " analyzed = " << analyzedEntries << '\n'
            << " selected = " << selectedEntries << " (weighted = " << selectedEntries_weighted << ")\n\n"
            << "cut-flow table" << std::endl;
  cutFlowTable_2lss_1tau.print(std::cout);
  std::cout << "HTTv2:" << std::endl;
  cutFlowTable_2lss_1tau_HTTv2.print(std::cout);
  std::cout << "AK12:" << std::endl;
  cutFlowTable_2lss_1tau_AK12.print(std::cout);
  std::cout << "resolved:" << std::endl;
  cutFlowTable_2lss_1tau_resolved.print(std::cout);
  std::cout << std::endl;

  delete dataToMCcorrectionInterface;

  delete muonReader;
  delete electronReader;
  delete hadTauReader;
  delete jetReader;
  delete metReader;
  delete genLeptonReader;
  delete genHadTauReader;
  delete genJetReader;
  delete lheInfoReader;
/*
  delete hadTopTagger;
 */
  delete inputTree;

  clock.Show("analyze_hadTopTagger_gen");

  return EXIT_SUCCESS;
}