#include "tthAnalysis/HiggsToTauTau/interface/EvtHistManager_2l_2tau.h"

#include "tthAnalysis/HiggsToTauTau/interface/histogramAuxFunctions.h" // fillWithOverFlow(), fillWithOverFlow2d()

EvtHistManager_2l_2tau::EvtHistManager_2l_2tau(const edm::ParameterSet& cfg)
  : HistManagerBase(cfg)
{
  central_or_shiftOptions_["numElectrons"] = { "central" };
  central_or_shiftOptions_["numMuons"] = { "central" };
  central_or_shiftOptions_["numHadTaus"] = { "central" };
  central_or_shiftOptions_["numJets"] = { "central" };
  central_or_shiftOptions_["numBJets_loose"] = { "central" };
  central_or_shiftOptions_["numBJets_medium"] = { "central" };
  central_or_shiftOptions_["numBJets_loose_vs_numJets"] = { "central" };
  central_or_shiftOptions_["numBJets_medium_vs_numJets"] = { "central" };
  central_or_shiftOptions_["leptonPairCharge"] = { "central" };
  central_or_shiftOptions_["hadTauPairCharge"] = { "central" };
  central_or_shiftOptions_["mTauTauVis"] = { "central" };
  central_or_shiftOptions_["EventCounter"] = { "*" };
  central_or_shiftOptions_["mvaOutput_plainKin_tt"] = { "central" };
  central_or_shiftOptions_["mvaOutput_plainKin_ttV"] = { "central" };
  central_or_shiftOptions_["mvaOutput_plainKin_1B_VT"] = { "central" };
  central_or_shiftOptions_["mvaOutput_plainKin_SUM_VT"] = { "central" };
  central_or_shiftOptions_["mvaOutput_plainKin_SUM_VT_noRebin"] = { "central" };
  central_or_shiftOptions_["mvaOutput_final"] = { "*" }; 
}

void
EvtHistManager_2l_2tau::bookHistograms(TFileDirectory & dir)
{
  histogram_numElectrons_    = book1D(dir, "numElectrons",    "numElectrons",     5, -0.5,  +4.5);
  histogram_numMuons_        = book1D(dir, "numMuons",        "numMuons",         5, -0.5,  +4.5);
  histogram_numHadTaus_      = book1D(dir, "numHadTaus",      "numHadTaus",       5, -0.5,  +4.5);
  histogram_numJets_         = book1D(dir, "numJets",         "numJets",         20, -0.5, +19.5);
  histogram_numBJets_loose_  = book1D(dir, "numBJets_loose",  "numBJets_loose",  10, -0.5,  +9.5);
  histogram_numBJets_medium_ = book1D(dir, "numBJets_medium", "numBJets_medium", 10, -0.5,  +9.5);

  //histogram_numBJets_loose_vs_numJets_  = book2D(dir, "numBJets_loose_vs_numJets",  "numBJets_loose_vs_numJets",  8, -0.5, +7.5, 6, -0.5, +5.5);
  //histogram_numBJets_medium_vs_numJets_ = book2D(dir, "numBJets_medium_vs_numJets", "numBJets_medium_vs_numJets", 8, -0.5, +7.5, 6, -0.5, +5.5);

  histogram_leptonPairCharge_ = book1D(dir, "leptonPairCharge", "leptonPairCharge", 5, -2.5, +2.5);
  histogram_hadTauPairCharge_ = book1D(dir, "hadTauPairCharge", "hadTauPairCharge", 5, -2.5, +2.5);

  histogram_mTauTauVis_   = book1D(dir, "mTauTauVis",   "mTauTauVis",   40,  0.,  200.);
  histogram_EventCounter_ = book1D(dir, "EventCounter", "EventCounter",  1, -0.5,  +0.5);

  histogram_mvaOutput_plainKin_tt_             = book1D(dir, "mvaOutput_plainKin_tt",             "mvaOutput_plainKin_tt",             100, 0.0, 1.0);
  histogram_mvaOutput_plainKin_ttV_            = book1D(dir, "mvaOutput_plainKin_ttV",            "mvaOutput_plainKin_ttV",            100, 0.0, 1.0);
  histogram_mvaOutput_plainKin_1B_VT_          = book1D(dir, "mvaOutput_plainKin_1B_VT",          "mvaOutput_plainKin_1B_VT",          100, 0.0, 1.0);
  histogram_mvaOutput_plainKin_SUM_VT_         = book1D(dir, "mvaOutput_plainKin_SUM_VT",         "mvaOutput_plainKin_SUM_VT",         100, 0.0, 1.0);
  histogram_mvaOutput_plainKin_SUM_VT_noRebin_ = book1D(dir, "mvaOutput_plainKin_SUM_VT_noRebin", "mvaOutput_plainKin_SUM_VT_noRebin", 100, 0.0, 1.0);

  Float_t binsx[5]  = { 0.0, 0.25, 0.50, 0.75, 1.0 };
  histogram_final_ = book1D(dir, "mvaOutput_final",  "mvaOutput_final", 4, binsx);

}

void
EvtHistManager_2l_2tau::fillHistograms(int numElectrons,
                                       int numMuons,
                                       int numHadTaus,
                                       int numJets,
                                       int numBJets_loose,
                                       int numBJets_medium,
                                       double mTauTauVis,
                                       double leptonPairCharge,
                                       double hadTauPairCharge,
                                       double evtWeight,
                                       double mvaOutput_plainKin_tt,
                                       double mvaOutput_plainKin_ttV,
                                       double mvaOutput_plainKin_SUM_VT,
                                       double mvaOutput_plainKin_1B_VT)
{
  const double evtWeightErr = 0.;

  fillWithOverFlow(histogram_numElectrons_,    numElectrons,    evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_numMuons_,        numMuons,        evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_numHadTaus_,      numHadTaus,      evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_numJets_,         numJets,         evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_numBJets_loose_,  numBJets_loose,  evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_numBJets_medium_, numBJets_medium, evtWeight, evtWeightErr);

  //fillWithOverFlow2d(histogram_numBJets_loose_vs_numJets_,  numJets, numBJets_loose,  evtWeight, evtWeightErr);
  //fillWithOverFlow2d(histogram_numBJets_medium_vs_numJets_, numJets, numBJets_medium, evtWeight, evtWeightErr);

  fillWithOverFlow(histogram_leptonPairCharge_, leptonPairCharge, evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_hadTauPairCharge_, hadTauPairCharge, evtWeight, evtWeightErr);

  fillWithOverFlow(histogram_mTauTauVis_,   mTauTauVis, evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_EventCounter_, 0.,         evtWeight, evtWeightErr);

  fillWithOverFlow(histogram_mvaOutput_plainKin_tt_,             mvaOutput_plainKin_tt,     evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_mvaOutput_plainKin_ttV_,            mvaOutput_plainKin_ttV,    evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_mvaOutput_plainKin_1B_VT_,          mvaOutput_plainKin_1B_VT,  evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_mvaOutput_plainKin_SUM_VT_,         mvaOutput_plainKin_SUM_VT, evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_mvaOutput_plainKin_SUM_VT_noRebin_, mvaOutput_plainKin_SUM_VT, evtWeight, evtWeightErr);
  fillWithOverFlow(histogram_final_,                             mvaOutput_plainKin_SUM_VT, evtWeight, evtWeightErr);
}
