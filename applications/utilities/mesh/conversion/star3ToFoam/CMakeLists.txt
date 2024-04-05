add_executable( star3ToFoam )
target_link_libraries( star3ToFoam
  PRIVATE
  OpenFOAM
  conversion
  dynamicMesh
  genericPatches
)
target_include_directories( star3ToFoam
  PUBLIC
  .
)
target_sources( star3ToFoam
  PRIVATE
  calcPointCells.C
  coupledFacePair.C
  createBoundaryFaces.C
  createCoupleMatches.C
  createPolyBoundary.C
  createPolyCells.C
  fixCollapsedEdges.C
  mergeCoupleFacePoints.C
  purgeCellShapes.C
  readBoundary.C
  readCells.C
  readCouples.C
  readPoints.C
  star3ToFoam.C
  starMesh.C
  writeMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  coupledFacePair.H
  starMesh.H
)
install( TARGETS star3ToFoam )
