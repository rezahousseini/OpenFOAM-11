add_executable( dsmcInitialise )
target_link_libraries( dsmcInitialise
  PRIVATE
  OpenFOAM
  DSMC
  finiteVolume
  lagrangian
  meshTools
)
target_include_directories( dsmcInitialise
  PUBLIC
  .
)
target_sources( dsmcInitialise
  PRIVATE
  dsmcInitialise.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS dsmcInitialise )
