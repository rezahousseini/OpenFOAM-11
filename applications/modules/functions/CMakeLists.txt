add_library( functions )
target_link_libraries( functions
  PRIVATE
  OpenFOAM
  movingMesh
)
target_include_directories( functions
  PUBLIC
  .
)
target_sources( functions
  PRIVATE
  functions.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  functions.H
)
install( TARGETS functions )