add_executable( icoFoam )
target_link_libraries( icoFoam
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( icoFoam
  PUBLIC
  .
)
target_sources( icoFoam
  PRIVATE
  icoFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS icoFoam )
