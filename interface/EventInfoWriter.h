#ifndef EVENTINFOWRITER_H
#define EVENTINFOWRITER_H

#include "tthAnalysis/HiggsToTauTau/interface/EventInfo.h" // EventInfo

// forward declarations
class TTree;

class EventInfoWriter
{
public:
  EventInfoWriter();
  EventInfoWriter(bool is_signal,
                  bool is_mc,
                  bool is_mc_th,
                  const std::string & prefix = "");

  void
  setBranches(TTree * tree);

  void
  write(const EventInfo & eventInfo);

  std::string
  getBranchName_run() const;

  std::string
  getBranchName_lumi() const;

  std::string
  getBranchName_event() const;

  std::string
  getBranchName_genHiggsDecayMode() const;

  std::string
  getBranchName_genWeight() const;

  std::string
  getBranchName_genWeight_tH() const;

  std::string
  getBranchName_pileupWeight() const;

protected:
  std::string branchName_run_;
  std::string branchName_lumi_;
  std::string branchName_event_;

  std::string branchName_genHiggsDecayMode_;
  std::string branchName_genWeight_;
  std::string branchName_genWeight_tH_;
  std::string branchName_pileupWeight_;

  EventInfo eventInfo_;
};

#endif // EVENTINFOWRITER_H
