add_library( fluidThermoThermophysicalTransportModels )
target_link_libraries( fluidThermoThermophysicalTransportModels
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  fluidThermophysicalModels
  thermophysicalTransportModel

  PUBLIC
  fluidThermophysicalTransportModel
)
target_include_directories( fluidThermoThermophysicalTransportModels
  PUBLIC
  .
)
target_sources( fluidThermoThermophysicalTransportModels
  PRIVATE
  fluidThermoThermophysicalTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  fluidThermoThermophysicalTransportModel.H
  fluidThermoThermophysicalTransportModels.H
)
install( TARGETS fluidThermoThermophysicalTransportModels )
