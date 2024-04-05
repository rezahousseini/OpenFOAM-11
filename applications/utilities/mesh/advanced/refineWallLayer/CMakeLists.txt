add_executable( refineWallLayer )
target_link_libraries( refineWallLayer
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( refineWallLayer
  PUBLIC
  .
)
target_sources( refineWallLayer
  PRIVATE
  refineWallLayer.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS refineWallLayer )
