add_library( movingMesh )
target_link_libraries( movingMesh
  PRIVATE
  OpenFOAM

  PUBLIC
  finiteVolume
)
target_include_directories( movingMesh
  PUBLIC
  .
)
target_sources( movingMesh
  PRIVATE
  movingMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  movingMesh.H
)
install( TARGETS movingMesh )
