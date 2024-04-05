add_executable( electrostaticFoam )
target_link_libraries( electrostaticFoam
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( electrostaticFoam
  PUBLIC
  .
)
target_sources( electrostaticFoam
  PRIVATE
  electrostaticFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS electrostaticFoam )
