from collections import OrderedDict as OD

# file generated at 2018-06-29 19:45:24 with the following command:
# find_samples.py -V -i ../NanoAOD/test/datasets_mc_2017.txt -m python/samples/metaDict_2017_mc.py -c /hdfs/cms/store/user/kaehatah/NanoProduction_v2_2018Apr26 /hdfs/cms/store/user/kaehatah/NanoProduction_v2_2018Jun08 /hdfs/cms/store/user/kaehatah/NanoProduction_v2_2018Jun12

meta_dictionary = OD()


### event sums

sum_events = {
  ("DY1JetsToLL_M-50", "DY1JetsToLL_M-50_ext1"),
  ("DY2JetsToLL_M-50", "DY2JetsToLL_M-50_ext1"),
  ("DY3JetsToLL_M-50", "DY3JetsToLL_M-50_ext1"),
  ("DYJetsToLL_M-4to50_HT-100to200", "DYJetsToLL_M-4to50_HT-100to200_ext1"),
  ("DYJetsToLL_M-4to50_HT-200to400", "DYJetsToLL_M-4to50_HT-200to400_ext1"),
  ("DYJetsToLL_M-4to50_HT-400to600", "DYJetsToLL_M-4to50_HT-400to600_ext1"),
  ("DYJetsToLL_M-4to50_HT-70to100", "DYJetsToLL_M-4to50_HT-70to100_ext1"),
  ("DYJetsToLL_M-50", "DYJetsToLL_M-50_ext1"),
  ("DYJetsToLL_M50_HT100to200", "DYJetsToLL_M50_HT100to200_ext1"),
  ("DYJetsToLL_M50_HT200to400", "DYJetsToLL_M50_HT200to400_ext1"),
  ("DYJetsToLL_M50_HT400to600", "DYJetsToLL_M50_HT400to600_ext1"),
  ("GluGluHToZZTo4L", "GluGluHToZZTo4L_ext1"),
  ("ST_s-channel_4f_leptonDecays", "ST_s-channel_4f_leptonDecays_PSweights"),
  ("ST_tW_top_5f_inclusiveDecays", "ST_tW_top_5f_inclusiveDecays_PSweights"),
  ("TTGJets", "TTGJets_ext1"),
  ("TTTo2L2Nu", "TTTo2L2Nu_PSweights"),
  ("TTToHadronic", "TTToHadronic_PSweights"),
  ("TTToSemiLeptonic", "TTToSemiLeptonic_PSweights"),
  ("TTWJetsToLNu", "TTWJetsToLNu_PSweights"),
  ("TTZToLL_M10", "TTZToLL_M10_PSweights"),
  ("WWToLNuQQ", "WWToLNuQQ_ext1"),
  ("ZZTo4L", "ZZTo4L_ext1"),
}


meta_dictionary["/ttHJetToNonbb_M125_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ttHJetToNonbb_M125_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "signal"),
  ("process_name_specific", "ttHJetToNonbb_M125_amcatnlo"),
  ("nof_db_events",         9650032),
  ("nof_db_files",          283),
  ("fsize_db",              603282930374),
  ("xsection",              0.2118),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 603.28GB; nevents: 9.65M; release: 9_4_0_patch1; last modified: 2018-02-25 01:47:16"),
])

meta_dictionary["/ttHJetTobb_M125_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ttHJetTobb_M125_TuneCP5_13TeV_amcatnloFXFX_madspin_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "signal"),
  ("process_name_specific", "ttHJetTobb_M125_amcatnlo"),
  ("nof_db_events",         9911561),
  ("nof_db_files",          259),
  ("fsize_db",              626042445493),
  ("xsection",              0.2953),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 626.04GB; nevents: 9.91M; release: 9_4_0_patch1; last modified: 2018-02-24 15:48:57"),
])

meta_dictionary["/ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ttHToNonbb_M125_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "signal"),
  ("process_name_specific", "ttHToNonbb_M125_powheg"),
  ("nof_db_events",         7669336),
  ("nof_db_files",          219),
  ("fsize_db",              465938496839),
  ("xsection",              0.2118),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 465.94GB; nevents: 7.67M; release: 9_4_0_patch1; last modified: 2018-02-17 14:21:12"),
])

meta_dictionary["/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "additional_signal_overlap"),
  ("process_name_specific", "GluGluHToZZTo4L"),
  ("nof_db_events",         934244),
  ("nof_db_files",          47),
  ("fsize_db",              42622664498),
  ("xsection",              0.01212),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 42.62GB; nevents: 934.24k; release: 9_4_0_patch1; last modified: 2018-02-06 20:27:24"),
])

meta_dictionary["/GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_GluGluHToZZTo4L_M125_13TeV_powheg2_JHUGenV7011_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11_ext1-v1"),
  ("sample_category",       "additional_signal_overlap"),
  ("process_name_specific", "GluGluHToZZTo4L_ext1"),
  ("nof_db_events",         976214),
  ("nof_db_files",          42),
  ("fsize_db",              44846003614),
  ("xsection",              0.01212),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 44.85GB; nevents: 976.21k; release: 9_4_0_patch1; last modified: 2018-02-15 08:45:34"),
])

meta_dictionary["/TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTZToLLNuNu_M-10_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TTZ"),
  ("process_name_specific", "TTZToLL_M10"),
  ("nof_db_events",         7563490),
  ("nof_db_files",          199),
  ("fsize_db",              444833969271),
  ("xsection",              0.2529),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 444.83GB; nevents: 7.56M; release: 9_4_0_patch1; last modified: 2018-01-23 23:10:22"),
])

meta_dictionary["/TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_TTZToLLNuNu_M-10_TuneCP5_PSweights_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TTZ"),
  ("process_name_specific", "TTZToLL_M10_PSweights"),
  ("nof_db_events",         3208840),
  ("nof_db_files",          87),
  ("fsize_db",              189790811067),
  ("xsection",              0.2529),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: PRODUCTION; size: 189.79GB; nevents: 3.21M; release: 9_4_0_patch1; last modified: 2018-01-08 18:30:31"),
])

meta_dictionary["/TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTZToLL_M-1to10_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TTZ"),
  ("process_name_specific", "TTZToLL_M-1to10"),
  ("nof_db_events",         250000),
  ("nof_db_files",          17),
  ("fsize_db",              14727460148),
  ("xsection",              0.0493),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 14.73GB; nevents: 250.00k; release: 9_4_0_patch1; last modified: 2017-12-21 15:03:55"),
])

meta_dictionary["/ttZJets_TuneCP5_13TeV_madgraphMLM_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun12_ttZJets_TuneCP5_13TeV_madgraphMLM_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "TTZ"),
  ("process_name_specific", "TTZJets_LO"),
  ("nof_db_events",         9054309),
  ("nof_db_files",          241),
  ("fsize_db",              640897723581),
  ("xsection",              0.7655),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 640.90GB; nevents: 9.05M; release: 9_4_0_patch1; last modified: 2018-03-05 17:02:05"),
])

meta_dictionary["/TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTWJetsToLNu_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "TTW"),
  ("process_name_specific", "TTWJetsToLNu"),
  ("nof_db_events",         4925829),
  ("nof_db_files",          109),
  ("fsize_db",              292280765632),
  ("xsection",              0.2043),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 292.28GB; nevents: 4.93M; release: 9_4_0_patch1; last modified: 2018-02-08 17:33:34"),
])

meta_dictionary["/TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTWJetsToLNu_TuneCP5_PSweights_13TeV-amcatnloFXFX-madspin-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TTW"),
  ("process_name_specific", "TTWJetsToLNu_PSweights"),
  ("nof_db_events",         4889942),
  ("nof_db_files",          122),
  ("fsize_db",              290787551975),
  ("xsection",              0.2043),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 290.79GB; nevents: 4.89M; release: 9_4_0_patch1; last modified: 2018-02-17 16:02:45"),
])

meta_dictionary["/ttWJets_TuneCP5_13TeV_madgraphMLM_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun12_ttWJets_TuneCP5_13TeV_madgraphMLM_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TTW"),
  ("process_name_specific", "TTWJets_LO"),
  ("nof_db_events",         5216384),
  ("nof_db_files",          153),
  ("fsize_db",              310644652158),
  ("xsection",              0.6105),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 310.64GB; nevents: 5.22M; release: 9_4_0_patch1; last modified: 2018-03-16 03:52:42"),
])

meta_dictionary["/TTWW_TuneCP5_13TeV-madgraph-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTWW_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v2"),
  ("sample_category",       "TTWW"),
  ("process_name_specific", "TTWW"),
  ("nof_db_events",         200000),
  ("nof_db_files",          11),
  ("fsize_db",              13111885203),
  ("xsection",              0.007834),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 13.11GB; nevents: 200.00k; release: 9_4_0_patch1; last modified: 2018-03-03 05:02:52"),
])

meta_dictionary["/ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ST_s-channel_4f_leptonDecays_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "ST_s-channel_4f_leptonDecays"),
  ("nof_db_events",         9472619),
  ("nof_db_files",          217),
  ("fsize_db",              423862017407),
  ("xsection",              3.36),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 423.86GB; nevents: 9.47M; release: 9_4_0_patch1; last modified: 2018-01-20 12:40:35"),
])

meta_dictionary["/ST_s-channel_4f_leptonDecays_TuneCP5_PSweights_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_ST_s-channel_4f_leptonDecays_TuneCP5_PSweights_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "ST_s-channel_4f_leptonDecays_PSweights"),
  ("nof_db_events",         9787680),
  ("nof_db_files",          194),
  ("fsize_db",              440027990285),
  ("xsection",              3.36),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 440.03GB; nevents: 9.79M; release: 9_4_0_patch1; last modified: 2018-01-20 01:59:00"),
])

meta_dictionary["/ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ST_t-channel_antitop_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "ST_t-channel_antitop_4f_inclusiveDecays"),
  ("nof_db_events",         3891190),
  ("nof_db_files",          116),
  ("fsize_db",              177784436788),
  ("xsection",              80.95),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 177.78GB; nevents: 3.89M; release: 9_4_0_patch1; last modified: 2018-01-14 03:54:35"),
])

meta_dictionary["/ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ST_t-channel_top_4f_inclusiveDecays_TuneCP5_13TeV-powhegV2-madspin-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "ST_t-channel_top_4f_inclusiveDecays"),
  ("nof_db_events",         5841455),
  ("nof_db_files",          186),
  ("fsize_db",              268058212482),
  ("xsection",              136.02),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 268.06GB; nevents: 5.84M; release: 9_4_0_patch1; last modified: 2018-01-16 00:24:51"),
])

meta_dictionary["/ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ST_tW_antitop_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "ST_tW_antitop_5f_inclusiveDecays"),
  ("nof_db_events",         7756300),
  ("nof_db_files",          155),
  ("fsize_db",              386122494678),
  ("xsection",              35.85),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 386.12GB; nevents: 7.76M; release: 9_4_0_patch1; last modified: 2018-01-23 00:51:57"),
])

meta_dictionary["/ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ST_tW_top_5f_inclusiveDecays_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "ST_tW_top_5f_inclusiveDecays"),
  ("nof_db_events",         7558006),
  ("nof_db_files",          183),
  ("fsize_db",              376466493438),
  ("xsection",              35.85),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 376.47GB; nevents: 7.56M; release: 9_4_0_patch1; last modified: 2018-01-15 00:03:54"),
])

meta_dictionary["/ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_ST_tW_top_5f_inclusiveDecays_TuneCP5_PSweights_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "ST_tW_top_5f_inclusiveDecays_PSweights"),
  ("nof_db_events",         7636171),
  ("nof_db_files",          167),
  ("fsize_db",              381182108588),
  ("xsection",              35.85),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 381.18GB; nevents: 7.64M; release: 9_4_0_patch1; last modified: 2018-01-16 00:36:23"),
])

meta_dictionary["/TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTTo2L2Nu_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "TT"),
  ("process_name_specific", "TTTo2L2Nu"),
  ("nof_db_events",         8705576),
  ("nof_db_files",          164),
  ("fsize_db",              451436194017),
  ("xsection",              88.29),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 451.44GB; nevents: 8.71M; release: 9_4_0_patch1; last modified: 2018-01-09 22:02:38"),
])

meta_dictionary["/TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTTo2L2Nu_TuneCP5_PSweights_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "TTTo2L2Nu_PSweights"),
  ("nof_db_events",         69705626),
  ("nof_db_files",          1230),
  ("fsize_db",              3608766343800),
  ("xsection",              88.29),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 3.61TB; nevents: 69.71M; release: 9_4_0_patch1; last modified: 2018-01-11 15:10:21"),
])

meta_dictionary["/TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTToSemiLeptonic_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "TTToSemiLeptonic"),
  ("nof_db_events",         41161951),
  ("nof_db_files",          743),
  ("fsize_db",              2166068169129),
  ("xsection",              365.34),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 2.17TB; nevents: 41.16M; release: 9_4_0_patch1; last modified: 2018-02-01 21:28:40"),
])

meta_dictionary["/TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTToSemiLeptonic_TuneCP5_PSweights_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "TTToSemiLeptonic_PSweights"),
  ("nof_db_events",         111381888),
  ("nof_db_files",          2032),
  ("fsize_db",              5860979058540),
  ("xsection",              365.34),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 5.86TB; nevents: 111.38M; release: 9_4_0_patch1; last modified: 2018-01-11 00:38:22"),
])

meta_dictionary["/TTToHadronic_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTToHadronic_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "TTToHadronic"),
  ("nof_db_events",         42678688),
  ("nof_db_files",          765),
  ("fsize_db",              2292321642457),
  ("xsection",              377.96),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 2.29TB; nevents: 42.68M; release: 9_4_0_patch1; last modified: 2018-02-24 05:06:16"),
])

meta_dictionary["/TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTToHadronic_TuneCP5_PSweights_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "TT"),
  ("process_name_specific", "TTToHadronic_PSweights"),
  ("nof_db_events",         129985840),
  ("nof_db_files",          2498),
  ("fsize_db",              6970450887587),
  ("xsection",              377.96),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 6.97TB; nevents: 129.99M; release: 9_4_0_patch1; last modified: 2018-01-24 23:15:56"),
])

meta_dictionary["/DYJetsToLL_M-10to50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_DYJetsToLL_M-10to50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-10to50"),
  ("nof_db_events",         38832197),
  ("nof_db_files",          508),
  ("fsize_db",              1343136870100),
  ("xsection",              18610.0),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.34TB; nevents: 38.83M; release: 9_4_0_patch1; last modified: 2018-02-26 22:05:21"),
])

meta_dictionary["/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-50"),
  ("nof_db_events",         26923935),
  ("nof_db_files",          372),
  ("fsize_db",              1065736102325),
  ("xsection",              5765.4),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.07TB; nevents: 26.92M; release: 9_4_0_patch1; last modified: 2018-01-11 00:33:57"),
])

meta_dictionary["/DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_DYJetsToLL_M-50_TuneCP5_13TeV-amcatnloFXFX-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-50_ext1"),
  ("nof_db_events",         185998625),
  ("nof_db_files",          2752),
  ("fsize_db",              7376341087077),
  ("xsection",              5765.4),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 7.38TB; nevents: 186.00M; release: 9_4_0_patch1; last modified: 2018-02-19 14:25:32"),
])

meta_dictionary["/DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DY1JetsToLL_M-50"),
  ("nof_db_events",         32553254),
  ("nof_db_files",          489),
  ("fsize_db",              1356866452326),
  ("xsection",              878.0),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.36TB; nevents: 32.55M; release: 9_4_0_patch1; last modified: 2017-12-09 03:07:19"),
])

meta_dictionary["/DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DY1JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DY1JetsToLL_M-50_ext1"),
  ("nof_db_events",         34376824),
  ("nof_db_files",          510),
  ("fsize_db",              1428623935923),
  ("xsection",              878.0),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.43TB; nevents: 34.38M; release: 9_4_0_patch1; last modified: 2018-01-17 05:08:13"),
])

meta_dictionary["/DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DY2JetsToLL_M-50"),
  ("nof_db_events",         11623646),
  ("nof_db_files",          209),
  ("fsize_db",              522789471860),
  ("xsection",              307.0),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 522.79GB; nevents: 11.62M; release: 9_4_0_patch1; last modified: 2017-12-12 05:32:20"),
])

meta_dictionary["/DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DY2JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DY2JetsToLL_M-50_ext1"),
  ("nof_db_events",         9701595),
  ("nof_db_files",          204),
  ("fsize_db",              437224450591),
  ("xsection",              307.0),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 437.22GB; nevents: 9.70M; release: 9_4_0_patch1; last modified: 2018-01-07 04:17:49"),
])

meta_dictionary["/DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DY3JetsToLL_M-50"),
  ("nof_db_events",         4779068),
  ("nof_db_files",          132),
  ("fsize_db",              223702455084),
  ("xsection",              112.0),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 223.70GB; nevents: 4.78M; release: 9_4_0_patch1; last modified: 2018-01-26 23:33:10"),
])

meta_dictionary["/DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DY3JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DY3JetsToLL_M-50_ext1"),
  ("nof_db_events",         1149467),
  ("nof_db_files",          48),
  ("fsize_db",              53586240898),
  ("xsection",              112.0),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 53.59GB; nevents: 1.15M; release: 9_4_0_patch1; last modified: 2018-02-22 00:35:31"),
])

meta_dictionary["/DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DY4JetsToLL_M-50_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DY4JetsToLL_M-50"),
  ("nof_db_events",         4337967),
  ("nof_db_files",          163),
  ("fsize_db",              223554118058),
  ("xsection",              44.2),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 223.55GB; nevents: 4.34M; release: 9_4_0_patch1; last modified: 2018-02-05 19:13:21"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-70to100"),
  ("nof_db_events",         8995670),
  ("nof_db_files",          183),
  ("fsize_db",              405068200207),
  ("xsection",              145.4),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 405.07GB; nevents: 9.00M; release: 9_4_0_patch1; last modified: 2018-01-17 05:07:35"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-70to100_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-70to100_ext1"),
  ("nof_db_events",         8859396),
  ("nof_db_files",          192),
  ("fsize_db",              401795378611),
  ("xsection",              145.4),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 401.80GB; nevents: 8.86M; release: 9_4_0_patch1; last modified: 2018-03-03 17:55:29"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-100to200"),
  ("nof_db_events",         8796005),
  ("nof_db_files",          246),
  ("fsize_db",              379888624037),
  ("xsection",              202.8),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 379.89GB; nevents: 8.80M; release: 9_4_0_patch1; last modified: 2018-01-17 05:05:38"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-100to200_ext1"),
  ("nof_db_events",         1026278),
  ("nof_db_files",          37),
  ("fsize_db",              43976270871),
  ("xsection",              202.8),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 43.98GB; nevents: 1.03M; release: 9_4_0_patch1; last modified: 2018-03-03 17:55:10"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-200to400"),
  ("nof_db_events",         1816239),
  ("nof_db_files",          62),
  ("fsize_db",              85691967328),
  ("xsection",              53.7),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 85.69GB; nevents: 1.82M; release: 9_4_0_patch1; last modified: 2018-02-05 19:12:52"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-200to400_ext1"),
  ("nof_db_events",         998174),
  ("nof_db_files",          39),
  ("fsize_db",              47401830877),
  ("xsection",              53.7),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 47.40GB; nevents: 998.17k; release: 9_4_0_patch1; last modified: 2018-02-18 23:53:15"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-400to600"),
  ("nof_db_events",         1843245),
  ("nof_db_files",          58),
  ("fsize_db",              96569994025),
  ("xsection",              5.66),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 96.57GB; nevents: 1.84M; release: 9_4_0_patch1; last modified: 2018-02-06 20:28:48"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-400to600_ext1"),
  ("nof_db_events",         989624),
  ("nof_db_files",          41),
  ("fsize_db",              52601135552),
  ("xsection",              5.66),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 52.60GB; nevents: 989.62k; release: 9_4_0_patch1; last modified: 2018-02-17 16:08:28"),
])

meta_dictionary["/DYJetsToLL_M-4to50_HT-600toInf_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-4to50_HT-600toInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M-4to50_HT-600toInf"),
  ("nof_db_events",         1771556),
  ("nof_db_files",          89),
  ("fsize_db",              102005502328),
  ("xsection",              1.852),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 102.01GB; nevents: 1.77M; release: 9_4_0_patch1; last modified: 2018-02-01 02:17:16"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT100to200"),
  ("nof_db_events",         10031487),
  ("nof_db_files",          197),
  ("fsize_db",              474917399610),
  ("xsection",              173.988),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 474.92GB; nevents: 10.03M; release: 9_4_0_patch1; last modified: 2018-01-11 16:33:51"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-100to200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT100to200_ext1"),
  ("nof_db_events",         3910157),
  ("nof_db_files",          101),
  ("fsize_db",              182693208611),
  ("xsection",              173.988),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 182.69GB; nevents: 3.91M; release: 9_4_0_patch1; last modified: 2018-02-20 02:28:16"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT200to400"),
  ("nof_db_events",         9917255),
  ("nof_db_files",          249),
  ("fsize_db",              516966853400),
  ("xsection",              53.2656),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 516.97GB; nevents: 9.92M; release: 9_4_0_patch1; last modified: 2018-01-21 13:30:32"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-200to400_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT200to400_ext1"),
  ("nof_db_events",         1200124),
  ("nof_db_files",          42),
  ("fsize_db",              62895087297),
  ("xsection",              53.2656),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 62.90GB; nevents: 1.20M; release: 9_4_0_patch1; last modified: 2018-03-08 17:45:27"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT400to600"),
  ("nof_db_events",         9348901),
  ("nof_db_files",          223),
  ("fsize_db",              541860088013),
  ("xsection",              7.58268),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 541.86GB; nevents: 9.35M; release: 9_4_0_patch1; last modified: 2018-01-20 13:33:02"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-400to600_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT400to600_ext1"),
  ("nof_db_events",         1124294),
  ("nof_db_files",          36),
  ("fsize_db",              65011146477),
  ("xsection",              7.58268),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 65.01GB; nevents: 1.12M; release: 9_4_0_patch1; last modified: 2018-02-20 02:31:14"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-600to800_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT600to800"),
  ("nof_db_events",         8003554),
  ("nof_db_files",          195),
  ("fsize_db",              479647451104),
  ("xsection",              1.88244),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 479.65GB; nevents: 8.00M; release: 9_4_0_patch1; last modified: 2018-01-25 21:02:17"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-800to1200_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT800to1200"),
  ("nof_db_events",         3065315),
  ("nof_db_files",          105),
  ("fsize_db",              189395376159),
  ("xsection",              0.872856),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 189.40GB; nevents: 3.07M; release: 9_4_0_patch1; last modified: 2018-01-14 12:47:56"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-1200to2500_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT1200to2500"),
  ("nof_db_events",         625517),
  ("nof_db_files",          34),
  ("fsize_db",              41559351668),
  ("xsection",              0.2079),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 41.56GB; nevents: 625.52k; release: 9_4_0_patch1; last modified: 2018-03-16 17:45:12"),
])

meta_dictionary["/DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_DYJetsToLL_M-50_HT-2500toInf_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "DYJetsToLL_M50_HT2500toInf"),
  ("nof_db_events",         388323),
  ("nof_db_files",          25),
  ("fsize_db",              28163992373),
  ("xsection",              0.0037649),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 28.16GB; nevents: 388.32k; release: 9_4_0_patch1; last modified: 2018-02-01 02:10:17"),
])

meta_dictionary["/WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_WJetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "WJetsToLNu"),
  ("nof_db_events",         23240598),
  ("nof_db_files",          382),
  ("fsize_db",              882645881655),
  ("xsection",              61526.7),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: PRODUCTION; size: 882.65GB; nevents: 23.24M; release: 9_4_0_patch1; last modified: 2018-01-22 15:06:50"),
])

meta_dictionary["/W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_W1JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "W1JetsToLNu"),
  ("nof_db_events",         30003848),
  ("nof_db_files",          484),
  ("fsize_db",              1163663813409),
  ("xsection",              9503.91),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: PRODUCTION; size: 1.16TB; nevents: 30.00M; release: 9_4_0_patch1; last modified: 2018-01-31 04:19:29"),
])

meta_dictionary["/W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v3/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_W2JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v3"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "W2JetsToLNu"),
  ("nof_db_events",         19944844),
  ("nof_db_files",          312),
  ("fsize_db",              825217914289),
  ("xsection",              3258.45),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: PRODUCTION; size: 825.22GB; nevents: 19.94M; release: 9_4_0_patch1; last modified: 2018-01-31 08:48:54"),
])

meta_dictionary["/W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v3/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_W3JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v3"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "W3JetsToLNu"),
  ("nof_db_events",         19644745),
  ("nof_db_files",          305),
  ("fsize_db",              858873579148),
  ("xsection",              1162.28),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 858.87GB; nevents: 19.64M; release: 9_4_0_patch1; last modified: 2018-02-09 16:01:59"),
])

meta_dictionary["/W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_W4JetsToLNu_TuneCP5_13TeV-madgraphMLM-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "W4JetsToLNu"),
  ("nof_db_events",         11285729),
  ("nof_db_files",          255),
  ("fsize_db",              536619066244),
  ("xsection",              634.61),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 536.62GB; nevents: 11.29M; release: 9_4_0_patch1; last modified: 2018-02-24 04:48:37"),
])

meta_dictionary["/WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_WWTo2L2Nu_NNPDF31_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "WWTo2L2Nu"),
  ("nof_db_events",         1818828),
  ("nof_db_files",          50),
  ("fsize_db",              75643188117),
  ("xsection",              12.178),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 75.64GB; nevents: 1.82M; release: 9_4_0_patch1; last modified: 2018-02-09 10:06:57"),
])

meta_dictionary["/WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "WWToLNuQQ"),
  ("nof_db_events",         8516920),
  ("nof_db_files",          183),
  ("fsize_db",              363216571132),
  ("xsection",              49.997),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 363.22GB; nevents: 8.52M; release: 9_4_0_patch1; last modified: 2018-01-20 12:37:09"),
])

meta_dictionary["/WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_WWToLNuQQ_NNPDF31_TuneCP5_13TeV-powheg-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "WWToLNuQQ_ext1"),
  ("nof_db_events",         9967337),
  ("nof_db_files",          194),
  ("fsize_db",              424952354600),
  ("xsection",              49.997),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 424.95GB; nevents: 9.97M; release: 9_4_0_patch1; last modified: 2018-03-02 10:51:00"),
])

meta_dictionary["/WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_WZTo3LNu_TuneCP5_13TeV-amcatnloFXFX-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "WZTo3LNu"),
  ("nof_db_events",         10751052),
  ("nof_db_files",          212),
  ("fsize_db",              452807583489),
  ("xsection",              4.42965),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 452.81GB; nevents: 10.75M; release: 9_4_0_patch1; last modified: 2018-02-06 20:33:20"),
])

meta_dictionary["/WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_WZTo1L1Nu2Q_13TeV_amcatnloFXFX_madspin_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "WZTo1L1Nu2Q"),
  ("nof_db_events",         18998465),
  ("nof_db_files",          359),
  ("fsize_db",              856935529998),
  ("xsection",              10.71),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 856.94GB; nevents: 19.00M; release: 9_4_0_patch1; last modified: 2018-02-23 14:58:45"),
])

meta_dictionary["/ZZTo4L_13TeV_powheg_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ZZTo4L_13TeV_powheg_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "ZZTo4L"),
  ("nof_db_events",         6960289),
  ("nof_db_files",          204),
  ("fsize_db",              322020515003),
  ("xsection",              1.256),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 322.02GB; nevents: 6.96M; release: 9_4_0_patch1; last modified: 2017-12-09 15:05:32"),
])

meta_dictionary["/ZZTo4L_13TeV_powheg_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ZZTo4L_13TeV_powheg_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10_ext1-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "ZZTo4L_ext1"),
  ("nof_db_events",         95716759),
  ("nof_db_files",          1490),
  ("fsize_db",              3881682466950),
  ("xsection",              1.256),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 3.88TB; nevents: 95.72M; release: 9_4_0_patch1; last modified: 2018-02-09 16:08:21"),
])

meta_dictionary["/ZZTo2L2Nu_13TeV_powheg_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_ZZTo2L2Nu_13TeV_powheg_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "EWK"),
  ("process_name_specific", "ZZTo2L2Nu"),
  ("nof_db_events",         8289873),
  ("nof_db_files",          219),
  ("fsize_db",              350361671755),
  ("xsection",              0.564),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 350.36GB; nevents: 8.29M; release: 9_4_0_patch1; last modified: 2018-01-26 05:42:51"),
])

meta_dictionary["/QCD_Pt_15to20_bcToE_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt_15to20_bcToE_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt15to20_bcToE"),
  ("nof_db_events",         2145233),
  ("nof_db_files",          122),
  ("fsize_db",              78971419951),
  ("xsection",              187000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 78.97GB; nevents: 2.15M; release: 9_4_0_patch1; last modified: 2018-02-20 05:22:39"),
])

meta_dictionary["/QCD_Pt_20to30_bcToE_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt_20to30_bcToE_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt20to30_bcToE"),
  ("nof_db_events",         10266970),
  ("nof_db_files",          238),
  ("fsize_db",              381521898074),
  ("xsection",              313500.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 381.52GB; nevents: 10.27M; release: 9_4_0_patch1; last modified: 2018-03-05 14:02:57"),
])

meta_dictionary["/QCD_Pt_30to80_bcToE_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt_30to80_bcToE_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt30to80_bcToE"),
  ("nof_db_events",         16030011),
  ("nof_db_files",          282),
  ("fsize_db",              624283973070),
  ("xsection",              361500.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 624.28GB; nevents: 16.03M; release: 9_4_0_patch1; last modified: 2018-03-05 11:43:00"),
])

meta_dictionary["/QCD_Pt_80to170_bcToE_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt_80to170_bcToE_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt80to170_bcToE"),
  ("nof_db_events",         15972037),
  ("nof_db_files",          282),
  ("fsize_db",              702221650296),
  ("xsection",              33770.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 702.22GB; nevents: 15.97M; release: 9_4_0_patch1; last modified: 2018-02-25 04:48:57"),
])

meta_dictionary["/QCD_Pt_170to250_bcToE_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt_170to250_bcToE_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt170to250_bcToE"),
  ("nof_db_events",         9831904),
  ("nof_db_files",          227),
  ("fsize_db",              472875748163),
  ("xsection",              2126.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 472.88GB; nevents: 9.83M; release: 9_4_0_patch1; last modified: 2018-03-05 11:42:39"),
])

meta_dictionary["/QCD_Pt_250toInf_bcToE_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt_250toInf_bcToE_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt250toInf_bcToE"),
  ("nof_db_events",         9921358),
  ("nof_db_files",          228),
  ("fsize_db",              505365065244),
  ("xsection",              563.1),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 505.37GB; nevents: 9.92M; release: 9_4_0_patch1; last modified: 2018-03-05 08:04:14"),
])

meta_dictionary["/QCD_Pt-15to20_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-15to20_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt15to20_EMEnriched"),
  ("nof_db_events",         10995821),
  ("nof_db_files",          193),
  ("fsize_db",              385771901470),
  ("xsection",              1330000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 385.77GB; nevents: 11.00M; release: 9_4_0_patch1; last modified: 2018-01-16 00:34:42"),
])

meta_dictionary["/QCD_Pt-20to30_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-20to30_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt20to30_EMEnriched"),
  ("nof_db_events",         11545386),
  ("nof_db_files",          151),
  ("fsize_db",              413960592964),
  ("xsection",              4928000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 413.96GB; nevents: 11.55M; release: 9_4_0_patch1; last modified: 2018-01-06 05:29:26"),
])

meta_dictionary["/QCD_Pt-30to50_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-30to50_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt30to50_EMEnriched"),
  ("nof_db_events",         14619987),
  ("nof_db_files",          260),
  ("fsize_db",              543195523019),
  ("xsection",              6410000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 543.20GB; nevents: 14.62M; release: 9_4_0_patch1; last modified: 2018-01-11 00:32:28"),
])

meta_dictionary["/QCD_Pt-50to80_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-50to80_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt50to80_EMEnriched"),
  ("nof_db_events",         10665765),
  ("nof_db_files",          157),
  ("fsize_db",              415220949639),
  ("xsection",              1986000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 415.22GB; nevents: 10.67M; release: 9_4_0_patch1; last modified: 2017-12-29 23:04:28"),
])

meta_dictionary["/QCD_Pt-80to120_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-80to120_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt80to120_EMEnriched"),
  ("nof_db_events",         8414260),
  ("nof_db_files",          170),
  ("fsize_db",              346574053270),
  ("xsection",              370900.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 346.57GB; nevents: 8.41M; release: 9_4_0_patch1; last modified: 2018-02-06 20:30:00"),
])

meta_dictionary["/QCD_Pt-120to170_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-120to170_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt120to170_EMEnriched"),
  ("nof_db_events",         8757439),
  ("nof_db_files",          152),
  ("fsize_db",              381865641926),
  ("xsection",              66760.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 381.87GB; nevents: 8.76M; release: 9_4_0_patch1; last modified: 2018-01-17 05:18:51"),
])

meta_dictionary["/QCD_Pt-170to300_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-170to300_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt170to300_EMEnriched"),
  ("nof_db_events",         3521215),
  ("nof_db_files",          66),
  ("fsize_db",              161813592592),
  ("xsection",              16430.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 161.81GB; nevents: 3.52M; release: 9_4_0_patch1; last modified: 2018-01-22 14:48:25"),
])

meta_dictionary["/QCD_Pt-300toInf_EMEnriched_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-300toInf_EMEnriched_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt300toInf_EMEnriched"),
  ("nof_db_events",         2898084),
  ("nof_db_files",          68),
  ("fsize_db",              144954265606),
  ("xsection",              1101.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 144.95GB; nevents: 2.90M; release: 9_4_0_patch1; last modified: 2018-01-14 03:57:20"),
])

meta_dictionary["/QCD_Pt-20toInf_MuEnrichedPt15_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-RECOSIMstep_94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-20toInf_MuEnrichedPt15_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-RECOSIMstep_94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Mu15"),
  ("nof_db_events",         16404691),
  ("nof_db_files",          261),
  ("fsize_db",              653560323211),
  ("xsection",              237800.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: PRODUCTION; size: 653.56GB; nevents: 16.40M; release: 9_4_0_patch1; last modified: 2017-12-23 01:52:28"),
])

meta_dictionary["/QCD_Pt-15to20_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-15to20_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt15to20_Mu5"),
  ("nof_db_events",         5748990),
  ("nof_db_files",          120),
  ("fsize_db",              210664044988),
  ("xsection",              2785000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 210.66GB; nevents: 5.75M; release: 9_4_0_patch1; last modified: 2017-12-29 14:44:51"),
])

meta_dictionary["/QCD_Pt-20to30_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-20to30_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt20to30_Mu5"),
  ("nof_db_events",         28006402),
  ("nof_db_files",          414),
  ("fsize_db",              1042303079896),
  ("xsection",              2490000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.04TB; nevents: 28.01M; release: 9_4_0_patch1; last modified: 2018-01-11 15:02:54"),
])

meta_dictionary["/QCD_Pt-30to50_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-30to50_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt30to50_Mu5"),
  ("nof_db_events",         28667918),
  ("nof_db_files",          488),
  ("fsize_db",              1108018237843),
  ("xsection",              1364000.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.11TB; nevents: 28.67M; release: 9_4_0_patch1; last modified: 2017-12-30 07:14:03"),
])

meta_dictionary["/QCD_Pt-50to80_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-50to80_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt50to80_Mu5"),
  ("nof_db_events",         23955198),
  ("nof_db_files",          323),
  ("fsize_db",              989720589789),
  ("xsection",              377400.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 989.72GB; nevents: 23.96M; release: 9_4_0_patch1; last modified: 2018-01-27 08:05:43"),
])

meta_dictionary["/QCD_Pt-80to120_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-80to120_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt80to120_Mu5"),
  ("nof_db_events",         23098427),
  ("nof_db_files",          351),
  ("fsize_db",              1019004927279),
  ("xsection",              88350.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.02TB; nevents: 23.10M; release: 9_4_0_patch1; last modified: 2017-12-25 07:10:38"),
])

meta_dictionary["/QCD_Pt-120to170_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-120to170_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt120to170_Mu5"),
  ("nof_db_events",         20821535),
  ("nof_db_files",          377),
  ("fsize_db",              977524130023),
  ("xsection",              21250.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 977.52GB; nevents: 20.82M; release: 9_4_0_patch1; last modified: 2018-01-12 06:22:50"),
])

meta_dictionary["/QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-170to300_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt170to300_Mu5"),
  ("nof_db_events",         46438676),
  ("nof_db_files",          796),
  ("fsize_db",              2321204365357),
  ("xsection",              6969.0),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 2.32TB; nevents: 46.44M; release: 9_4_0_patch1; last modified: 2017-12-29 06:33:54"),
])

meta_dictionary["/QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-300to470_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt300to470_Mu5"),
  ("nof_db_events",         17620456),
  ("nof_db_files",          309),
  ("fsize_db",              953319834358),
  ("xsection",              619.5),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 953.32GB; nevents: 17.62M; release: 9_4_0_patch1; last modified: 2018-01-28 01:14:27"),
])

meta_dictionary["/QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-470to600_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt470to600_Mu5"),
  ("nof_db_events",         24230220),
  ("nof_db_files",          614),
  ("fsize_db",              1430680707837),
  ("xsection",              58.9),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 1.43TB; nevents: 24.23M; release: 9_4_0_patch1; last modified: 2018-03-21 08:02:38"),
])

meta_dictionary["/QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-600to800_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt600to800_Mu5"),
  ("nof_db_events",         16392140),
  ("nof_db_files",          314),
  ("fsize_db",              959357066284),
  ("xsection",              18.36),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 959.36GB; nevents: 16.39M; release: 9_4_0_patch1; last modified: 2018-02-05 10:29:41"),
])

meta_dictionary["/QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-800to1000_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt800to1000_Mu5"),
  ("nof_db_events",         15694987),
  ("nof_db_files",          361),
  ("fsize_db",              946456575174),
  ("xsection",              3.253),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 946.46GB; nevents: 15.69M; release: 9_4_0_patch1; last modified: 2018-02-06 20:27:50"),
])

meta_dictionary["/QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_QCD_Pt-1000toInf_MuEnrichedPt5_TuneCP5_13TeV_pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "QCD"),
  ("process_name_specific", "QCD_Pt1000toInf_Mu5"),
  ("nof_db_events",         11464778),
  ("nof_db_files",          268),
  ("fsize_db",              714825533488),
  ("xsection",              1.075),
  ("use_it",                False),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 714.83GB; nevents: 11.46M; release: 9_4_0_patch1; last modified: 2018-02-06 11:38:32"),
])

meta_dictionary["/WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_WWW_4F_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "WWW_4F"),
  ("nof_db_events",         240000),
  ("nof_db_files",          21),
  ("fsize_db",              11711799646),
  ("xsection",              0.2086),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 11.71GB; nevents: 240.00k; release: 9_4_0_patch1; last modified: 2018-03-01 06:04:33"),
])

meta_dictionary["/WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_WWZ_4F_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "WWZ_4F"),
  ("nof_db_events",         250000),
  ("nof_db_files",          14),
  ("fsize_db",              13268139304),
  ("xsection",              0.1651),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 13.27GB; nevents: 250.00k; release: 9_4_0_patch1; last modified: 2018-03-16 02:39:57"),
])

meta_dictionary["/WZZ_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_WZZ_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "WZZ"),
  ("nof_db_events",         250000),
  ("nof_db_files",          18),
  ("fsize_db",              12226507693),
  ("xsection",              0.05565),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 12.23GB; nevents: 250.00k; release: 9_4_0_patch1; last modified: 2018-03-05 12:43:46"),
])

meta_dictionary["/ZZZ_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_ZZZ_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "ZZZ"),
  ("nof_db_events",         250000),
  ("nof_db_files",          17),
  ("fsize_db",              11782250391),
  ("xsection",              0.01398),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 11.78GB; nevents: 250.00k; release: 9_4_0_patch1; last modified: 2018-03-14 05:49:59"),
])

meta_dictionary["/WZG_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_WZG_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "WZG"),
  ("nof_db_events",         995620),
  ("nof_db_files",          43),
  ("fsize_db",              49822671760),
  ("xsection",              0.04123),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 49.82GB; nevents: 995.62k; release: 9_4_0_patch1; last modified: 2018-03-02 02:00:45"),
])

meta_dictionary["/TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "TTGJets"),
  ("nof_db_events",         4647278),
  ("nof_db_files",          138),
  ("fsize_db",              269969335093),
  ("xsection",              3.697),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 269.97GB; nevents: 4.65M; release: 9_4_0_patch1; last modified: 2018-01-23 11:13:18"),
])

meta_dictionary["/TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8/RunIIFall17MiniAOD-PU2017_94X_mc2017_realistic_v11_ext1-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_TTGJets_TuneCP5_13TeV-amcatnloFXFX-madspin-pythia8__RunIIFall17MiniAOD-PU2017_94X_mc2017_realistic_v11_ext1-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "TTGJets_ext1"),
  ("nof_db_events",         9402928),
  ("nof_db_files",          214),
  ("fsize_db",              546911617485),
  ("xsection",              3.697),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 546.91GB; nevents: 9.40M; release: 9_4_0_patch1; last modified: 2018-03-20 10:57:22"),
])

meta_dictionary["/TTTT_TuneCP5_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_TTTT_TuneCP5_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v2"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "TTTT"),
  ("nof_db_events",         993804),
  ("nof_db_files",          29),
  ("fsize_db",              77438656415),
  ("xsection",              0.008213),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 77.44GB; nevents: 993.80k; release: 9_4_0_patch1; last modified: 2018-02-23 15:30:59"),
])

meta_dictionary["/TTWH_TuneCP5_13TeV-madgraph-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_TTWH_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "TTWH"),
  ("nof_db_events",         200000),
  ("nof_db_files",          17),
  ("fsize_db",              13226366130),
  ("xsection",              0.00114),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 13.23GB; nevents: 200.00k; release: 9_4_0_patch1; last modified: 2018-02-17 16:13:00"),
])

meta_dictionary["/TTTW_TuneCP5_13TeV-madgraph-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v3/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Jun08_TTTW_TuneCP5_13TeV-madgraph-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v3"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "TTTW"),
  ("nof_db_events",         200000),
  ("nof_db_files",          15),
  ("fsize_db",              14302344096),
  ("xsection",              0.0007273),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 14.30GB; nevents: 200.00k; release: 9_4_0_patch1; last modified: 2018-02-17 14:29:13"),
])

meta_dictionary["/tZq_ll_4f_ckm_NLO_TuneCP5_PSweights_13TeV-amcatnlo-pythia8/RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_tZq_ll_4f_ckm_NLO_TuneCP5_PSweights_13TeV-amcatnlo-pythia8__RunIIFall17MiniAOD-94X_mc2017_realistic_v10-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "tZq_ll_4f"),
  ("nof_db_events",         13220024),
  ("nof_db_files",          292),
  ("fsize_db",              723683119488),
  ("xsection",              0.0758),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 723.68GB; nevents: 13.22M; release: 9_4_0_patch1; last modified: 2018-02-17 15:41:39"),
])

meta_dictionary["/WWTo2L2Nu_DoubleScattering_13TeV-herwigpp/RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1/MINIAODSIM"] =  OD([
  ("crab_string",           "NanoProduction_v2_2018Apr26_WWTo2L2Nu_DoubleScattering_13TeV-herwigpp__RunIIFall17MiniAOD-94X_mc2017_realistic_v11-v1"),
  ("sample_category",       "Rares"),
  ("process_name_specific", "WWTo2L2Nu_DoubleScattering"),
  ("nof_db_events",         1000000),
  ("nof_db_files",          23),
  ("fsize_db",              42876536279),
  ("xsection",              0.1743),
  ("use_it",                True),
  ("genWeight",             True),
  ("comment",               "status: VALID; size: 42.88GB; nevents: 1.00M; release: 9_4_0_patch1; last modified: 2018-03-26 17:51:09"),
])


# event statistics by sample category:
# signal:                    27.23M
# additional_signal_overlap: 1.91M
# TTZ:                       20.08M
# TTW:                       15.03M
# TTWW:                      200.00k
# TT:                        455.56M
# EWK:                       698.13M
# QCD:                       414.13M
# Rares:                     31.65M

