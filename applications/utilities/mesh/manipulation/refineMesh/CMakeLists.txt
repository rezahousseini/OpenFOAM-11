add_executable( refineMesh )
target_link_libraries( refineMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( refineMesh
  PUBLIC
  .
)
target_sources( refineMesh
  PRIVATE
  refineMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS refineMesh )
