add_library( twoPhaseSolver )
target_link_libraries( twoPhaseSolver
  PRIVATE
  OpenFOAM
  finiteVolume
  fluidSolver
  interfaceCompression
  meshTools

  PUBLIC
  VoFSolver
  twoPhaseMixture
)
target_include_directories( twoPhaseSolver
  PUBLIC
  .
)
target_sources( twoPhaseSolver
  PRIVATE
  alphaPredictor.C
  pressureCorrector.C
  twoPhaseSolver.C
  twoPhaseVoFMixture/twoPhaseVoFMixture.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  twoPhaseSolver.H
  twoPhaseVoFMixture/twoPhaseVoFMixture.H
)
install( TARGETS twoPhaseSolver )
