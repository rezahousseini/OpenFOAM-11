add_library( incompressibleFluid )
target_link_libraries( incompressibleFluid
  PRIVATE
  OpenFOAM
  finiteVolume
  fluidSolver
  incompressibleMomentumTransportModels
  physicalProperties
)
target_include_directories( incompressibleFluid
  PUBLIC
  .
)
target_sources( incompressibleFluid
  PRIVATE
  correctPressure.C
  incompressibleFluid.C
  momentumPredictor.C
  moveMesh.C
  setRDeltaT.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  incompressibleFluid.H
)
install( TARGETS incompressibleFluid )