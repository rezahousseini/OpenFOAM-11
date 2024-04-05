add_executable( subsetMesh )
target_link_libraries( subsetMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatchFields
)
target_include_directories( subsetMesh
  PUBLIC
  .
)
target_sources( subsetMesh
  PRIVATE
  subsetMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS subsetMesh )
