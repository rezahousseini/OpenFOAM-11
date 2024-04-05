add_executable( modifyMesh )
target_link_libraries( modifyMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( modifyMesh
  PUBLIC
  .
)
target_sources( modifyMesh
  PRIVATE
  cellSplitter.C
  modifyMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  cellSplitter.H
)
install( TARGETS modifyMesh )
