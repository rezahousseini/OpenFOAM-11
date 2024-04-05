add_executable( attachMesh )
target_link_libraries( attachMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( attachMesh
  PUBLIC
  .
)
target_sources( attachMesh
  PRIVATE
  attachMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS attachMesh )
