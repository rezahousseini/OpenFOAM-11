add_library( phaseFluidThermophysicalTransportModels )
target_link_libraries( phaseFluidThermophysicalTransportModels
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  fluidThermophysicalModels
  fluidThermophysicalTransportModel
  phaseCompressibleMomentumTransportModels
  thermophysicalTransportModel
)
target_include_directories( phaseFluidThermophysicalTransportModels
  PUBLIC
  .
)
target_sources( phaseFluidThermophysicalTransportModels
  PRIVATE
  phaseFluidThermophysicalTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  phaseFluidThermophysicalTransportModel.H
  phaseFluidThermophysicalTransportModels.H
)
install( TARGETS phaseFluidThermophysicalTransportModels )
