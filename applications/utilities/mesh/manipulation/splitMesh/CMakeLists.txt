add_executable( splitMesh )
target_link_libraries( splitMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( splitMesh
  PUBLIC
  .
)
target_sources( splitMesh
  PRIVATE
  regionSide.C
  splitMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  regionSide.H
)
install( TARGETS splitMesh )
