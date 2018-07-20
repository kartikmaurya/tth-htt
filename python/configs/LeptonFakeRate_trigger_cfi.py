import FWCore.ParameterSet.Config as cms

triggers_mu_2016 = cms.VPSet(
  cms.PSet(
    path = cms.vstring("HLT_Mu27_v"),
    cone_minPt = cms.double(45.),
    cone_maxPt = cms.double(100000.),
    jet_minPt = cms.double(30.),
#    pufile    = cms.FileInPath(""), ## PU file to be implemented later
    average_prescale = cms.double(143),
    prescale_rand_mc = cms.double(5.),
    is_trigger_1mu = cms.bool(True),
    is_trigger_2mu = cms.bool(False),
    is_trigger_1e = cms.bool(False),
    is_trigger_2e = cms.bool(False)
  ),
  cms.PSet(
    path = cms.vstring("HLT_Mu17_v"),
    cone_minPt = cms.double(30.),
    cone_maxPt = cms.double(100000.),
    jet_minPt = cms.double(30.),
#    pufile    = cms.FileInPath(""), ## PU file to be implemented later
    average_prescale = cms.double(126),
    prescale_rand_mc = cms.double(5.),
    is_trigger_1mu = cms.bool(False),
    is_trigger_2mu = cms.bool(True),
    is_trigger_1e = cms.bool(False),
    is_trigger_2e = cms.bool(False)
  ),
  cms.PSet(
    path = cms.vstring("HLT_Mu8_v"),
    cone_minPt = cms.double(15.),
    cone_maxPt = cms.double(45.),
    jet_minPt = cms.double(30.),
#    pufile    = cms.FileInPath(""), ## PU file to be implemented later
    average_prescale = cms.double(9072),
    prescale_rand_mc = cms.double(100.),
    is_trigger_1mu = cms.bool(False),
    is_trigger_2mu = cms.bool(True),
    is_trigger_1e = cms.bool(False),
    is_trigger_2e = cms.bool(False)
  ),
  cms.PSet(
    path = cms.vstring("HLT_Mu3_PFJet40_v"),
    cone_minPt = cms.double(10.),
    cone_maxPt = cms.double(30.),
    jet_minPt = cms.double(40.),
#    pufile    = cms.FileInPath(""), ## PU file to be implemented later
    average_prescale = cms.double(4841),
    prescale_rand_mc = cms.double(50.),
    is_trigger_1mu = cms.bool(False),
    is_trigger_2mu = cms.bool(True),
    is_trigger_1e = cms.bool(False),
    is_trigger_2e = cms.bool(False)
  )
),

triggers_e_2016 = cms.VPSet(
  cms.PSet(
    path = cms.vstring("HLT_Ele17_CaloIdM_TrackIdM_PFJet30_v"),
    cone_minPt = cms.double(30.),
    cone_maxPt = cms.double(100000.),
    jet_minPt = cms.double(30.),
#    pufile    = cms.FileInPath(""), ## PU file to be implemented later
    average_prescale = cms.double(569),
    prescale_rand_mc = cms.double(10.),
    is_trigger_1mu = cms.bool(False),
    is_trigger_2mu = cms.bool(False),
    is_trigger_1e = cms.bool(False),
    is_trigger_2e = cms.bool(True)
  ),
  cms.PSet(
    path = cms.vstring("HLT_Ele12_CaloIdM_TrackIdM_PFJet30_v"),
    cone_minPt = cms.double(20.),
    cone_maxPt = cms.double(30.),
    jet_minPt = cms.double(30.),
#    pufile    = cms.FileInPath(""), ## PU file to be implemented later
    average_prescale = cms.double(2021),
    prescale_rand_mc = cms.double(25.),
    is_trigger_1mu = cms.bool(False),
    is_trigger_2mu = cms.bool(False),
    is_trigger_1e = cms.bool(False),
    is_trigger_2e = cms.bool(True)
  )
),

triggers_mu_cfg_2017 = cms.VPSet(
    cms.PSet(
        path = cms.string("HLT_Mu27"),
        cone_minPt = cms.double(45.),
        cone_maxPt = cms.double(100.),
        minRecoPt = cms.double(27.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(30.),
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(225), ## 2016 VALUE: 143
        is_trigger_1mu = cms.bool(True),
        is_trigger_2mu = cms.bool(False),
        is_trigger_1e = cms.bool(False),
        is_trigger_2e = cms.bool(False)
    ),
    cms.PSet(
        path = cms.string("HLT_Mu20"),
        cone_minPt = cms.double(32.),
        cone_maxPt = cms.double(100.),
        minRecoPt = cms.double(20.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(30.),
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(225), ## 2016 VALUE: 143
        is_trigger_1mu = cms.bool(True),
        is_trigger_2mu = cms.bool(False),
        is_trigger_1e = cms.bool(False),
        is_trigger_2e = cms.bool(False)
    ),
    cms.PSet(
        path = cms.string("HLT_Mu17"),
        cone_minPt = cms.double(32.),
        cone_maxPt = cms.double(100.),
        minRecoPt = cms.double(17.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(30.),
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(594), ## 2016 VALUE: 126
        is_trigger_1mu = cms.bool(False),
        is_trigger_2mu = cms.bool(True),
        is_trigger_1e = cms.bool(False),
        is_trigger_2e = cms.bool(False)
     ),
    cms.PSet(
        path = cms.string("HLT_Mu8"),
        cone_minPt = cms.double(15.),
        cone_maxPt = cms.double(45.),
        minRecoPt = cms.double(8.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(30.),
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(15948), ## 2016 VALUE: 9072
        is_trigger_1mu = cms.bool(False),
        is_trigger_2mu = cms.bool(True),
        is_trigger_1e = cms.bool(False),
        is_trigger_2e = cms.bool(False)
    ),
    cms.PSet(
        path = cms.string("HLT_Mu3_PFJet40"),
        cone_minPt = cms.double(10.),
        cone_maxPt = cms.double(32.),
        minRecoPt = cms.double(-1.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(45.), # UPDATED FROM 2016 VALUE (40 GeV) FOR 2017 DATA
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(8992), ## 2016 VALUE: 4841
        is_trigger_1mu = cms.bool(True),
        is_trigger_2mu = cms.bool(False),
        is_trigger_1e = cms.bool(False),
        is_trigger_2e = cms.bool(False)
     )
)

triggers_e_cfg_2017 = cms.VPSet(
    cms.PSet(
        path = cms.string("HLT_Ele8_CaloIdM_TrackIdM_PFJet30"),
        cone_minPt = cms.double(15.),
        cone_maxPt = cms.double(45.),
        minRecoPt = cms.double(8.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(30.),
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(11365),
        is_trigger_1mu = cms.bool(False),
        is_trigger_2mu = cms.bool(False),
        is_trigger_1e = cms.bool(True),
        is_trigger_2e = cms.bool(False)
    ),
#        cms.PSet(
#            path = cms.string("HLT_Ele12_CaloIdL_TrackIdL_IsoVL_PFJet30"), ## DOESN'T EXIST IN 2017 DATA
#            cone_minPt = cms.double(20.),
#            cone_maxPt = cms.double(30.),
#            minRecoPt = cms.double(12.), # NEWLY ADDED AFTER GIOVANNI SYNC
#            jet_minPt = cms.double(30.),
##        pufile    = cms.FileInPath(""), ## PU file to be implemented later
#            average_prescale = cms.double(1086), #TODO: update
#            is_trigger_1mu = cms.bool(False),
#            is_trigger_2mu = cms.bool(False),
#            is_trigger_1e = cms.bool(True),
#            is_trigger_2e = cms.bool(False)
#        ),
    cms.PSet(
        path = cms.string("HLT_Ele17_CaloIdM_TrackIdM_PFJet30"),
        cone_minPt = cms.double(25.),
        cone_maxPt = cms.double(100.),
        minRecoPt = cms.double(17.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(30.),
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(1167), ## 2016 VALUE: 569
        is_trigger_1mu = cms.bool(False),
        is_trigger_2mu = cms.bool(False),
        is_trigger_1e = cms.bool(True),
        is_trigger_2e = cms.bool(False)
    ),
    cms.PSet(
        path = cms.string("HLT_Ele23_CaloIdM_TrackIdM_PFJet30"),
        cone_minPt = cms.double(32.),
        cone_maxPt = cms.double(100.),
        minRecoPt = cms.double(23.), # NEWLY ADDED AFTER GIOVANNI SYNC
        jet_minPt = cms.double(30.),
#        pufile    = cms.FileInPath(""), ## PU file to be implemented later
        average_prescale = cms.double(1069), ## suggested by christian to be checked with Giovanni !!!
        is_trigger_1mu = cms.bool(False),
        is_trigger_2mu = cms.bool(False),
        is_trigger_1e = cms.bool(True),
        is_trigger_2e = cms.bool(False)
    )
)
