add_library( fluid )
target_link_libraries( fluid
  PRIVATE
  OpenFOAM
  finiteVolume
  fluidThermoThermophysicalTransportModels
  isothermalFluid
)
target_include_directories( fluid
  PUBLIC
  .
)
target_sources( fluid
  PRIVATE
  fluid.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  fluid.H
)
install( TARGETS fluid )