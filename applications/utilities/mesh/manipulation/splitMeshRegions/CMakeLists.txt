add_executable( splitMeshRegions )
target_link_libraries( splitMeshRegions
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( splitMeshRegions
  PUBLIC
  .
)
target_sources( splitMeshRegions
  PRIVATE
  splitMeshRegions.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS splitMeshRegions )
