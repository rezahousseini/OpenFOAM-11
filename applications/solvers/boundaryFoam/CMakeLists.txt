add_executable( boundaryFoam )
target_link_libraries( boundaryFoam
  PRIVATE
  OpenFOAM
  finiteVolume
  fvConstraints
  fvModels
  incompressibleMomentumTransportModels
  meshTools
  momentumTransportModels
  physicalProperties
  sampling
)
target_include_directories( boundaryFoam
  PUBLIC
  .
)
target_sources( boundaryFoam
  PRIVATE
  boundaryFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
  evaluateNearWall.H
  interrogateWallPatches.H
  makeGraphs.H
)
install( TARGETS boundaryFoam )
