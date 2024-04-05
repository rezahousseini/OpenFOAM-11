add_library( VoFSolver )
target_link_libraries( VoFSolver
  PRIVATE
  OpenFOAM
  finiteVolume

  PUBLIC
  fluidSolver
)
target_include_directories( VoFSolver
  PUBLIC
  .
)
target_sources( VoFSolver
  PRIVATE
  VoFMixture/VoFMixture.C
  VoFSolver.C
  momentumPredictor.C
  moveMesh.C
  setRDeltaT.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFMixture/VoFMixture.H
  VoFSolver.H
)
install( TARGETS VoFSolver )
