# The following comments couldn't be translated into the new config version:

# This is a vector of ParameterSet names to be read, in this order

# Z decays

# Higgs decays

import FWCore.ParameterSet.Config as cms

source = cms.Source("PythiaSource",
    pythiaPylistVerbosity = cms.untracked.int32(1),
    # put here the efficiency of your filter (1. if no filter)
    filterEfficiency = cms.untracked.double(1.0),
    pythiaHepMCVerbosity = cms.untracked.bool(False),
    # put here the cross section of your process (in pb)
    crossSection = cms.untracked.double(4.3),
    maxEventsToPrint = cms.untracked.int32(3),
    PythiaParameters = cms.PSet(
        pythiaUESettings = cms.vstring('MSTJ(11)=3     ! Choice of the fragmentation function', 'MSTJ(22)=2     ! Decay those unstable particles', 'PARJ(71)=10 .  ! for which ctau  10 mm', 'MSTP(2)=1      ! which order running alphaS', 'MSTP(33)=0     ! no K factors in hard cross sections', 'MSTP(51)=7     ! structure function chosen', 'MSTP(81)=1     ! multiple parton interactions 1 is Pythia default', 'MSTP(82)=4     ! Defines the multi-parton model', 'MSTU(21)=1     ! Check on possible errors during program execution', 'PARP(82)=1.9409   ! pt cutoff for multiparton interactions', 'PARP(89)=1960. ! sqrts for which PARP82 is set', 'PARP(83)=0.5   ! Multiple interactions: matter distrbn parameter', 'PARP(84)=0.4   ! Multiple interactions: matter distribution parameter', 'PARP(90)=0.16  ! Multiple interactions: rescaling power', 'PARP(67)=2.5    ! amount of initial-state radiation', 'PARP(85)=1.0  ! gluon prod. mechanism in MI', 'PARP(86)=1.0  ! gluon prod. mechanism in MI', 'PARP(62)=1.25   ! ', 'PARP(64)=0.2    ! ', 'MSTP(91)=1     !', 'PARP(91)=2.1   ! kt distribution', 'PARP(93)=15.0  ! '),
        parameterSets = cms.vstring('pythiaUESettings', 'processParameters'),
        processParameters = cms.vstring('PMAS(25,1)=120.0        !mass of Higgs', 'MSEL=0                  ! user selection for process', 'MSUB(123)=1             !ZZ fusion to H', 'MSUB(124)=1             !WW fusion to H', 'MDME(174,1)=0           !Z decay into d dbar', 'MDME(175,1)=0           !Z decay into u ubar', 'MDME(176,1)=0           !Z decay into s sbar', 'MDME(177,1)=0           !Z decay into c cbar', 'MDME(178,1)=0           !Z decay into b bbar', 'MDME(179,1)=0           !Z decay into t tbar', 'MDME(182,1)=0           !Z decay into e- e+', 'MDME(183,1)=1           !Z decay into nu_e nu_ebar', 'MDME(184,1)=0           !Z decay into mu- mu+', 'MDME(185,1)=0           !Z decay into nu_mu nu_mubar', 'MDME(186,1)=0           !Z decay into tau- tau+', 'MDME(187,1)=0           !Z decay into nu_tau nu_taubar', 'MDME(210,1)=0           !Higgs decay into dd', 'MDME(211,1)=0           !Higgs decay into uu', 'MDME(212,1)=0           !Higgs decay into ss', 'MDME(213,1)=0           !Higgs decay into cc', 'MDME(214,1)=0           !Higgs decay into bb', 'MDME(215,1)=0           !Higgs decay into tt', 'MDME(216,1)=0           !Higgs decay into', 'MDME(217,1)=0           !Higgs decay into Higgs decay', 'MDME(218,1)=0           !Higgs decay into e nu e', 'MDME(219,1)=0           !Higgs decay into mu nu mu', 'MDME(220,1)=0           !Higgs decay into tau nu tau', 'MDME(221,1)=0           !Higgs decay into Higgs decay', 'MDME(222,1)=0           !Higgs decay into g g', 'MDME(223,1)=0           !Higgs decay into gam gam', 'MDME(224,1)=0           !Higgs decay into gam Z', 'MDME(225,1)=1           !Higgs decay into Z Z', 'MDME(226,1)=0           !Higgs decay into W W')
    )
)


