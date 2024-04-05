add_executable( foamRun )
target_link_libraries( foamRun
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( foamRun
  PUBLIC
  .
)
target_sources( foamRun
  PRIVATE
  foamRun.C
  setDeltaT.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  setDeltaT.H
)
install( TARGETS foamRun )
