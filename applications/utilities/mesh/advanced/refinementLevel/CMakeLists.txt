add_executable( refinementLevel )
target_link_libraries( refinementLevel
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatches
  meshTools
)
target_include_directories( refinementLevel
  PUBLIC
  .
)
target_sources( refinementLevel
  PRIVATE
  refinementLevel.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS refinementLevel )
