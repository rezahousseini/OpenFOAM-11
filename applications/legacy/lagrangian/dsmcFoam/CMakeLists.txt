add_executable( dsmcFoam )
target_link_libraries( dsmcFoam
  PRIVATE
  OpenFOAM
  DSMC
  finiteVolume
  lagrangian
)
target_include_directories( dsmcFoam
  PUBLIC
  .
)
target_sources( dsmcFoam
  PRIVATE
  dsmcFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS dsmcFoam )
