add_library( coupledThermophysicalTransportModels )
target_link_libraries( coupledThermophysicalTransportModels
  PRIVATE
  OpenFOAM
  finiteVolume
  thermophysicalTransportModel
)
target_include_directories( coupledThermophysicalTransportModels
  PUBLIC
  .
)
target_sources( coupledThermophysicalTransportModels
  PRIVATE
  coupledTemperature/coupledTemperatureFvPatchScalarField.C
  externalTemperature/externalTemperatureFvPatchScalarField.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  coupledTemperature/coupledTemperatureFvPatchScalarField.H
  externalTemperature/externalTemperatureFvPatchScalarField.H
)
install( TARGETS coupledThermophysicalTransportModels )
