add_executable( refineHexMesh )
target_link_libraries( refineHexMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  genericPatches
  meshTools
)
target_include_directories( refineHexMesh
  PUBLIC
  .
)
target_sources( refineHexMesh
  PRIVATE
  refineHexMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS refineHexMesh )
