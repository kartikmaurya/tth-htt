#ifndef EventInfoReader_H
#define EventInfoReader_H

#include "tthAnalysis/HiggsToTauTau/interface/ReaderBase.h" // ReaderBase
#include "tthAnalysis/HiggsToTauTau/interface/sysUncertOptions.h" // PUsys

// forward declarations
class TTree;
class EventInfo;

class EventInfoReader
  : public ReaderBase
{
public:
  explicit EventInfoReader(PUsys puSys_option = PUsys::central,
                           bool read_genHiggsDecayMode = true,
                           bool read_puWeight = true);
  explicit EventInfoReader(EventInfo * info,
                           PUsys puSys_option = PUsys::central,
                           bool read_genHiggsDecayMode = true,
                           bool read_puWeight = true);
  ~EventInfoReader() {}

  void
  setBranchAddresses(TTree * tree) override;

  void
  setEventInfo(EventInfo * info);

protected:
  bool read_genHiggsDecayMode_;
  bool read_puWeight_;

  EventInfo * info_;

public:
  const std::string branchName_run;
  const std::string branchName_lumi;
  const std::string branchName_event;
  const std::string branchName_genHiggsDecayMode;
  const std::string branchName_genWeight;
  const std::string branchName_puWeight;
  const std::string branchName_lheWeightSM;
};

#endif // EventInfoReader_H
