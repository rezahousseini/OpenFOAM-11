add_executable( extrudeMesh )
target_link_libraries( extrudeMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  extrudeModel
  finiteVolume
  genericPatchFields
  meshTools
  surfMesh
)
target_include_directories( extrudeMesh
  PUBLIC
  .
)
target_sources( extrudeMesh
  PRIVATE
  extrudeMesh.C
  extrudedMesh/extrudedMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createTimeExtruded.H
  extrudedMesh/extrudedMesh.H
)
install( TARGETS extrudeMesh )
