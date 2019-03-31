#ifndef tthAnalysis_HiggsToTauTau_RecoHadTauReader_h
#define tthAnalysis_HiggsToTauTau_RecoHadTauReader_h

#include "tthAnalysis/HiggsToTauTau/interface/ReaderBase.h" // ReaderBase
#include "tthAnalysis/HiggsToTauTau/interface/RecoHadTau.h" // RecoHadTau

#include <map> // std::map<,>

// forward declarations
class TFile;
class TGraphAsymmErrors;
class TFormula;
class TTree;
class GenLeptonReader;
class GenHadTauReader;
class GenJetReader;

class RecoHadTauReader
  : public ReaderBase
{
public:
  RecoHadTauReader(int era,
                   bool readGenMatching = false);
  RecoHadTauReader(int era,
                   const std::string & branchName_obj,
                   bool readGenMatching = false);
  ~RecoHadTauReader();

  void
  setHadTauPt_central_or_shift(int hadTauPt_option);

  void
  set_default_tauID(TauID tauId);

  /**
   * @brief Call tree->SetBranchAddress for all RecoHadTau branches
   */
  void
  setBranchAddresses(TTree * tree) override;

  /**
   * @brief Read branches from tree and use information to fill collection of RecoHadTau objects
   * @return Collection of RecoHadTau objects
   */
  std::vector<RecoHadTau>
  read() const;

protected:

  /**
   * @brief Initialize names of branches to be read from tree
   */
  void
  setBranchNames();

  int era_;
  const int max_nHadTaus_;
  std::string branchName_num_;
  std::string branchName_obj_;

  /**
   * @brief Read branches containing information on matching of RecoHadTau objects
   *        to generator level electrons, muons, hadronic taus, and jets from tree
   *        and add this information to collection of RecoHadTau objects given as function argument
   */
  void
  readGenMatching(std::vector<RecoHadTau> & hadTaus) const;

  GenLeptonReader * genLeptonReader_;
  GenHadTauReader * genHadTauReader_;
  GenJetReader * genJetReader_;
  bool readGenMatching_;

  std::string branchName_pt_;
  std::string branchName_eta_;
  std::string branchName_phi_;
  std::string branchName_mass_;
  std::string branchName_charge_;
  std::string branchName_dxy_;
  std::string branchName_dz_;
  std::string branchName_decayMode_;
  std::string branchName_idDecayMode_;
  std::string branchName_idDecayModeNewDMs_;
  std::string branchName_idAgainstElec_;
  std::string branchName_idAgainstMu_;
  std::string branchName_filterBits_;
  std::string branchName_jetIdx_;
  std::string branchName_genMatchIdx_;

  std::map<TauID, std::string> branchNames_idMVA_;
  std::map<TauID, std::string> branchNames_rawMVA_;

  TauID tauID_;
  int hadTauPt_option_;

  UInt_t nHadTaus_;
  Float_t * hadTau_pt_;
  Float_t * hadTau_eta_;
  Float_t * hadTau_phi_;
  Float_t * hadTau_mass_;
  Int_t * hadTau_charge_;
  Float_t * hadTau_dxy_;
  Float_t * hadTau_dz_;
  Int_t * hadTau_decayMode_;
  Bool_t * hadTau_idDecayMode_;
  Bool_t * hadTau_idDecayModeNewDMs_;
  Int_t * hadTau_idAgainstElec_;
  Int_t * hadTau_idAgainstMu_;
  UInt_t * hadTau_filterBits_;
  Int_t * hadTau_jetIdx_;
  Int_t * hadTau_genMatchIdx_;

  std::map<TauID, Int_t *> hadTau_idMVAs_;
  std::map<TauID, Float_t *> hadTau_rawMVAs_;

  // CV: make sure that only one RecoHadronicTauReader instance exists for a given branchName,
  //     as ROOT cannot handle multiple TTree::SetBranchAddress calls for the same branch.
  static std::map<std::string, int> numInstances_;
  static std::map<std::string, RecoHadTauReader *> instances_;
};

#endif // tthAnalysis_HiggsToTauTau_RecoHadTauReader_h

