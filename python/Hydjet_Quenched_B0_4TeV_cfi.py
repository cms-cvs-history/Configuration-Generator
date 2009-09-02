import FWCore.ParameterSet.Config as cms

source = cms.Source("EmptySource")

from Configuration.Generator.PyquenDefaultSettings_cff import *

generator = cms.EDFilter("HydjetGeneratorFilter",
                         collisionParameters,
                         qgpParameters,
                         hydjetParameters,
                         hydjetMode = cms.string('kHydroQJets'),
                         PythiaParameters = cms.PSet(pyquenPythiaDefaultBlock,
                                                     # Quarkonia and Weak Bosons removed upon dilepton group's request.
                                                     parameterSets = cms.vstring('pythiaDefault','pythiaJets','pythiaPromptPhotons'),
                                                     ),
                         cFlag = cms.int32(0),
                         bMin = cms.double(0),
                         bMax = cms.double(0),
                         bFixed = cms.double(0)
                         )

ProductionFilterSequence = cms.Sequence(generator)
