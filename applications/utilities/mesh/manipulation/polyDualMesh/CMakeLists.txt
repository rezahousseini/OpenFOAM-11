add_executable( polyDualMesh )
target_link_libraries( polyDualMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( polyDualMesh
  PUBLIC
  .
)
target_sources( polyDualMesh
  PRIVATE
  meshDualiser.C
  polyDualMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  meshDualiser.H
)
install( TARGETS polyDualMesh )
