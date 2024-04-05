add_executable( foamMultiRun )
target_link_libraries( foamMultiRun
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( foamMultiRun
  PUBLIC
  .
)
target_sources( foamMultiRun
  PRIVATE
  foamMultiRun.C
  regionSolvers/regionSolvers.C
  setDeltaT.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  regionSolvers/regionSolvers.H
  regionSolvers/regionSolversI.H
  setDeltaT.H
)
install( TARGETS foamMultiRun )
