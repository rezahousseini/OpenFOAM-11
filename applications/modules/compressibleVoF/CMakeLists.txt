add_library( compressibleVoF )
target_link_libraries( compressibleVoF
  PRIVATE
  OpenFOAM
  VoFSolver
  compressibleCavitationModels
  compressibleMomentumTransportModels
  compressibleTwoPhases
  finiteVolume
  fluidSolver
  fluidThermophysicalModels
  lagrangianParcel
  phaseCompressibleMomentumTransportModels
  thermophysicalTransportModel
  twoPhaseSolver
  twoPhaseVoFSolver
)
target_include_directories( compressibleVoF
  PUBLIC
  .
)
target_sources( compressibleVoF
  PRIVATE
  alphaSuSp.C
  compressibleInterPhaseThermophysicalTransportModel/compressibleInterPhaseThermophysicalTransportModel.C
  compressibleInterPhaseTransportModel/compressibleInterPhaseTransportModel.C
  compressibleTwoPhaseVoFMixture/compressibleTwoPhaseVoFMixture.C
  compressibleVoF.C
  momentumPredictor.C
  pressureCorrector.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  compressibleInterPhaseThermophysicalTransportModel/compressibleInterPhaseThermophysicalTransportModel.H
  compressibleInterPhaseTransportModel/compressibleInterPhaseTransportModel.H
  compressibleTwoPhaseVoFMixture/compressibleTwoPhaseVoFMixture.H
  compressibleVoF.H
  fvModels/VoFCavitation/VoFCavitation.H
  fvModels/VoFClouds/VoFClouds.H
  fvModels/VoFSolidificationMeltingSource/VoFSolidificationMeltingSource.H
  fvModels/VoFTurbulenceDamping/VoFTurbulenceDamping.H
)
install( TARGETS compressibleVoF )
