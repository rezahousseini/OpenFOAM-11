add_executable( topoSet )
target_link_libraries( topoSet
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatches
  meshTools
)
target_include_directories( topoSet
  PUBLIC
  .
)
target_sources( topoSet
  PRIVATE
  topoSet.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS topoSet )
