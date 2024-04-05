add_executable( mdInitialise )
target_link_libraries( mdInitialise
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  lagrangian
  meshTools
  molecularMeasurements
  molecule
  potential
)
target_include_directories( mdInitialise
  PUBLIC
  .
)
target_sources( mdInitialise
  PRIVATE
  mdInitialise.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS mdInitialise )
