import FWCore.ParameterSet.Config as cms

source = cms.Source("FlatRandomPtGunSource",
    PGunParameters = cms.untracked.PSet(
        MaxPt = cms.untracked.double(35.01),
        MinPt = cms.untracked.double(34.99),
        PartID = cms.untracked.vint32(11),
        MaxEta = cms.untracked.double(2.5),
        MaxPhi = cms.untracked.double(3.14159265359),
        MinEta = cms.untracked.double(-2.5),
        MinPhi = cms.untracked.double(-3.14159265359)
    ),
    Verbosity = cms.untracked.int32(0),
    psethack = cms.string('single electron pt 35'),
    AddAntiParticle = cms.untracked.bool(True),
    firstRun = cms.untracked.uint32(1)
)


