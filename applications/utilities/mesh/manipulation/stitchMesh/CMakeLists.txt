add_executable( stitchMesh )
target_link_libraries( stitchMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( stitchMesh
  PUBLIC
  .
)
target_sources( stitchMesh
  PRIVATE
  stitchMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS stitchMesh )
