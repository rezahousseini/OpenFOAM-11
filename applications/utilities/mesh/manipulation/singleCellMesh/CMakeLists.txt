add_executable( singleCellMesh )
target_link_libraries( singleCellMesh
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
)
target_include_directories( singleCellMesh
  PUBLIC
  .
)
target_sources( singleCellMesh
  PRIVATE
  singleCellMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS singleCellMesh )
