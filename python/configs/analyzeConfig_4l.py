import logging, re

from tthAnalysis.HiggsToTauTau.configs.analyzeConfig import *
from tthAnalysis.HiggsToTauTau.jobTools import create_if_not_exists
from tthAnalysis.HiggsToTauTau.analysisTools import initDict, getKey, create_cfg, createFile, generateInputFileList

def get_lepton_selection_and_frWeight(lepton_selection, lepton_frWeight):
  lepton_selection_and_frWeight = lepton_selection
  if lepton_selection.startswith("Fakeable"):
    if lepton_frWeight == "enabled":
      lepton_selection_and_frWeight += "_wFakeRateWeights"
    elif lepton_frWeight == "disabled":
      lepton_selection_and_frWeight += "_woFakeRateWeights"
  lepton_selection_and_frWeight = lepton_selection_and_frWeight.replace("|", "_")
  return lepton_selection_and_frWeight

def getHistogramDir(lepton_selection, lepton_frWeight, chargeSumSelection):
  histogramDir = "4l_%s_%s" % (chargeSumSelection, lepton_selection)
  if lepton_selection.find("Fakeable") != -1:
    if lepton_frWeight == "enabled":
      histogramDir += "_wFakeRateWeights"
    elif lepton_frWeight == "disabled":
      histogramDir += "_woFakeRateWeights"
  return histogramDir

class analyzeConfig_4l(analyzeConfig):
  """Configuration metadata needed to run analysis in a single go.

  Sets up a folder structure by defining full path names; no directory creation is delegated here.

  Args specific to analyzeConfig_4l:
    lepton_selection: either `Tight`, `Loose` or `Fakeable`

  See $CMSSW_BASE/src/tthAnalysis/HiggsToTauTau/python/analyzeConfig.py
  for documentation of further Args.

  """
  def __init__(self, configDir, outputDir, executable_analyze, cfgFile_analyze, samples,
               applyFakeRateWeights, chargeSumSelections, central_or_shifts,
               max_files_per_job, era, use_lumi, lumi, check_input_files, running_method, num_parallel_jobs,
               executable_addBackgrounds, executable_addBackgroundJetToTauFakes, histograms_to_fit, select_rle_output = False,
               executable_prep_dcard="prepareDatacards", executable_add_syst_dcard = "addSystDatacards",
               select_root_output = False, do_sync = False, verbose = False, dry_run = False, isDebug = False,
               rle_select = ''):
    analyzeConfig.__init__(self, configDir, outputDir, executable_analyze, "4l", central_or_shifts,
      max_files_per_job, era, use_lumi, lumi, check_input_files, running_method, num_parallel_jobs,
      histograms_to_fit,
      executable_prep_dcard = executable_prep_dcard,
      executable_add_syst_dcard = executable_add_syst_dcard,
      do_sync = do_sync,
      verbose = verbose,
      dry_run = dry_run,
      isDebug = isDebug,
    )

    self.samples = samples

    ##self.lepton_selections = [ "Tight", "Fakeable", "Fakeable_mcClosure" ]
    self.lepton_selections = [ "Tight", "Fakeable" ]
    self.lepton_frWeights = [ "enabled", "disabled" ]
    self.applyFakeRateWeights = applyFakeRateWeights

    self.lepton_genMatches = [ "4l0j", "3l1j", "2l2j", "1l3j", "0l4j" ]

    self.apply_leptonGenMatching = None
    self.lepton_genMatches_nonfakes = []
    self.lepton_genMatches_fakes = []
    if applyFakeRateWeights == "4lepton":
      self.apply_leptonGenMatching = True
      for lepton_genMatch in self.lepton_genMatches:
        if lepton_genMatch.endswith("0j"):
          self.lepton_genMatches_nonfakes.append(lepton_genMatch)
        else:
          self.lepton_genMatches_fakes.append(lepton_genMatch)
    else:
      raise ValueError("Invalid Configuration parameter 'applyFakeRateWeights' = %s !!" % applyFakeRateWeights)

    self.chargeSumSelections = chargeSumSelections

    self.executable_addBackgrounds = executable_addBackgrounds
    self.executable_addFakes = executable_addBackgroundJetToTauFakes

    self.nonfake_backgrounds = [ "TT", "TTW", "TTZ", "TTWW", "EWK", "Rares", "tH" ]

    self.cfgFile_analyze = os.path.join(self.template_dir, cfgFile_analyze)
    self.prep_dcard_processesToCopy = [ "data_obs" ] + self.nonfake_backgrounds + [ "fakes_data", "fakes_mc" ]
    self.histogramDir_prep_dcard = "4l_OS_Tight"
    self.histogramDir_prep_dcard_SS = "4l_SS_Tight"
    self.make_plots_backgrounds = [ "TTW", "TTZ", "EWK", "Rares", "fakes_data" ]
    self.cfgFile_make_plots = os.path.join(self.template_dir, "makePlots_4l_cfg.py")
    self.cfgFile_make_plots_mcClosure = os.path.join(self.template_dir, "makePlots_mcClosure_4l_cfg.py")

    self.select_rle_output = select_rle_output
    self.select_root_output = select_root_output
    self.rle_select = rle_select

    self.isBDTtraining = False

  def set_BDT_training(self):
    """Run analysis with loose selection criteria for leptons,
       for the purpose of preparing event list files for BDT training.
    """
    self.lepton_selections = [ "forBDTtraining" ]
    self.lepton_frWeights  = [ "disabled" ]
    self.isBDTtraining     = True

  def createCfg_analyze(self, jobOptions):
    """Create python configuration file for the analyze_4l executable (analysis code)

    Args:
      inputFiles: list of input files (Ntuples)
      outputFile: output file of the job -- a ROOT file containing histogram
      process: either `TT`, `TTW`, `TTZ`, `EWK`, `Rares`, `data_obs`, `ttH_hww`, `ttH_hzz` or `ttH_htt`
      is_mc: flag indicating whether job runs on MC (True) or data (False)
      lumi_scale: event weight (= xsection * luminosity / number of events)
      central_or_shift: either 'central' or one of the systematic uncertainties defined in $CMSSW_BASE/src/tthAnalysis/HiggsToTauTau/bin/analyze_4l.cc
    """
    lines = []
    ##lines.append("process.fwliteInput.fileNames = cms.vstring(%s)" % [ os.path.basename(inputFile) for inputFile in jobOptions['ntupleFiles'] ])
    lines.append("process.fwliteInput.fileNames = cms.vstring(%s)" % jobOptions['ntupleFiles'])
    lines.append("process.fwliteOutput.fileName = cms.string('%s')" % os.path.basename(jobOptions['histogramFile']))
    lines.append("process.analyze_4l.process = cms.string('%s')" % jobOptions['sample_category'])
    lepton_frWeight = None
    if jobOptions['applyFakeRateWeights'] == "disabled":
      lepton_frWeight = "disabled"
    else:
      lepton_frWeight = "enabled"
    histogramDir = getHistogramDir(jobOptions['lepton_selection'], lepton_frWeight, jobOptions['chargeSumSelection'])
    lines.append("process.analyze_4l.histogramDir = cms.string('%s')" % histogramDir)
    lines.append("process.analyze_4l.era = cms.string('%s')" % self.era)
    for trigger in [ '1e', '1mu', '2e', '2mu', '1e1mu', '3e', '3mu', '1e2mu', '2e1mu' ]:
      lines.append("process.analyze_4l.triggers_%s = cms.vstring(%s)" % (trigger, getattr(self, 'triggers_%s' % trigger)))
      lines.append("process.analyze_4l.use_triggers_%s = cms.bool(%s)" % (trigger, trigger in jobOptions['triggers']))
    lines.append("process.analyze_4l.leptonSelection = cms.string('%s')" % jobOptions['lepton_selection'])
    lines.append("process.analyze_4l.apply_leptonGenMatching = cms.bool(%s)" % (jobOptions['apply_leptonGenMatching'] and jobOptions['is_mc']))
    lines.append("process.analyze_4l.apply_leptonGenMatching_ttZ_workaround = cms.bool(%s)" % (jobOptions['sample_category'] in [ "TTZ", "TTW", "signal" ]))
    lines.append("process.analyze_4l.applyFakeRateWeights = cms.string('%s')" % jobOptions['applyFakeRateWeights'])
    lines.append("process.analyze_4l.chargeSumSelection = cms.string('%s')" % jobOptions['chargeSumSelection'])
    lines.append("process.analyze_4l.use_HIP_mitigation_mediumMuonId = cms.bool(%s)" % jobOptions['use_HIP_mitigation_mediumMuonId'])
    lines.append("process.analyze_4l.isMC = cms.bool(%s)" % jobOptions['is_mc'])
    lines.append("process.analyze_4l.central_or_shift = cms.string('%s')" % jobOptions['central_or_shift'])
    lines.append("process.analyze_4l.lumiScale = cms.double(%f)" % jobOptions['lumi_scale'])
    lines.append("process.analyze_4l.apply_genWeight = cms.bool(%s)" % jobOptions['apply_genWeight'])
    lines.append("process.analyze_4l.apply_trigger_bits = cms.bool(%s)" % jobOptions['apply_trigger_bits'])
    lines.append("process.analyze_4l.selEventsFileName_output = cms.string('%s')" % jobOptions['rleOutputFile'])
    lines.append("process.analyze_4l.selEventsTFileName = cms.string('%s')" % jobOptions['rootOutputFile'])
    lines.append("process.analyze_4l.selectBDT = cms.bool(%s)" % str(jobOptions['selectBDT']))
    lines.append("process.analyze_4l.redoGenMatching = cms.bool(False)")
    lines.append("process.analyze_4l.fillGenEvtHistograms = cms.bool(True)")
    if self.do_sync:
      lines.append("process.analyze_4l.syncNtuple.tree   = cms.string('%s')" % jobOptions['syncTree'])
      lines.append("process.analyze_4l.syncNtuple.output = cms.string('%s')" % os.path.basename(jobOptions['syncOutput']))
      lines.append("process.analyze_4l.selEventsFileName_input = cms.string('%s')" % jobOptions['syncRLE'])
    lines.append("process.analyze_4l.isDEBUG = cms.bool(%s)" % self.isDebug)
    create_cfg(self.cfgFile_analyze, jobOptions['cfgFile_modified'], lines)

  def createCfg_makePlots_mcClosure(self, jobOptions):
    """Fills the template of python configuration file for making control plots

    Args:
      histogramFile: name of the input ROOT file
    """
    lines = []
    lines.append("process.fwliteInput.fileNames = cms.vstring('%s')" % jobOptions['inputFile'])
    lines.append("process.makePlots_mcClosure.outputFileName = cms.string('%s')" % jobOptions['outputFile'])
    lines.append("process.makePlots_mcClosure.processesBackground = cms.vstring(%s)" % self.make_plots_backgrounds)
    lines.append("process.makePlots_mcClosure.processSignal = cms.string('%s')" % self.make_plots_signal)
    lines.append("process.makePlots_mcClosure.categories = cms.VPSet(")
    lines.append("  cms.PSet(")
    lines.append("    signal = cms.string('%s')," % self.histogramDir_prep_dcard)
    lines.append("    sideband = cms.string('%s')," % self.histogramDir_prep_dcard.replace("Tight", "Fakeable_mcClosure_wFakeRateWeights"))
    lines.append("    label = cms.string('%s')" % self.channel)
    lines.append("  )")
    lines.append(")")
    create_cfg(self.cfgFile_make_plots_mcClosure, jobOptions['cfgFile_modified'], lines)

  def create(self):
    """Creates all necessary config files and runs the complete analysis workfow -- either locally or on the batch system
    """

    for sample_name, sample_info in self.samples.items():
      if not sample_info["use_it"] or sample_info["sample_category"] in [ "additional_signal_overlap", "background_data_estimate" ]:
        continue
      process_name = sample_info["process_name_specific"]
      for lepton_selection in self.lepton_selections:
        for lepton_frWeight in self.lepton_frWeights:
          if lepton_frWeight == "enabled" and not lepton_selection.startswith("Fakeable"):
            continue
          lepton_selection_and_frWeight = get_lepton_selection_and_frWeight(lepton_selection, lepton_frWeight)
          for chargeSumSelection in self.chargeSumSelections:
            key_dir = getKey(process_name, lepton_selection_and_frWeight, chargeSumSelection)
            for dir_type in [ DKEY_CFGS, DKEY_HIST, DKEY_LOGS, DKEY_ROOT, DKEY_RLES, DKEY_SYNC ]:
              initDict(self.dirs, [ key_dir, dir_type ])
              if dir_type in [ DKEY_CFGS, DKEY_LOGS ]:
                self.dirs[key_dir][dir_type] = os.path.join(self.configDir, dir_type, self.channel,
                  "_".join([ lepton_selection_and_frWeight, chargeSumSelection ]), process_name)
              else:
                self.dirs[key_dir][dir_type] = os.path.join(self.outputDir, dir_type, self.channel,
                  "_".join([ lepton_selection_and_frWeight, chargeSumSelection ]), process_name)
    for dir_type in [ DKEY_CFGS, DKEY_SCRIPTS, DKEY_HIST, DKEY_LOGS, DKEY_DCRD, DKEY_PLOT, DKEY_HADD_RT, DKEY_SYNC ]:
      initDict(self.dirs, [ dir_type ])
      if dir_type in [ DKEY_CFGS, DKEY_SCRIPTS, DKEY_LOGS, DKEY_DCRD, DKEY_PLOT, DKEY_HADD_RT ]:
        self.dirs[dir_type] = os.path.join(self.configDir, dir_type, self.channel)
      else:
        self.dirs[dir_type] = os.path.join(self.outputDir, dir_type, self.channel)
    ##print "self.dirs = ", self.dirs

    for key in self.dirs.keys():
      if type(self.dirs[key]) == dict:
        for dir_type in self.dirs[key].keys():
          create_if_not_exists(self.dirs[key][dir_type])
      else:
        create_if_not_exists(self.dirs[key])

    inputFileLists = {}
    for sample_name, sample_info in self.samples.items():
      if not sample_info["use_it"] or sample_info["sample_category"] in [ "additional_signal_overlap", "background_data_estimate" ]:
        continue
      logging.info("Checking input files for sample %s" % sample_info["process_name_specific"])
      inputFileLists[sample_name] = generateInputFileList(sample_info, self.max_files_per_job, self.check_input_files)

    for lepton_selection in self.lepton_selections:

      if lepton_selection == "forBDTtraining":
        lepton_selection = "Loose" # "Tight" ## "Fakeable" ## Xanda

      for lepton_frWeight in self.lepton_frWeights:
        if lepton_frWeight == "enabled" and not lepton_selection.startswith("Fakeable"):
          continue
        if lepton_frWeight == "disabled" and not lepton_selection in [ "Tight", "forBDTtraining" ]:
          continue
        lepton_selection_and_frWeight = get_lepton_selection_and_frWeight(lepton_selection, lepton_frWeight)

        for chargeSumSelection in self.chargeSumSelections:

          for sample_name, sample_info in self.samples.items():
            if not sample_info["use_it"] or sample_info["sample_category"] in [ "additional_signal_overlap", "background_data_estimate" ]:
              continue
            process_name = sample_info["process_name_specific"]
            logging.info("Creating configuration files to run '%s' for sample %s" % (self.executable_analyze, process_name))

            sample_category = sample_info["sample_category"]
            is_mc = (sample_info["type"] == "mc")
            is_signal = (sample_category == "signal")

            for central_or_shift in self.central_or_shifts:

              inputFileList = inputFileLists[sample_name]
              for jobId in inputFileList.keys():
                if central_or_shift != "central":
                  isFR_shape_shift = False
                  for FR_shape_shift in [
                    "CMS_ttHl_FRe_shape",
                    "CMS_ttHl_FRm_shape",
                    "CMS_ttHl_FRjt_norm",
                    "CMS_ttHl_FRjt_shape" ]:
                    if central_or_shift.find(FR_shape_shift) != -1:
                      isFR_shape_shift = True
                  if not ((lepton_selection == "Fakeable" and chargeSumSelection == "OS" and isFR_shape_shift) or
                          (lepton_selection == "Tight"    and chargeSumSelection == "OS")):
                    continue
                  if not is_mc and not isFR_shape_shift:
                    continue
                if central_or_shift.startswith("CMS_ttHl_thu_shape_ttH") and sample_category != "signal":
                  continue
                if central_or_shift.startswith("CMS_ttHl_thu_shape_ttW") and sample_category != "TTW":
                  continue
                if central_or_shift.startswith("CMS_ttHl_thu_shape_ttZ") and sample_category != "TTZ":
                  continue
                ##print "processing sample %s: jobId = %i, central_or_shift = '%s'" % (process_name, jobId, central_or_shift)

                # build config files for executing analysis code
                key_dir = getKey(process_name, lepton_selection_and_frWeight, chargeSumSelection)
                key_analyze_job = getKey(process_name, lepton_selection_and_frWeight, chargeSumSelection, central_or_shift, jobId)
                ntupleFiles = inputFileList[jobId]
                if len(ntupleFiles) == 0:
                  logging.warning("No input ntuples for %s --> skipping job !!" % (key_analyze_job))
                  continue
                rootOutputFile = ""
                if self.select_root_output:
                  rootOutputFile = os.path.join(self.dirs[key_dir][DKEY_ROOT], "out_%s_%s_%s_%s_%s_%i.root" % \
                    (self.channel, process_name, lepton_selection_and_frWeight, chargeSumSelection, central_or_shift, jobId))
                  key_file_woJobId = getKey(process_name, lepton_selection_and_frWeight, chargeSumSelection, central_or_shift)
                  if key_file_woJobId not in self.rootOutputAux:
                    self.rootOutputAux[key_file_woJobId] = [ re.sub('_\d+\.root', '.root', rootOutputFile),
                                                             re.sub('\d+\.root', '*.root', rootOutputFile) ]

                syncOutput = ''
                syncTree = ''
                if self.do_sync:
                  if lepton_selection_and_frWeight == 'Tight' and chargeSumSelection == 'OS':
                    syncOutput = os.path.join(self.dirs[key_dir][DKEY_SYNC], '%s_SR.root' % self.channel)
                    syncTree   = 'syncTree_%s_SR' % self.channel.replace('_', '')
                  elif lepton_selection_and_frWeight == 'Fakeable_wFakeRateWeights' and chargeSumSelection == 'OS':
                    syncOutput = os.path.join(self.dirs[key_dir][DKEY_SYNC], '%s_Fake.root' % self.channel)
                    syncTree   = 'syncTree_%s_Fake' % self.channel.replace('_', '')
                  else:
                    continue
                  self.inputFiles_sync['sync'].append(syncOutput)

                syncRLE = ''
                if self.do_sync and self.rle_select:
                  syncRLE = self.rle_select % syncTree
                  if not os.path.isfile(syncRLE):
                    raise ValueError('Input RLE file for the sync is missing: %s' % syncRLE)

                self.jobOptions_analyze[key_analyze_job] = {
                  'ntupleFiles' : ntupleFiles,
                  'cfgFile_modified' : os.path.join(self.dirs[key_dir][DKEY_CFGS], "analyze_%s_%s_%s_%s_%s_%i_cfg.py" % \
                    (self.channel, process_name, lepton_selection_and_frWeight, chargeSumSelection, central_or_shift, jobId)),
                  'histogramFile' : os.path.join(self.dirs[key_dir][DKEY_HIST], "%s_%s_%s_%s_%i.root" % \
                    (process_name, lepton_selection_and_frWeight, chargeSumSelection, central_or_shift, jobId)),
                  'logFile' : os.path.join(self.dirs[key_dir][DKEY_LOGS], "analyze_%s_%s_%s_%s_%s_%i.log" % \
                    (self.channel, process_name, lepton_selection_and_frWeight, chargeSumSelection, central_or_shift, jobId)),
                  'rleOutputFile' : os.path.join(self.dirs[key_dir][DKEY_RLES], "rle_%s_%s_%s_%s_%s_%i.txt" % \
                    (self.channel, process_name, lepton_selection_and_frWeight, chargeSumSelection, central_or_shift, jobId)) if self.select_rle_output else "",
                  'rootOutputFile' : rootOutputFile,
                  'sample_category' : sample_category,
                  'triggers' : sample_info["triggers"],
                  'lepton_selection' : lepton_selection,
                  'apply_leptonGenMatching' : self.apply_leptonGenMatching,
                  'chargeSumSelection' : chargeSumSelection,
                  'applyFakeRateWeights' : self.applyFakeRateWeights if not lepton_selection == "Tight" else "disabled",
                  ##'use_HIP_mitigation_mediumMuonId' : sample_info["use_HIP_mitigation_mediumMuonId"],
                  'use_HIP_mitigation_mediumMuonId' : False,
                  'is_mc' : is_mc,
                  'central_or_shift' : central_or_shift,
                  'lumi_scale' : 1. if not (self.use_lumi and is_mc) else sample_info["xsection"] * self.lumi / sample_info["nof_events"],
                  'apply_genWeight' : sample_info["genWeight"] if (is_mc and "genWeight" in sample_info) else False,
                  'apply_trigger_bits' : (is_mc and sample_info["reHLT"]) or not is_mc,
                  'selectBDT': self.isBDTtraining,
                  'syncOutput': syncOutput,
                  'syncTree'  : syncTree,
                  'syncRLE'   : syncRLE,
                }
                self.createCfg_analyze(self.jobOptions_analyze[key_analyze_job])

                # initialize input and output file names for hadd_stage1
                key_hadd_stage1 = getKey(process_name, lepton_selection_and_frWeight, chargeSumSelection)
                if not key_hadd_stage1 in self.inputFiles_hadd_stage1:
                  self.inputFiles_hadd_stage1[key_hadd_stage1] = []
                self.inputFiles_hadd_stage1[key_hadd_stage1].append(self.jobOptions_analyze[key_analyze_job]['histogramFile'])
                self.outputFile_hadd_stage1[key_hadd_stage1] = os.path.join(self.dirs[DKEY_HIST], "histograms_harvested_stage1_%s_%s_%s_%s.root" % \
                  (self.channel, process_name, lepton_selection_and_frWeight, chargeSumSelection))

            if self.isBDTtraining or self.do_sync:
              continue

            if is_mc:
              logging.info("Creating configuration files to run 'addBackgrounds' for sample %s" % process_name)

              sample_categories = [ sample_category ]
              if is_signal:
                sample_categories = [ "signal", "ttH", "ttH_htt", "ttH_hww", "ttH_hzz" ]
              for sample_category in sample_categories:
                # sum non-fake and fake contributions for each MC sample separately
                genMatch_categories = [ "nonfake", "fake" ]

                for genMatch_category in genMatch_categories:
                  key_hadd_stage1 = getKey(process_name, lepton_selection_and_frWeight, chargeSumSelection)
                  key_addBackgrounds_job = None
                  processes_input = None
                  process_output = None
                  cfgFile_modified = None
                  outputFile = None
                  if genMatch_category == "nonfake":
                    # sum non-fake contributions for each MC sample separately
                    # input processes: TT4l0j,...
                    # output processes: TT; ...
                    if sample_category in [ "signal" ]:
                      lepton_genMatches = []
                      lepton_genMatches.extend(self.lepton_genMatches_nonfakes)
                      lepton_genMatches.extend(self.lepton_genMatches_fakes)
                      processes_input = [ "%s%s" % (sample_category, genMatch) for genMatch in lepton_genMatches ]
                    elif sample_category in [ "ttH" ]:
                      processes_input = []
                      processes_input.extend([ "%s%s" % ("ttH_htt", genMatch) for genMatch in self.lepton_genMatches_nonfakes ])
                      processes_input.extend([ "%s%s" % ("ttH_hww", genMatch) for genMatch in self.lepton_genMatches_nonfakes ])
                      processes_input.extend([ "%s%s" % ("ttH_hzz", genMatch) for genMatch in self.lepton_genMatches_nonfakes ])
                    else:
                      processes_input = [ "%s%s" % (sample_category, genMatch) for genMatch in self.lepton_genMatches_nonfakes ]
                    process_output = sample_category
                    key_addBackgrounds_job = getKey(process_name, sample_category, lepton_selection_and_frWeight, chargeSumSelection)
                    cfgFile_modified = os.path.join(self.dirs[DKEY_CFGS], "addBackgrounds_%s_%s_%s_%s_%s_cfg.py" % \
                      (self.channel, process_name, sample_category, lepton_selection_and_frWeight, chargeSumSelection))
                    outputFile = os.path.join(self.dirs[DKEY_HIST], "addBackgrounds_%s_%s_%s_%s_%s.root" % \
                      (self.channel, process_name, sample_category, lepton_selection_and_frWeight, chargeSumSelection))
                  elif genMatch_category == "fake":
                    # sum fake contributions for each MC sample separately
                    # input processes: TT2l1j,TT1l2j,TT0l3j,...
                    # output processes: TT_fake; ...
                    if sample_category in [ "signal" ]:
                      processes_input = [ "%s%s" % (sample_category, genMatch) for genMatch in self.lepton_genMatches_fakes ]
                    elif sample_category in [ "ttH" ]:
                      processes_input = []
                      processes_input.extend([ "%s%s" % ("ttH_htt", genMatch) for genMatch in self.lepton_genMatches_fakes ])
                      processes_input.extend([ "%s%s" % ("ttH_hww", genMatch) for genMatch in self.lepton_genMatches_fakes ])
                      processes_input.extend([ "%s%s" % ("ttH_hzz", genMatch) for genMatch in self.lepton_genMatches_fakes ])
                    else:
                      processes_input = [ "%s%s" % (sample_category, genMatch) for genMatch in self.lepton_genMatches_fakes ]
                    process_output = "%s_fake" % sample_category
                    key_addBackgrounds_job = getKey(process_name, "%s_fake" % sample_category, lepton_selection_and_frWeight, chargeSumSelection)
                    cfgFile_modified = os.path.join(self.dirs[DKEY_CFGS], "addBackgrounds_%s_fakes_%s_%s_%s_%s_cfg.py" % \
                      (self.channel, process_name, sample_category, lepton_selection_and_frWeight, chargeSumSelection))
                    outputFile = os.path.join(self.dirs[DKEY_HIST], "addBackgrounds_%s_fakes_%s_%s_%s_%s.root" % \
                      (self.channel, process_name, sample_category, lepton_selection_and_frWeight, chargeSumSelection))
                  if processes_input:
                    logging.info(" ...for genMatch option = '%s'" % genMatch_category)
                    self.jobOptions_addBackgrounds[key_addBackgrounds_job] = {
                      'inputFile' : self.outputFile_hadd_stage1[key_hadd_stage1],
                      'cfgFile_modified' : cfgFile_modified,
                      'outputFile' : outputFile,
                      'logFile' : os.path.join(self.dirs[DKEY_LOGS], os.path.basename(cfgFile_modified).replace("_cfg.py", ".log")),
                      'categories' : [ getHistogramDir(lepton_selection, lepton_frWeight, chargeSumSelection) ],
                      'processes_input' : processes_input,
                      'process_output' : process_output
                    }
                    self.createCfg_addBackgrounds(self.jobOptions_addBackgrounds[key_addBackgrounds_job])

                    # initialize input and output file names for hadd_stage1_5
                    key_hadd_stage1_5 = getKey(lepton_selection_and_frWeight, chargeSumSelection)
                    if not key_hadd_stage1_5 in self.inputFiles_hadd_stage1_5:
                      self.inputFiles_hadd_stage1_5[key_hadd_stage1_5] = []
                    self.inputFiles_hadd_stage1_5[key_hadd_stage1_5].append(self.jobOptions_addBackgrounds[key_addBackgrounds_job]['outputFile'])
                    self.outputFile_hadd_stage1_5[key_hadd_stage1_5] = os.path.join(self.dirs[DKEY_HIST], "histograms_harvested_stage1_5_%s_%s_%s.root" % \
                     (self.channel, lepton_selection_and_frWeight, chargeSumSelection))

            if self.isBDTtraining or self.do_sync:
              continue

            # add output files of hadd_stage1 for data to list of input files for hadd_stage1_5
            if not is_mc:
              key_hadd_stage1 = getKey(process_name, lepton_selection_and_frWeight, chargeSumSelection)
              key_hadd_stage1_5 = getKey(lepton_selection_and_frWeight, chargeSumSelection)
              if not key_hadd_stage1_5 in self.inputFiles_hadd_stage1_5:
                self.inputFiles_hadd_stage1_5[key_hadd_stage1_5] = []
              self.inputFiles_hadd_stage1_5[key_hadd_stage1_5].append(self.outputFile_hadd_stage1[key_hadd_stage1])

          if self.isBDTtraining or self.do_sync:
            continue

          # sum fake contributions for the total of all MC sample
          # input processes: TT2l1j,TT1l2j,TT0l3j,...
          # output process: fakes_mc
          key_addBackgrounds_job = getKey(lepton_selection_and_frWeight, chargeSumSelection)
          sample_categories = []
          sample_categories.extend(self.nonfake_backgrounds)
          sample_categories.extend([ "signal" ])
          processes_input = []
          for sample_category in sample_categories:
            processes_input.append("%s_fake" % sample_category)
          self.jobOptions_addBackgrounds_sum[key_addBackgrounds_job] = {
            'inputFile' : self.outputFile_hadd_stage1_5[key_hadd_stage1_5],
            'cfgFile_modified' : os.path.join(self.dirs[DKEY_CFGS], "addBackgrounds_%s_fakes_mc_%s_%s_cfg.py" % \
              (self.channel, lepton_selection_and_frWeight, chargeSumSelection)),
            'outputFile' : os.path.join(self.dirs[DKEY_HIST], "addBackgrounds_%s_fakes_mc_%s_%s.root" % \
              (self.channel, lepton_selection_and_frWeight, chargeSumSelection)),
            'logFile' : os.path.join(self.dirs[DKEY_LOGS], "addBackgrounds_%s_fakes_mc_%s_%s.log" % \
              (self.channel, lepton_selection_and_frWeight, chargeSumSelection)),
            'categories' : [ getHistogramDir(lepton_selection, lepton_frWeight, chargeSumSelection) ],
            'processes_input' : processes_input,
            'process_output' : "fakes_mc"
          }
          self.createCfg_addBackgrounds(self.jobOptions_addBackgrounds_sum[key_addBackgrounds_job])

          # initialize input and output file names for hadd_stage2
          key_hadd_stage2 = getKey(lepton_selection_and_frWeight, chargeSumSelection)
          if not key_hadd_stage2 in self.inputFiles_hadd_stage2:
            self.inputFiles_hadd_stage2[key_hadd_stage2] = []
          if lepton_selection == "Tight":
            self.inputFiles_hadd_stage2[key_hadd_stage2].append(self.jobOptions_addBackgrounds_sum[key_addBackgrounds_job]['outputFile'])
          key_hadd_stage1_5 = getKey(lepton_selection_and_frWeight, chargeSumSelection)
          self.inputFiles_hadd_stage2[key_hadd_stage2].append(self.outputFile_hadd_stage1_5[key_hadd_stage1_5])
          self.outputFile_hadd_stage2[key_hadd_stage2] = os.path.join(self.dirs[DKEY_HIST], "histograms_harvested_stage2_%s_%s_%s.root" % \
            (self.channel, lepton_selection_and_frWeight, chargeSumSelection))

    if self.isBDTtraining or self.do_sync:
      if self.is_sbatch:
        logging.info("Creating script for submitting '%s' jobs to batch system" % self.executable_analyze)
        self.sbatchFile_analyze = os.path.join(self.dirs[DKEY_SCRIPTS], "sbatch_analyze_%s.py" % self.channel)
        if self.isBDTtraining:
          self.createScript_sbatch_analyze(self.executable_analyze, self.sbatchFile_analyze, self.jobOptions_analyze)
        elif self.do_sync:
          self.createScript_sbatch_syncNtuple(self.executable_analyze, self.sbatchFile_analyze, self.jobOptions_analyze)
      logging.info("Creating Makefile")
      lines_makefile = []
      if self.isBDTtraining:
        self.addToMakefile_analyze(lines_makefile)
        self.addToMakefile_hadd_stage1(lines_makefile)
      elif self.do_sync:
        self.addToMakefile_syncNtuple(lines_makefile)
        outputFile_sync_path = os.path.join(self.outputDir, DKEY_SYNC, '%s.root' % self.channel)
        self.outputFile_sync['sync'] = outputFile_sync_path
        self.targets.append(outputFile_sync_path)
        self.addToMakefile_hadd_sync(lines_makefile)
      else:
        raise ValueError("Internal logic error")
      self.createMakefile(lines_makefile)
      logging.info("Done")
      return self.num_jobs

    logging.info("Creating configuration files to run 'addBackgroundFakes'")
    for chargeSumSelection in self.chargeSumSelections:
      key_addFakes_job = getKey("fakes_data", chargeSumSelection)
      key_hadd_stage1_5 = getKey(get_lepton_selection_and_frWeight("Fakeable", "enabled"), chargeSumSelection)
      category_sideband = "4l_%s_Fakeable" % chargeSumSelection
      self.jobOptions_addFakes[key_addFakes_job] = {
        'inputFile' : self.outputFile_hadd_stage1_5[key_hadd_stage1_5],
        'cfgFile_modified' : os.path.join(self.dirs[DKEY_CFGS], "addBackgroundLeptonFakes_%s_%s_cfg.py" % \
          (self.channel, chargeSumSelection)),
        'outputFile' : os.path.join(self.dirs[DKEY_HIST], "addBackgroundLeptonFakes_%s_%s.root" % \
          (self.channel, chargeSumSelection)),
        'logFile' : os.path.join(self.dirs[DKEY_LOGS], "addBackgroundLeptonFakes_%s_%s.log" % \
          (self.channel, chargeSumSelection)),
        'category_signal' : "4l_%s_Tight" % chargeSumSelection,
        'category_sideband' : category_sideband
      }
      self.createCfg_addFakes(self.jobOptions_addFakes[key_addFakes_job])
      key_hadd_stage2 = getKey(get_lepton_selection_and_frWeight("Tight", "disabled"), chargeSumSelection)
      self.inputFiles_hadd_stage2[key_hadd_stage2].append(self.jobOptions_addFakes[key_addFakes_job]['outputFile'])

    logging.info("Creating configuration files to run 'prepareDatacards'")
    for histogramToFit in self.histograms_to_fit:
      key_prep_dcard_job = getKey(histogramToFit)
      key_hadd_stage2 = getKey(get_lepton_selection_and_frWeight("Tight", "disabled"), "OS")
      self.jobOptions_prep_dcard[key_prep_dcard_job] = {
        'inputFile' : self.outputFile_hadd_stage2[key_hadd_stage2],
        'cfgFile_modified' : os.path.join(self.dirs[DKEY_CFGS], "prepareDatacards_%s_%s_cfg.py" % (self.channel, histogramToFit)),
        'datacardFile' : os.path.join(self.dirs[DKEY_DCRD], "prepareDatacards_%s_%s.root" % (self.channel, histogramToFit)),
        'histogramDir' : self.histogramDir_prep_dcard,
        'histogramToFit' : histogramToFit,
        'label' : None
      }
      self.createCfg_prep_dcard(self.jobOptions_prep_dcard[key_prep_dcard_job])

      if "SS" in self.chargeSumSelections:
        key_prep_dcard_job = getKey(histogramToFit, "SS")
        key_hadd_stage2 = getKey(get_lepton_selection_and_frWeight("Tight", "disabled"), "SS")
        self.jobOptions_prep_dcard[key_prep_dcard_job] = {
          'inputFile' : self.outputFile_hadd_stage2[key_hadd_stage2],
          'cfgFile_modified' : os.path.join(self.dirs[DKEY_CFGS], "prepareDatacards_%s_SS_%s_cfg.py" % (self.channel, histogramToFit)),
          'datacardFile' : os.path.join(self.dirs[DKEY_DCRD], "prepareDatacards_%s_SS_%s.root" % (self.channel, histogramToFit)),
          'histogramDir' : self.histogramDir_prep_dcard_SS,
          'histogramToFit' : histogramToFit,
          'label' : 'SS'
        }
        self.createCfg_prep_dcard(self.jobOptions_prep_dcard[key_prep_dcard_job])

    logging.info("Creating configuration files to run 'makePlots'")
    key_makePlots_job = getKey("OS")
    key_hadd_stage2 = getKey(get_lepton_selection_and_frWeight("Tight", "disabled"), "OS")
    self.jobOptions_make_plots[key_makePlots_job] = {
      'executable' : self.executable_make_plots,
      'inputFile' : self.outputFile_hadd_stage2[key_hadd_stage2],
      'cfgFile_modified' : os.path.join(self.dirs[DKEY_CFGS], "makePlots_%s_cfg.py" % self.channel),
      'outputFile' : os.path.join(self.dirs[DKEY_PLOT], "makePlots_%s.png" % self.channel),
      'histogramDir' : self.histogramDir_prep_dcard,
      'label' : None,
      'make_plots_backgrounds' : self.make_plots_backgrounds
    }
    self.createCfg_makePlots(self.jobOptions_make_plots[key_makePlots_job])
    if "SS" in self.chargeSumSelections:
      key_makePlots_job = getKey("SS")
      key_hadd_stage2 = getKey(get_lepton_selection_and_frWeight("Tight", "disabled"), "SS")
      self.jobOptions_make_plots[key_makePlots_job] = {
        'executable' : self.executable_make_plots,
        'inputFile' : self.outputFile_hadd_stage2[key_hadd_stage2],
        'cfgFile_modified' : os.path.join(self.dirs[DKEY_CFGS], "makePlots_%s_SS_cfg.py" % self.channel),
        'outputFile' : os.path.join(self.dirs[DKEY_PLOT], "makePlots_%s_SS.png" % self.channel),
        'histogramDir' : self.histogramDir_prep_dcard_SS,
        'label' : "SS",
        'make_plots_backgrounds' : self.make_plots_backgrounds
      }
      self.createCfg_makePlots(self.jobOptions_make_plots[key_makePlots_job])
    if "Fakeable_mcClosure" in self.lepton_selections:
      key_makePlots_job = getKey("OS")
      key_hadd_stage2 = getKey(get_lepton_selection_and_frWeight("Tight", "disabled"), "OS")
      self.jobOptions_make_plots[key_makePlots_job] = {
        'executable' : self.executable_make_plots_mcClosure,
        'inputFile' : self.outputFile_hadd_stage2[key_hadd_stage2],
        'cfgFile_modified' : os.path.join(self.dirs[DKEY_CFGS], "makePlots_mcClosure_%s_cfg.py" % self.channel),
        'outputFile' : os.path.join(self.dirs[DKEY_PLOT], "makePlots_mcClosure_%s.png" % self.channel)
      }
      self.createCfg_makePlots_mcClosure(self.jobOptions_make_plots[key_makePlots_job])

    if self.is_sbatch:
      logging.info("Creating script for submitting '%s' jobs to batch system" % self.executable_analyze)
      self.sbatchFile_analyze = os.path.join(self.dirs[DKEY_SCRIPTS], "sbatch_analyze_%s.py" % self.channel)
      self.createScript_sbatch_analyze(self.executable_analyze, self.sbatchFile_analyze, self.jobOptions_analyze)
      logging.info("Creating script for submitting '%s' jobs to batch system" % self.executable_addBackgrounds)
      self.sbatchFile_addBackgrounds = os.path.join(self.dirs[DKEY_SCRIPTS], "sbatch_addBackgrounds_%s.py" % self.channel)
      self.createScript_sbatch(self.executable_addBackgrounds, self.sbatchFile_addBackgrounds, self.jobOptions_addBackgrounds)
      self.sbatchFile_addBackgrounds_sum = os.path.join(self.dirs[DKEY_SCRIPTS], "sbatch_addBackgrounds_sum_%s.py" % self.channel)
      self.createScript_sbatch(self.executable_addBackgrounds, self.sbatchFile_addBackgrounds_sum, self.jobOptions_addBackgrounds_sum)
      logging.info("Creating script for submitting '%s' jobs to batch system" % self.executable_addFakes)
      self.sbatchFile_addFakes = os.path.join(self.dirs[DKEY_SCRIPTS], "sbatch_addFakes_%s.py" % self.channel)
      self.createScript_sbatch(self.executable_addFakes, self.sbatchFile_addFakes, self.jobOptions_addFakes)

    logging.info("Creating Makefile")
    lines_makefile = []
    self.addToMakefile_analyze(lines_makefile)
    self.addToMakefile_hadd_stage1(lines_makefile)
    self.addToMakefile_backgrounds_from_data(lines_makefile)
    self.addToMakefile_hadd_stage2(lines_makefile)
    self.addToMakefile_prep_dcard(lines_makefile)
    self.addToMakefile_add_syst_dcard(lines_makefile)
    self.addToMakefile_make_plots(lines_makefile)
    self.createMakefile(lines_makefile)

    logging.info("Done")

    return self.num_jobs