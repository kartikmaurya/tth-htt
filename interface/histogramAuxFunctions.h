#ifndef tthAnalysis_HiggsToTauTau_histogramAuxFunctions_h
#define tthAnalysis_HiggsToTauTau_histogramAuxFunctions_h

#include <CommonTools/Utils/interface/TFileDirectory.h> // TFile, TH1, TDirectory, TFileDirectory

// forward declarations
class TH2;

void
fill(TH1 * histogram,
     double x,
     double evtWeight,
     double evtWeightErr = 0.);

void
fillWithOverFlow(TH1 * histogram,
                 double x,
                 double evtWeight,
                 double evtWeightErr = 0.);

void
fill2d(TH2 * histogram,
       double x,
       double y,
       double evtWeight,
       double evtWeightErr = 0.);

void
fillWithOverFlow2d(TH2 * histogram,
                   double x,
                   double y,
                   double evtWeight,
                   double evtWeightErr = 0.);

double
getLogWeight(double weight);

void
checkCompatibleBinning(const TH1 * histogram1,
                       const TH1 * histogram2);

bool
checkIfLabeledHistograms(const std::vector<TH1 *> & histogramsToAdd);

TH1 *
addHistograms(const std::string & newHistogramName,
              const TH1* histogram1,
              const TH1* histogram2,
              int verbosity = 0);

TH1 *
addHistograms(const std::string & newHistogramName,
              const std::vector<TH1 *> & histogramsToAdd,
              int verbosity = 0);

TH1 *
subtractHistograms(const std::string & newHistogramName,
                   const TH1 * histogramMinuend,
                   const TH1 * histogramSubtrahend,
                   int verbosity = 0);

TH1 *
subtractHistograms(const std::string & newHistogramName,
                   const TH1* histogram,
                   const std::vector<TH1 *> & histogramsToSubtract,
                   int verbosity = 0);

double
compIntegral(const TH1 * histogram,
             bool includeUnderflowBin,
             bool includeOverflowBin);

void
makeBinContentsPositive(TH1 * histogram,
                        int verbosity = 0);

void
dumpHistogram(const TH1 * histogram);

TDirectory *
getDirectory(const TFile * inputFile,
             const std::string & dirName,
             bool enableException);

TDirectory *
getSubdirectory(const TDirectory * dir,
                const std::string & subdirName,
                bool enableException);

TH1 *
getHistogram(const TDirectory * dir,
             const std::string & process,
             const std::string & histogramName,
             const std::string & central_or_shift,
             bool enableException);

TDirectory *
createSubdirectory(TDirectory * dir,
                   const std::string & subdirName,
                   bool verbose = true);

TDirectory *
createSubdirectory_recursively(TFileDirectory & dir,
                               const std::string & fullSubdirName,
                               bool verbose = true);

TArrayD
getBinning(const TH1 * histogram,
           double xMin = -1.,
           double xMax = -1.);

TH1 *
getRebinnedHistogram1d(const TH1 * histoOriginal,
                       unsigned numBins_rebinned,
                       const TArrayD & binEdges_rebinned,
		       bool add_uniqueId = false);

TH2 *
getRebinnedHistogram2d(const TH1 * histoOriginal,
                       unsigned numBinsX_rebinned,
                       const TArrayD & binEdgesX_rebinned,
                       unsigned numBinsY_rebinned,
                       const TArrayD & binEdgesY_rebinned,
		       bool add_uniqueId = false);

TArrayD getRebinnedBinning(TH1*, double);

#endif // tthAnalysis_HiggsToTauTau_histogramAuxFunctions_h
