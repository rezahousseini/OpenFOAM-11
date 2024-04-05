add_library( fluidSolver )
target_link_libraries( fluidSolver
  PRIVATE
  OSspecific
  OpenFOAM
  Pstream
  finiteVolume
)
target_include_directories( fluidSolver
  PUBLIC
  .
)
target_sources( fluidSolver
  PRIVATE
  fluidSolver.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  fluidSolver.H
)
install( TARGETS fluidSolver )
