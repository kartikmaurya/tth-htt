#ifndef NTUPLEFILLERMEM_H
#define NTUPLEFILLERMEM_H

#include "tthAnalysis/HiggsToTauTau/interface/NtupleFillerUnits.h"
#include "tthAnalysis/HiggsToTauTau/interface/RecoJet.h"
#include "tthAnalysis/HiggsToTauTau/interface/RecoLepton.h"

#include <TFile.h>
#include <TTree.h>

#include <boost/math/special_functions/sign.hpp> // boost::math::sign()

#include <vector> // std::vector<>
#include <array> // std::array<>
#include <algorithm> // std::sort(), std::find(), std::remove_if()

#define NTUPLE_ERR_OK                                       0ull
#define NTUPLE_ERR_LESS_THAN_2_JETS                         1ull << 0
#define NTUPLE_ERR_LESS_THAN_3_LEPTONS                      1ull << 1
#define NTUPLE_ERR_NO_HAD_TAU                               1ull << 2
#define NTUPLE_ERR_LESS_THAN_2_GEN_BQUARKS                  1ull << 3
#define NTUPLE_ERR_NO_GEN_LEPT_FROM_TAU                     1ull << 4
#define NTUPLE_ERR_NO_GEN_HAD_TAU                           1ull << 5
#define NTUPLE_ERR_LESS_THAN_3_GEN_NUS_FROM_TAU             1ull << 6
#define NTUPLE_ERR_LESS_THAN_2_GEN_TAUS                     1ull << 7
#define NTUPLE_ERR_LESS_THAN_2_GEN_LEP_FROM_TOP             1ull << 8
#define NTUPLE_ERR_LESS_THAN_2_GEN_NU_FROM_TOP              1ull << 9
#define NTUPLE_ERR_NO_GEN_POS_BQUARKS                       1ull << 10
#define NTUPLE_ERR_MORE_THAN_1_GEN_POS_BQUARKS              1ull << 11
#define NTUPLE_ERR_NO_GEN_NEG_BQUARKS                       1ull << 12
#define NTUPLE_ERR_MORE_THAN_1_GEN_NEG_BQUARKS              1ull << 13
#define NTUPLE_ERR_NO_MATCHING_GEN_HAD_TAU                  1ull << 14
#define NTUPLE_ERR_NO_GEN_LEPTONS_FROM_TAU_CORRECT_CHARGE   1ull << 15
#define NTUPLE_ERR_NO_GEN_LEPTONS_FROM_TAU_CORRESPONDING_NU 1ull << 16
#define NTUPLE_ERR_NO_GEN_LEPT_NUS_FROM_TAU_CORRECT_FLAVOR  1ull << 17
#define NTUPLE_ERR_NO_GEN_TAU_NUS_FROM_TAU                  1ull << 18
#define NTUPLE_ERR_NO_GEN_TAU_NUS_FROM_TAU_OPPOSITE_FLAVOR  1ull << 19
#define NTUPLE_ERR_NO_GEN_TAU_PAIRS                         1ull << 20
#define NTUPLE_ERR_NO_GEN_POS_LEPT_FROM_TOP                 1ull << 21
#define NTUPLE_ERR_NO_GEN_POS_LEPT_FROM_TOP_W_MATCHING_NU   1ull << 22
#define NTUPLE_ERR_NO_GEN_NEG_LEPT_FROM_TOP                 1ull << 23
#define NTUPLE_ERR_NO_GEN_NEG_LEPT_FROM_TOP_W_MATCHING_NU   1ull << 24
#define NTUPLE_ERR_NO_GEN_NU_FROM_POS_TOP                   1ull << 25
#define NTUPLE_ERR_NO_GEN_NU_FROM_NEG_TOP                   1ull << 26
#define NTUPLE_ERR_NOT_POSSIBLE_POS_W_RECONSTRUCTION        1ull << 27
#define NTUPLE_ERR_NOT_POSSIBLE_NEG_W_RECONSTRUCTION        1ull << 28
#define NTUPLE_ERR_NOT_POSSIBLE_POS_TOP_RECONSTRUCTION      1ull << 29
#define NTUPLE_ERR_NOT_POSSIBLE_NEG_TOP_RECONSTRUCTION      1ull << 30
#define NTUPLE_ERR_HADRONICALLY_DECAYING_TAU_RECONSTRUCTION 1ull << 31
#define NTUPLE_ERR_LEPTONICALLY_DECAYING_TAU_RECONSTRUCTION 1ull << 32

#define NTUPLE_ERR_NO_GEN_POS_BQUARKS_DR                    1ull << 33
#define NTUPLE_ERR_NO_GEN_NEG_BQUARKS_DR                    1ull << 34
#define NTUPLE_ERR_SAME_JET_OVERLAP                         1ull << 35
#define NTUPLE_ERR_NO_GEN_LEPTONS_FROM_TAU_DR               1ull << 36
#define NTUPLE_ERR_MORE_THAN_ONE_GEN_TAU_PAIR               1ull << 37
#define NTUPLE_ERR_GEN_POS_LEPT_FROM_TOP_DR                 1ull << 38
#define NTUPLE_ERR_GEN_NEG_LEPT_FROM_TOP_DR                 1ull << 39

#define NTUPLE_WARN_OK                                           0ull
#define NTUPLE_WARN_MULTIPLE_TAU_NUS                             1ull << 0
#define NTUPLE_WARN_MULTIPLE_TAU_NUS_OPPOSITE_FLAVOR             1ull << 1
#define NTUPLE_WARN_MULTIPLE_GEN_POS_LEPT_FROM_TOP_W_MATCHING_NU 1ull << 2
#define NTUPLE_WARN_MULTIPLE_GEN_NEG_LEPT_FROM_TOP_W_MATCHING_NU 1ull << 3
#define NTUPLE_WARN_MULTIPLE_GEN_NU_FROM_POS_TOP                 1ull << 4
#define NTUPLE_WARN_MULTIPLE_GEN_NU_FROM_NEG_TOP                 1ull << 5
#define NTUPLE_WARN_MULTIPLE_POS_W_CANDIDATES                    1ull << 6
#define NTUPLE_WARN_MULTIPLE_NEG_W_CANDIDATES                    1ull << 7
#define NTUPLE_WARN_MULTIPLE_POS_TOP_CANDIDATES                  1ull << 8
#define NTUPLE_WARN_MULTIPLE_NEG_TOP_CANDIDATES                  1ull << 9
#define NTUPLE_WARN_MULTIPLE_TAU_BRANCHES_DECAY_HADRONICALLY     1ull << 10
#define NTUPLE_WARN_MULTIPLE_TAU_BRANCHES_DECAY_LEPTONICALLY     1ull << 11

typedef GenLepton GenParticleExt;

template <typename FloatType>
using RecoLeptonFiller = GenLeptonFiller<FloatType>;

template <typename FloatType>
using RecoJetFiller = GenParticleFiller<FloatType>;

template <typename FloatType>
using GenTauFiller = GenLeptonFiller<FloatType>;

template <typename FloatType>
using GenJetFiller = GenLeptonFiller<FloatType>;

template <typename FloatType>
using GenNuFiller = GenLeptonFiller<FloatType>;

struct NtupleFillerMEM // only for 3l1tau analysis
{
  /**
   * @brief Initialize file pointer to zero;
   *        do not use gen lvl info by default
   */
  NtupleFillerMEM();

  /**
    * Destructor; close the file
    * (WOOO, RAII)
    */
  ~NtupleFillerMEM();

  /**
   * @brief Basically, tell the class to use generator lvl info
   * @param use2016 Use true, if you want to use gen lvl info
   *
   * @note Use this function before setFileName() !!!
   */
  void
  use2016(bool use2016);

  /**
   * @brief Creates the file and initializes the tree
   * @param fileName
   */
  void
  setFileName(const std::string & fileName);

  /**
   * @brief Set the mass of two taus in ttH/ttZ (H/Z -> tau tau)
   * @param diTauMass The di-tau mass
   */
  void
  setDiTauMass(double diTauMass);

  /**
   * @brief Updates Higgs decay mode at generator level
   * @param genHiggsDecayMode The decay mode
   */
  void
  add(double genHiggsDecayMode);

  /**
   * @brief Updates the run-lumi-event related branches to new values
   * @param rleUnit The struct holding run-lumi-event numbers
   */
  void
  add(const RLEUnit & rleUnit);

  /**
   * @brief Updates the MET related branches to new values
   * @param metUnit
   */
  void
  add(const METUnit<double> & metUnit);

  /**
   * @brief Updates the MVA related input/output branches to new values
   * @param mva   The map containing MVA input values (string-double map)
   * @param ttV   MVA output value
   * @param ttbar Another MVA output value
   */
  void
  add(const std::map<std::string, double> mva,
      double ttV,
      double ttbar);

  /**
   * @brief Updates the selected reco b-jet branches to new values
   * @param selBJets_loose  Selected loose b-jets
   * @param selBJets_medium Selected medium b-jets
   * @param selJets Selected hadronic jets
   *
   * Note that the function tries to sort the medium, loose and hadronic jets by their CSV,
   * which is followed by unique merge of medium, loose and hadronic jets. The reason why
   * we do this because in the analysis we might select a hadronic jet instead of a b-jet
   * if the first selected b-jet is a medium one and there are no other b-jets. However, the
   * subset relation b/w the jets is: medium < loose < hadronic; therefore, we need to find
   * unique set of jets. It's fortunately easy since we just need to compare pointer values
   * and nothing else.
   */
  void
  add(const std::vector<const RecoJet*> & selBJets_loose,
      const std::vector<const RecoJet*> & selBJets_medium,
      const std::vector<const RecoJet*> & selJets);

  /**
   * @brief Updates the selected reco lepton branches to new values
   * @param selLeptons Selected leptons
   */
  void
  add(const std::vector<const RecoLepton*> & selLeptons);

  /**
   * @brief Updates the selected reco hadronic tau branches to new values
   * @param selHadTau Selected hadronic tau
   */
  void
  add(const RecoHadTau * selHadTau);

  /**
   * @brief Updates the generator level branches to new values
   * @param genHadTaus       Generator level hadronic taus
   * @param genBQuarkFromTop Generator level b quarks from top
   * @param genLepFromTau    Generator level leptons from tau
   * @param genNuFromTau     Generator level neutrinos from tau
   * @param genTau           Generator level taus
   * @param genLepFromTop    Generator level leptons from top
   * @param genNuFromTop     Generator level neutrinos from top
   */
  void
  add(const std::vector<GenHadTau> & genHadTaus,
      const std::vector<GenLepton> & genBQuarkFromTop,
      const std::vector<GenLepton> & genLepFromTau,
      const std::vector<GenLepton> & genNuFromTau,
      const std::vector<GenLepton> & genTau,
      const std::vector<GenLepton> & genLepFromTop,
      const std::vector<GenLepton> & genNuFromTop);

  /**
   * @brief Fills the tree (ofc if it's initialized) and clears whatever
   *        vectors have been saved during add() functions
   * @param force If true, fills anyways
   */
  void
  fill(bool force = false);

  /**
   * @brief Closes the file and sets related pointers to zero
   */
  void
  close();

protected:

  TFile * file_;
  TTree * tree_;

  bool use2016_;
  double diTauMass_;

  const std::map<std::string, std::string> mvaMap_ = {
    { "max(abs(LepGood_eta[iF_Recl[0]]),abs(LepGood_eta[iF_Recl[1]]))", "max2LeptonEta"  },
    { "MT_met_lep1",                                                    "MT_met_lep1"    },
    { "nJet25_Recl",                                                    "nJet25_Recl"    },
    { "mindr_lep1_jet",                                                 "mindr_lep1_jet" },
    { "mindr_lep2_jet",                                                 "mindr_lep2_jet" },
    { "LepGood_conePt[iF_Recl[0]]",                                     "lep1_cone_pt"   },
    { "LepGood_conePt[iF_Recl[2]]",                                     "lep3_cone_pt"   },
    { "avg_dr_jet",                                                     "avg_dr_jet"     },
    { "mhtJet25_Recl",                                                  "mhtJet25_Recl"  }
  };

  /* basics */
  RLEFiller rle_f_;
  METFiller<double> met_f_;

  /* mva */
  MapFiller<double> mva_f_; // provide map (below)
  BasicFiller<double> ttV_f_;
  BasicFiller<double> ttbar_f_;

  /* reconstructed */
  std::array<RecoLeptonFiller<double>, 3> leptons_f_;
  std::array<RecoJetFiller<double>, 2> jets_f_;
  RecoHadTauFiller<double> hTau_f_;

  /* generator level, enabled only if use2016_ is true */
  std::array<GenTauFiller<double>, 2>    genTaus_f_;
  std::array<GenLeptonFiller<double>, 2> genLepFromTop_f_;
  std::array<GenJetFiller<double>, 2>    genBQuark_f_;
  std::array<GenNuFiller<double>, 2>     genNuFromTop_f_;
  GenHadTauFiller<double> genHtau_f_;
  GenLeptonFiller<double> genLepFromTau_f_;
  GenNuFiller<double>     genNuLepFromTau_f_,
                          genNuFromHTau_f_,
                          genNuFromLTau_f_;
  BasicFiller<double> genHiggsDecayMode_; // use only if signal sample

  /* multiplicity counter of generator level objects */
  std::array<BasicFiller<unsigned int>, 7> genMultiplicity_f_;

private:

  /**
   * @brief Auxiliary function for sorting a collection of RecoJet pointers
   *        by their b-tagging CSV score
   * @param jet1 The first jet
   * @param jet2 The second jet
   * @return True, if the 1st jet has higher CSV score
   */
  static bool
  isHigherCSV(const RecoJet * jet1,
              const RecoJet * jet2);

  std::vector<const RecoJet*> selBJetsMerged_;
  std::vector<const RecoLepton*> selLeptons_;
  const RecoHadTau * selHadTau_;

  unsigned long long errCode_, warnCode_;
  BasicFiller<unsigned long long> errCode_f_, warnCode_f_;
};

#endif // NTUPLEFILLERMEM_H