add_library( multiphaseEuler )
target_link_libraries( multiphaseEuler
  PRIVATE
  OpenFOAM
  finiteVolume
  fluidSolver
  multiphaseThermophysicalTransportModels
  phaseCompressibleMomentumTransportModels
  phaseSystem
)
target_include_directories( multiphaseEuler
  PUBLIC
  .
)
target_sources( multiphaseEuler
  PRIVATE
  cellPressureCorrector.C
  compressibilityEqns.C
  facePressureCorrector.C
  momentumPredictor.C
  moveMesh.C
  multiphaseEuler.C
  pressureCorrector.C
  setRDeltaT.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  multiphaseEuler.H
)
install( TARGETS multiphaseEuler )