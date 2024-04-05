add_executable( sammToFoam )
target_link_libraries( sammToFoam
  PRIVATE
  OpenFOAM
  conversion
  dynamicMesh
  genericPatches
)
target_include_directories( sammToFoam
  PUBLIC
  .
)
target_sources( sammToFoam
  PRIVATE
  calcPointCells.C
  createBoundaryFaces.C
  createPolyBoundary.C
  createPolyCells.C
  fillSammAddressingTable.C
  fillSammCellShapeTable.C
  fixCollapsedEdges.C
  purgeCellShapes.C
  readBoundary.C
  readCells.C
  readCouples.C
  readPoints.C
  sammMesh.C
  sammToFoam.C
  writeMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  sammMesh.H
  starMesh.H
)
install( TARGETS sammToFoam )
