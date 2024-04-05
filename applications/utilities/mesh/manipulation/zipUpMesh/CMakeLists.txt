add_executable( zipUpMesh )
target_link_libraries( zipUpMesh
  PRIVATE
  OpenFOAM
  genericPatches
  meshTools
)
target_include_directories( zipUpMesh
  PUBLIC
  .
)
target_sources( zipUpMesh
  PRIVATE
  zipUpMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS zipUpMesh )
