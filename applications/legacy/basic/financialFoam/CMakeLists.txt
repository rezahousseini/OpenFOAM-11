add_executable( financialFoam )
target_link_libraries( financialFoam
  PRIVATE
  OpenFOAM
  finiteVolume
  sampling
)
target_include_directories( financialFoam
  PUBLIC
  .
)
target_sources( financialFoam
  PRIVATE
  financialFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS financialFoam )
