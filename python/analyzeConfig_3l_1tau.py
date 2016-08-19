import logging

from tthAnalysis.HiggsToTauTau.analyzeConfig import *
import tthAnalyzeSamples_3l_1tau
from tthAnalysis.HiggsToTauTau.jobTools import create_if_not_exists

class analyzeConfig_3l_1tau(analyzeConfig):
  """Configuration metadata needed to run analysis in a single go.

  Sets up a folder structure by defining full path names; no directory creation is delegated here.

  Args specific to analyzeConfig_3l_1tau:
    lepton_selection: either `Tight`, `Loose` or `Fakeable`

  See $CMSSW_BASE/src/tthAnalysis/HiggsToTauTau/python/analyzeConfig.py
  for documentation of further Args.

  """
  def __init__(self, outputDir, executable_analyze, lepton_selections, hadTau_selection, central_or_shifts,
               max_files_per_job, use_lumi, lumi, debug, running_method, num_parallel_jobs, 
               histograms_to_fit, select_rle_output = False, executable_prep_dcard="prepareDatacard",
               select_root_output = False):
    analyzeConfig.__init__(self, outputDir, executable_analyze, "3l_1tau", central_or_shifts,
      max_files_per_job, use_lumi, lumi, debug, running_method, num_parallel_jobs, 
      histograms_to_fit)

    self.samples = tthAnalyzeSamples_3l_1tau.samples

    self.lepton_selections = lepton_selections

    self.hadTau_selection = hadTau_selection

    for sample_name, sample_info in self.samples.items():
      if not sample_info["use_it"] or sample_info["sample_category"] in [ "additional_signal_overlap", "background_data_estimate" ]:
        continue
      process_name = sample_info["process_name_specific"]
      for lepton_selection in self.lepton_selections:
        key_dir = getKey(sample_name, lepton_selection)  
        for dir_type in DIRLIST:
          if (not select_rle_output and dir_type == DKEY_RLES) or \
             (not select_root_output and dir_type == DKEY_ROOT): continue
          initDict(self.dirs, [ key_dir, dir_type ])
          self.dirs[key_dir][dir_type] = os.path.join(self.outputDir, dir_type, self.channel,
            "_".join([ lepton_selection ]), process_name)
    ##print "self.dirs = ", self.dirs

    self.cfgFile_analyze_original = os.path.join(self.workingDir, "analyze_3l_1tau_cfg.py")
    self.histogramDir_prep_dcard = "3l_1tau_Tight"
    self.select_rle_output = select_rle_output
    self.select_root_output = select_root_output

  def createCfg_analyze(self, inputFiles, outputFile, sample_category, triggers, lepton_selection, hadTau_selection,
                        is_mc, central_or_shift, lumi_scale, cfgFile_modified, rle_output_file, root_output_file):
    """Create python configuration file for the analyze_3l_1tau executable (analysis code)

    Args:
      inputFiles: list of input files (Ntuples)
      outputFile: output file of the job -- a ROOT file containing histogram
      process: either `TT`, `TTW`, `TTZ`, `EWK`, `Rares`, `data_obs`, `ttH_hww`, `ttH_hzz` or `ttH_htt`
      is_mc: flag indicating whether job runs on MC (True) or data (False)
      lumi_scale: event weight (= xsection * luminosity / number of events)
      central_or_shift: either 'central' or one of the systematic uncertainties defined in $CMSSW_BASE/src/tthAnalysis/HiggsToTauTau/bin/analyze_3l_1tau.cc
    """  
    lines = []
    lines.append("process.fwliteInput.fileNames = cms.vstring(%s)" % inputFiles)
    lines.append("process.fwliteOutput.fileName = cms.string('%s')" % outputFile)
    lines.append("process.analyze_3l_1tau.process = cms.string('%s')" % sample_category)
    lines.append("process.analyze_3l_1tau.use_triggers_1e = cms.bool(%s)" % ("1e" in triggers))
    lines.append("process.analyze_3l_1tau.use_triggers_2e = cms.bool(%s)" % ("2e" in triggers))
    lines.append("process.analyze_3l_1tau.use_triggers_1mu = cms.bool(%s)" % ("1mu" in triggers))
    lines.append("process.analyze_3l_1tau.use_triggers_2mu = cms.bool(%s)" % ("2mu" in triggers))
    lines.append("process.analyze_3l_1tau.use_triggers_1e1mu = cms.bool(%s)" % ("1e1mu" in triggers))
    lines.append("process.analyze_3l_1tau.leptonSelection = cms.string('%s')" % lepton_selection)
    lines.append("process.analyze_3l_1tau.hadTauSelection = cms.string('%s')" % hadTau_selection)
    lines.append("process.analyze_3l_1tau.isMC = cms.bool(%s)" % is_mc)
    lines.append("process.analyze_3l_1tau.central_or_shift = cms.string('%s')" % central_or_shift)
    lines.append("process.analyze_3l_1tau.lumiScale = cms.double(%f)" % lumi_scale)
    lines.append("process.analyze_3l_1tau.selEventsFileName_output = cms.string('%s')" % rle_output_file)
    lines.append("process.analyze_3l_1tau.selEventsTFileName = cms.string('%s')" % root_output_file)
    create_cfg(self.cfgFile_analyze_original, cfgFile_modified, lines)

  def addToMakefile_hadd_stage1(self, lines_makefile):
    inputFiles_hadd_stage1 = []
    for sample_name, sample_info in self.samples.items():
      if not sample_name in self.inputFileIds.keys():
        continue
      process_name = sample_info["process_name_specific"]
      inputFiles_sample = []
      for lepton_selection in self.lepton_selections:
        for central_or_shift in self.central_or_shifts:
          inputFiles_jobIds = []                  
          for jobId in range(len(self.inputFileIds[sample_name])):
            key_file = getKey(sample_name, lepton_selection, central_or_shift, jobId)
            if key_file in self.histogramFiles.keys():
              inputFiles_jobIds.append(self.histogramFiles[key_file])
          if len(inputFiles_jobIds) > 0:
            haddFile_jobIds = self.histogramFile_hadd_stage1.replace(".root", "_%s_%s_%s.root" % \
              (process_name, lepton_selection, central_or_shift))
            lines_makefile.append("%s: %s" % (haddFile_jobIds, " ".join(inputFiles_jobIds)))
            lines_makefile.append("\t%s %s" % ("rm -f", haddFile_jobIds))
            lines_makefile.append("\t%s %s %s" % ("hadd", haddFile_jobIds, " ".join(inputFiles_jobIds)))
            lines_makefile.append("")
            inputFiles_sample.append(haddFile_jobIds)
            self.filesToClean.append(haddFile_jobIds)
      if len(inputFiles_sample) > 0:
        haddFile_sample = self.histogramFile_hadd_stage1.replace(".root", "_%s.root" % process_name)
        lines_makefile.append("%s: %s" % (haddFile_sample, " ".join(inputFiles_sample)))
        lines_makefile.append("\t%s %s" % ("rm -f", haddFile_sample))
        lines_makefile.append("\t%s %s %s" % ("hadd", haddFile_sample, " ".join(inputFiles_sample)))
        lines_makefile.append("")
        inputFiles_hadd_stage1.append(haddFile_sample)
        self.filesToClean.append(haddFile_sample)
    lines_makefile.append("%s: %s" % (self.histogramFile_hadd_stage1, " ".join(inputFiles_hadd_stage1)))
    lines_makefile.append("\t%s %s" % ("rm -f", self.histogramFile_hadd_stage1))
    lines_makefile.append("\t%s %s %s" % ("hadd", self.histogramFile_hadd_stage1, " ".join(inputFiles_hadd_stage1)))
    lines_makefile.append("")
    self.filesToClean.append(self.histogramFile_hadd_stage1)

  def create(self):
    """Creates all necessary config files and runs the complete analysis workfow -- either locally or on the batch system
    """

    for key in self.dirs.keys():
      for dir_type in self.dirs[key].keys():
        create_if_not_exists(self.dirs[key][dir_type])
  
    self.inputFileIds = {}
    for sample_name, sample_info in self.samples.items():
      if not sample_info["use_it"] or sample_info["sample_category"] in [ "additional_signal_overlap", "background_data_estimate" ]:
        continue

      process_name = sample_info["process_name_specific"]

      logging.info("Creating configuration files to run '%s' for sample %s" % (self.executable_analyze, process_name))  

      ( secondary_files, primary_store, secondary_store ) = self.initializeInputFileIds(sample_name, sample_info)

      is_mc = (sample_info["type"] == "mc")
      lumi_scale = 1. if not (self.use_lumi and is_mc) else sample_info["xsection"] * self.lumi / sample_info["nof_events"]
      sample_category = sample_info["sample_category"]
      triggers = sample_info["triggers"]

      for lepton_selection in self.lepton_selections:
        for central_or_shift in self.central_or_shifts:
          for jobId in range(len(self.inputFileIds[sample_name])):
            if central_or_shift != "central" and not is_mc:
              continue

            inputFiles = generate_input_list(self.inputFileIds[sample_name][jobId], secondary_files, primary_store, secondary_store, self.debug)
  
            key_dir = getKey(sample_name, lepton_selection)
            key_file = getKey(sample_name, lepton_selection, central_or_shift, jobId)

            self.cfgFiles_analyze_modified[key_file] = os.path.join(self.dirs[key_dir][DKEY_CFGS], "analyze_%s_%s_%s_%s_%i_cfg.py" % \
              (self.channel, process_name, lepton_selection, central_or_shift, jobId))
            self.histogramFiles[key_file] = os.path.join(self.dirs[key_dir][DKEY_HIST], "%s_%s_%s_%i.root" % \
              (process_name, lepton_selection, central_or_shift, jobId))
            self.logFiles_analyze[key_file] = os.path.join(self.dirs[key_dir][DKEY_LOGS], "analyze_%s_%s_%s_%s_%i.log" % \
              (self.channel, process_name, lepton_selection, central_or_shift, jobId))
            self.rleOutputFiles[key_file] = os.path.join(self.dirs[key_dir][DKEY_RLES], "rle_%s_%s_%s_%s_%i.txt" % \
              (self.channel, process_name, lepton_selection, central_or_shift, jobId)) if self.select_rle_output else ""
            self.rootOutputFiles[key_file] = os.path.join(self.dirs[key_dir][DKEY_ROOT], "out_%s_%s_%s_%s_%i.root" % \
              (self.channel, process_name, lepton_selection, central_or_shift, jobId)) if self.select_root_output else ""

            self.createCfg_analyze(inputFiles, self.histogramFiles[key_file], sample_category, triggers,
              lepton_selection, self.hadTau_selection,
              is_mc, central_or_shift, lumi_scale, self.cfgFiles_analyze_modified[key_file],
              self.rleOutputFiles[key_file], self.rootOutputFiles[key_file])

    if self.is_sbatch:
      logging.info("Creating script for submitting '%s' jobs to batch system" % self.executable_analyze)
      self.createScript_sbatch()

    logging.info("Creating configuration files for executing 'prepareDatacards'")
    for histogramToFit in self.histograms_to_fit:
      self.createCfg_prep_dcard(histogramToFit)

    logging.info("Creating Makefile")
    lines_makefile = []
    self.addToMakefile_analyze(lines_makefile)
    self.addToMakefile_hadd_stage1(lines_makefile)
    self.addToMakefile_backgrounds_from_data(lines_makefile)
    self.addToMakefile_hadd_stage2(lines_makefile)
    self.addToMakefile_prep_dcard(lines_makefile)
    self.addToMakefile_clean(lines_makefile)
    self.createMakefile(lines_makefile)

    logging.info("Done")

