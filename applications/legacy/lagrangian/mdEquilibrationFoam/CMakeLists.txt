add_executable( mdEquilibrationFoam )
target_link_libraries( mdEquilibrationFoam
  PRIVATE
  OpenFOAM
  finiteVolume
  lagrangian
  molecularMeasurements
  molecule
  potential
)
target_include_directories( mdEquilibrationFoam
  PUBLIC
  .
)
target_sources( mdEquilibrationFoam
  PRIVATE
  mdEquilibrationFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  readmdEquilibrationDict.H
)
install( TARGETS mdEquilibrationFoam )
