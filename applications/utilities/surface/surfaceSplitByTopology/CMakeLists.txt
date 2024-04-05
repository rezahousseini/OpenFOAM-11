add_executable( surfaceSplitByTopology )
target_link_libraries( surfaceSplitByTopology
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceSplitByTopology
  PUBLIC
  .
)
target_sources( surfaceSplitByTopology
  PRIVATE
  surfaceSplitByTopology.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceSplitByTopology )
