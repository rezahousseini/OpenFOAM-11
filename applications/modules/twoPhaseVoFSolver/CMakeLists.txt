add_library( twoPhaseVoFSolver )
target_link_libraries( twoPhaseVoFSolver
  PRIVATE
  OpenFOAM
  VoFSolver
  finiteVolume
  fluidSolver
  twoPhaseMixture
  twoPhaseSolver

  PUBLIC
  interfaceProperties
)
target_include_directories( twoPhaseVoFSolver
  PUBLIC
  .
)
target_sources( twoPhaseVoFSolver
  PRIVATE
  setInterfaceRDeltaT.C
  twoPhaseVoFSolver.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  twoPhaseVoFSolver.H
)
install( TARGETS twoPhaseVoFSolver )
