add_library( incompressibleVoF )
target_link_libraries( incompressibleVoF
  PRIVATE
  OpenFOAM
  compressibleCavitationModels
  compressibleVoF
  finiteVolume
  incompressibleMomentumTransportModels
  incompressibleTwoPhases
  phaseIncompressibleMomentumTransportModels
  physicalProperties
  twoPhaseSolver
  twoPhaseVoFSolver
)
target_include_directories( incompressibleVoF
  PUBLIC
  .
)
target_sources( incompressibleVoF
  PRIVATE
  alphaSuSp.C
  incompressibleInterPhaseTransportModel/incompressibleInterPhaseTransportModel.C
  incompressibleTwoPhaseVoFMixture/incompressibleTwoPhaseVoFMixture.C
  incompressibleVoF.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  fvModels/VoFCavitation/VoFCavitation.H
  fvModels/VoFTurbulenceDamping/VoFTurbulenceDamping.H
  incompressibleInterPhaseTransportModel/incompressibleInterPhaseTransportModel.H
  incompressibleTwoPhaseVoFMixture/incompressibleTwoPhaseVoFMixture.H
  incompressibleVoF.H
)
install( TARGETS incompressibleVoF )