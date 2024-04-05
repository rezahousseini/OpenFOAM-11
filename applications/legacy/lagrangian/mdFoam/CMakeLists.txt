add_executable( mdFoam )
target_link_libraries( mdFoam
  PRIVATE
  OpenFOAM
  finiteVolume
  lagrangian
  molecularMeasurements
  molecule
  potential
)
target_include_directories( mdFoam
  PUBLIC
  .
)
target_sources( mdFoam
  PRIVATE
  mdFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS mdFoam )
