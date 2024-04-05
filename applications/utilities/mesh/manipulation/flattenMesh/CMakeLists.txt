add_executable( flattenMesh )
target_link_libraries( flattenMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( flattenMesh
  PUBLIC
  .
)
target_sources( flattenMesh
  PRIVATE
  flattenMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS flattenMesh )
