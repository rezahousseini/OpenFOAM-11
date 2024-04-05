add_executable( selectCells )
target_link_libraries( selectCells
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  lagrangian
  meshTools
  triSurface
)
target_include_directories( selectCells
  PUBLIC
  .
)
target_sources( selectCells
  PRIVATE
  edgeStats.C
  selectCells.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  edgeStats.H
)
install( TARGETS selectCells )
