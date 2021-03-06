#ifndef tthAnalysis_HiggsToTauTau_EvtHistManager_2lss_1tau_h
#define tthAnalysis_HiggsToTauTau_EvtHistManager_2lss_1tau_h

/** \class EvtHistManager_2lss_1tau
 *
 * Book and fill histograms for event-level quantities in ttH, H->tautau analysis
 * in 2lss_1tau category
 *
 * \author Christian Veelken, Tallin
 *
 */

#include "tthAnalysis/HiggsToTauTau/interface/HistManagerBase.h" // HistManagerBase

#include "tthAnalysis/HiggsToTauTau/interface/MEMInterface_2lss_1tau.h" // MEMOutput_2lss_1tau

class EvtHistManager_2lss_1tau
  : public HistManagerBase
{
 public:
  EvtHistManager_2lss_1tau(const edm::ParameterSet & cfg);
  ~EvtHistManager_2lss_1tau() {}

  void
  bookHistograms(TFileDirectory & dir) override;

  void
  fillHistograms(int numElectrons,
                 int numMuons,
                 int numHadTaus,
                 int numJets,
                 int numBJets_loose,
                 int numBJets_medium,
                 double evtWeight,
                 double mvaOutput_2lss_ttV,
                 double mvaOutput_2lss_tt,
                 double mvaOutput_2lss_1tau_plainKin_tt,
                 double mvaOutput_2lss_1tau_plainKin_ttV,
                 double mvaOutput_2lss_1tau_plainKin_1B_M,
                 double mvaOutput_2lss_1tau_plainKin_SUM_M,
                 double mvaOutput_2lss_1tau_HTT_SUM_M,
                 double mvaOutput_2lss_1tau_HTTMEM_SUM_M,
                 double mTauTauVis1,
                 double mTauTauVis2,
                 double memOutput_LR);

  const TH1 *
  getHistogram_EventCounter() const;

 private:
  int era_;

  TH1 * histogram_numElectrons_;
  TH1 * histogram_numMuons_;
  TH1 * histogram_numHadTaus_;
  TH1 * histogram_numJets_;
  TH1 * histogram_numBJets_loose_;
  TH1 * histogram_numBJets_medium_;

  // CV: used to check loss in signal efficiency in case events with
  // high jet and b-jet multiplicity are vetoed to avoid overlap with ttH, H->bb analysis
  // (alternative: ttH, H->bb analysis adds hadronic tau veto)
  TH2 * histogram_numBJets_loose_vs_numJets_;
  TH2 * histogram_numBJets_medium_vs_numJets_;

  TH1 * histogram_mvaOutput_2lss_ttV_;
  TH1 * histogram_mvaOutput_2lss_tt_;

  TH1 * histogram_mvaOutput_2lss_1tau_plainKin_tt_;
  TH1 * histogram_mvaOutput_2lss_1tau_plainKin_ttV_;
  TH1 * histogram_mvaOutput_2lss_1tau_plainKin_1B_M_;
  TH1 * histogram_mvaOutput_2lss_1tau_plainKin_SUM_M_;
  TH1 * histogram_mvaOutput_2lss_1tau_plainKin_SUM_M_noRebin_;
  TH1 * histogram_mvaOutput_2lss_1tau_HTT_SUM_M_;
  TH1 * histogram_mvaOutput_2lss_1tau_HTT_SUM_M_noRebin_;
  TH1 * histogram_mvaOutput_2lss_1tau_HTTMEM_SUM_M_;
  TH1 * histogram_mvaOutput_2lss_1tau_HTTMEM_SUM_M_noRebin_;
  TH1 * histogram_final_;

  TH1 * histogram_mTauTauVis1_;
  TH1 * histogram_mTauTauVis_;
  TH1 * histogram_mTauTauVis2_;
  TH1 * histogram_memOutput_LR_;

  TH1 * histogram_EventCounter_;
};

#endif
