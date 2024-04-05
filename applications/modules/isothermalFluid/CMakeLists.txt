add_library( isothermalFluid )
target_link_libraries( isothermalFluid
  PRIVATE
  OpenFOAM
  finiteVolume

  PUBLIC
  compressibleMomentumTransportModels
  fluidSolver
  fluidThermophysicalModels
)
target_include_directories( isothermalFluid
  PUBLIC
  .
)
target_sources( isothermalFluid
  PRIVATE
  correctBuoyantPressure.C
  correctDensity.C
  correctPressure.C
  isothermalFluid.C
  momentumPredictor.C
  moveMesh.C
  prePredictor.C
  setRDeltaT.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  isothermalFluid.H
)
install( TARGETS isothermalFluid )
