add_executable( potentialFoam )
target_link_libraries( potentialFoam
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
  sampling
)
target_include_directories( potentialFoam
  PUBLIC
  .
)
target_sources( potentialFoam
  PRIVATE
  potentialFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createControls.H
  createFields.H
)
install( TARGETS potentialFoam )
