add_executable( rotateMesh )
target_link_libraries( rotateMesh
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatches
)
target_include_directories( rotateMesh
  PUBLIC
  .
)
target_sources( rotateMesh
  PRIVATE
  rotateMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS rotateMesh )
