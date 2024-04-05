add_executable( surfaceSplitByPatch )
target_link_libraries( surfaceSplitByPatch
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceSplitByPatch
  PUBLIC
  .
)
target_sources( surfaceSplitByPatch
  PRIVATE
  surfaceSplitByPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceSplitByPatch )
