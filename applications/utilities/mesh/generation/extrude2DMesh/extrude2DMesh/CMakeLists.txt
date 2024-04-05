add_library( extrude2DMesh )
target_link_libraries( extrude2DMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  surfMesh

  PUBLIC
  extrudeModel
)
target_include_directories( extrude2DMesh
  PUBLIC
  .
)
target_sources( extrude2DMesh
  PRIVATE
  extrude2DMesh/extrude2DMesh.C
  patchToPoly2DMesh/patchToPoly2DMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  extrude2DMesh/extrude2DMesh.H
  patchToPoly2DMesh/patchToPoly2DMesh.H
)
install( TARGETS extrude2DMesh )
