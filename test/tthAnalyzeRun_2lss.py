#!/usr/bin/env python
import os, logging, sys, getpass
from tthAnalysis.HiggsToTauTau.configs.analyzeConfig_2lss import analyzeConfig_2lss
from tthAnalysis.HiggsToTauTau.jobTools import query_yes_no
from tthAnalysis.HiggsToTauTau.analysisSettings import systematics
from tthAnalysis.HiggsToTauTau.runConfig import tthAnalyzeParser

#--------------------------------------------------------------------------------
# NOTE: set mode flag to
#   'VHbb'           : to run the analysis directly on the VHbb Ntuples
#   'forBDTtraining' : to run the analysis on the Ntuples with a relaxed event selection, to increase the BDT training statistics
#--------------------------------------------------------------------------------

# E.g. to run: ./tthAnalyzeRun_2lss.py -v 2017Dec13 -mode VHbb -e 2017

mode_choices         = [ 'VHbb', 'forBDTtraining', 'sync' ]
sys_choices          = [ 'central', 'full', 'extended' ]
systematics.full     = systematics.an_common
systematics.extended = systematics.an_extended

parser = tthAnalyzeParser()
parser.add_modes(mode_choices)
parser.add_sys(sys_choices)
parser.add_preselect()
parser.add_rle_select()
args = parser.parse_args()

# Common arguments
era                = args.era
version            = args.version
dry_run            = args.dry_run
resubmission_limit = args.resubmission_limit
resubmit           = not args.disable_resubmission
no_exec            = args.no_exec
auto_exec          = args.auto_exec
check_input_files  = args.check_input_files
debug              = args.debug

# Additional arguments
mode              = args.mode
systematics_label = args.systematics
use_preselected   = args.use_preselected
rle_select        = os.path.expanduser(args.rle_select)

# Use the arguments
max_job_resubmission = resubmission_limit if resubmit else 1
central_or_shift     = getattr(systematics, systematics_label)
max_files_per_job    = 50 if use_preselected else 1

lepton_charge_selections = [ "OS", "SS" ]

if mode == "VHbb":
  if use_preselected:
    from tthAnalysis.HiggsToTauTau.samples.tthAnalyzeSamples_2017_preselected import samples_2017
  else:
    from tthAnalysis.HiggsToTauTau.samples.tthAnalyzeSamples_2017 import samples_2017
elif mode == "forBDTtraining":
  if use_preselected:
    from tthAnalysis.HiggsToTauTau.samples.tthAnalyzeSamples_2017_FastSim_preselected import samples_2017
  else:
    from tthAnalysis.HiggsToTauTau.samples.tthAnalyzeSamples_2017_FastSim import samples_2017
  lepton_charge_selections = ["SS"]
elif mode == "sync":
  from tthAnalysis.HiggsToTauTau.samples.tthAnalyzeSamples_2017_addMEM_sync import samples_2017
else:
  raise ValueError("Internal logic error")

if era == "2017":
  from tthAnalysis.HiggsToTauTau.analysisSettings import lumi_2017 as lumi
  samples = samples_2017
else:
  raise ValueError("Invalid era: %s" % era)

for sample_name, sample_info in samples.items():
  if sample_name.startswith('/Tau/Run'):
    sample_info["use_it"] = False

if __name__ == '__main__':
  logging.basicConfig(
    stream = sys.stdout,
    level  = logging.INFO,
    format = '%(asctime)s - %(levelname)s: %(message)s',
  )

  logging.info(
    "Running the jobs with the following systematic uncertainties enabled: %s" % \
    ', '.join(central_or_shift)
  )

  configDir = os.path.join("/home",       getpass.getuser(), "ttHAnalysis", era, version)
  outputDir = os.path.join("/hdfs/local", getpass.getuser(), "ttHAnalysis", era, version)

  job_statistics_summary = {}
  run_analysis           = False
  is_last_resubmission   = False

  for idx_job_resubmission in range(max_job_resubmission):
    if is_last_resubmission:
      continue
    logging.info("Job submission #%i:" % (idx_job_resubmission + 1))

    analysis = analyzeConfig_2lss(
      configDir                 = configDir,
      outputDir                 = outputDir,
      executable_analyze        = "analyze_2lss",
      cfgFile_analyze           = "analyze_2lss_cfg.py",
      samples                   = samples,
      MEMbranch                 = None, # CV: MEM not implemented for 2lss channel yet
      lepton_charge_selections  = lepton_charge_selections,
      hadTauVeto_selection      = "dR03mvaMedium", # veto events containing taus that pass tau ID WP applied in 2lss+1tau channel,
      applyFakeRateWeights      = "2lepton",
      central_or_shifts         = central_or_shift,
      max_files_per_job         = max_files_per_job,
      era                       = era,
      use_lumi                  = True,
      lumi                      = lumi,
      check_input_files         = check_input_files,
      running_method            = "sbatch",
      num_parallel_jobs         = 100, # KE: run up to 100 'hadd' jobs in parallel on batch system
      executable_addBackgrounds = "addBackgrounds",
      executable_addFakes       = "addBackgroundLeptonFakes",
      executable_addFlips       = "addBackgroundLeptonFlips",
      histograms_to_fit         = [
        "EventCounter",
        "numJets",
        "mvaOutput_2lss_ttV",
        "mvaOutput_2lss_ttbar",
        "mvaDiscr_2lss",
      ],
      select_rle_output         = True,
      verbose                   = idx_job_resubmission > 0,
      dry_run                   = dry_run,
      do_sync                   = mode == 'sync',
      isDebug                   = debug,
      rle_select                = rle_select,
    )

    if mode.find("forBDTtraining") != -1:
      analysis.set_BDT_training()

    job_statistics = analysis.create()
    for job_type, num_jobs in job_statistics.items():
      logging.info(" #jobs of type '%s' = %i" % (job_type, num_jobs))
    job_statistics_summary[idx_job_resubmission] = job_statistics

    if idx_job_resubmission == 0:
      if auto_exec:
        run_analysis = True
      elif no_exec:
        run_analysis = False
      else:
        run_analysis = query_yes_no("Start jobs ?")
    if run_analysis:
      analysis.run()
    else:
      sys.exit(0)

    if job_statistics['analyze'] == 0:
      is_last_resubmission = True

  for idx_job_resubmission in job_statistics_summary.keys():
    logging.info("Job submission #%i:" % (idx_job_resubmission + 1))
    for job_type, num_jobs in job_statistics_summary[idx_job_resubmission].items():
      logging.info(" #jobs of type '%s' = %i" % (job_type, num_jobs))