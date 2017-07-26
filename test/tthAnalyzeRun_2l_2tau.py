#!/usr/bin/env python
import os, logging, sys, getpass

from tthAnalysis.HiggsToTauTau.analyzeConfig_2l_2tau import analyzeConfig_2l_2tau
from tthAnalysis.HiggsToTauTau.jobTools import query_yes_no

mode = "VHbb"

hadTau_selection = None
changeBranchNames = None
applyFakeRateWeights = None
if mode == "VHbb":
  from tthAnalysis.HiggsToTauTau.tthAnalyzeSamples_2l_2tau_2015 import samples_2015
  from tthAnalysis.HiggsToTauTau.tthAnalyzeSamples_2l_2tau_2016 import samples_2016
  hadTau_selection = "dR03mvaMedium"
  changeBranchNames = False
  applyFakeRateWeights = "2lepton"
else:
  raise ValueError("Invalid Configuration parameter 'mode' = %s !!" % mode)

#ERA = "2015"
ERA = "2016"

samples = None
LUMI = None
if ERA == "2015":
  samples = samples_2015
  LUMI =  2.3e+3 # 1/pb
elif ERA == "2016":
  samples = samples_2016
  LUMI = 35.9e+3 # 1/pb
else:
  raise ValueError("Invalid Configuration parameter 'ERA' = %s !!" % ERA)

version = "2017May10"

if __name__ == '__main__':
  logging.basicConfig(
    stream = sys.stdout,
    level = logging.INFO,
    format = '%(asctime)s - %(levelname)s: %(message)s')

  analysis = analyzeConfig_2l_2tau(
    configDir = os.path.join("/home", getpass.getuser(), "ttHAnalysis", ERA, version),
    outputDir = os.path.join("/hdfs/local", getpass.getuser(), "ttHAnalysis", ERA, version),
    executable_analyze = "analyze_2l_2tau",
    cfgFile_analyze = "analyze_2l_2tau_cfg.py",
    samples = samples,
    changeBranchNames = changeBranchNames,
    lepton_charge_selections = [ "OS" ],
    hadTau_selections = hadTau_selection,
    hadTau_charge_selections = [ "OS", "SS" ],
    applyFakeRateWeights = applyFakeRateWeights,
    chargeSumSelections  = [ "OS", "SS" ],
    central_or_shifts = [ 
      "central",
##       "CMS_ttHl_btag_HFUp", 
##       "CMS_ttHl_btag_HFDown",	
##       "CMS_ttHl_btag_HFStats1Up", 
##       "CMS_ttHl_btag_HFStats1Down",
##       "CMS_ttHl_btag_HFStats2Up", 
##       "CMS_ttHl_btag_HFStats2Down",
##       "CMS_ttHl_btag_LFUp", 
##       "CMS_ttHl_btag_LFDown",	
##       "CMS_ttHl_btag_LFStats1Up", 
##       "CMS_ttHl_btag_LFStats1Down",
##       "CMS_ttHl_btag_LFStats2Up", 
##       "CMS_ttHl_btag_LFStats2Down",
##       "CMS_ttHl_btag_cErr1Up",
##       "CMS_ttHl_btag_cErr1Down",
##       "CMS_ttHl_btag_cErr2Up",
##       "CMS_ttHl_btag_cErr2Down",
##       "CMS_ttHl_JESUp",
##       "CMS_ttHl_JESDown",
##       "CMS_ttHl_tauESUp",
##       "CMS_ttHl_tauESDown",
##       "CMS_ttHl_FRjt_normUp",
##       "CMS_ttHl_FRjt_normDown",
##       "CMS_ttHl_FRjt_shapeUp",
##       "CMS_ttHl_FRjt_shapeDown"
##       "CMS_ttHl_FRet_shiftUp",
##       "CMS_ttHl_FRet_shiftDown",
##       "CMS_ttHl_FRmt_shiftUp",
##       "CMS_ttHl_FRmt_shiftDown",
##       "CMS_ttHl_thu_shape_ttH_x1Up",  
##       "CMS_ttHl_thu_shape_ttH_x1Down",
##       "CMS_ttHl_thu_shape_ttH_y1Up",   
##       "CMS_ttHl_thu_shape_ttH_y1Down",
##       "CMS_ttHl_thu_shape_ttW_x1Up",
##       "CMS_ttHl_thu_shape_ttW_x1Down",
##       "CMS_ttHl_thu_shape_ttW_y1Up",
##       "CMS_ttHl_thu_shape_ttW_y1Down",
##       "CMS_ttHl_thu_shape_ttZ_x1Up",
##       "CMS_ttHl_thu_shape_ttZ_x1Down",
##       "CMS_ttHl_thu_shape_ttZ_y1Up",
##       "CMS_ttHl_thu_shape_ttZ_y1Down"       
    ],
    max_files_per_job = 100,
    era = ERA,
    use_lumi = True,
    lumi = LUMI,
    debug = False,
    running_method = "sbatch",
    num_parallel_jobs = 8,
    executable_addBackgrounds = "addBackgrounds",
    executable_addBackgroundJetToTauFakes = "addBackgroundLeptonFakes", # CV: use common executable for estimating jet->lepton and jet->tau_h fake background
    histograms_to_fit = [ "EventCounter", "numJets", "mTauTauVis" ],
    select_rle_output = True)

  analysis.create()

  run_analysis = query_yes_no("Start jobs ?")
  ##run_analysis = True
  if run_analysis:
    analysis.run()
  else:
    sys.exit(0)

