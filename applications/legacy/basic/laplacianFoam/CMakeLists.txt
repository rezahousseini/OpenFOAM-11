add_executable( laplacianFoam )
target_link_libraries( laplacianFoam
  PRIVATE
  OpenFOAM
  finiteVolume
  fvConstraints
  fvModels
)
target_include_directories( laplacianFoam
  PUBLIC
  .
)
target_sources( laplacianFoam
  PRIVATE
  laplacianFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
  write.H
)
install( TARGETS laplacianFoam )
