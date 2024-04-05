add_library( fluidMulticomponentThermophysicalTransportModels )
target_link_libraries( fluidMulticomponentThermophysicalTransportModels
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  fluidThermophysicalModels
  multicomponentThermophysicalModels
  thermophysicalTransportModel

  PUBLIC
  fluidThermophysicalTransportModel
)
target_include_directories( fluidMulticomponentThermophysicalTransportModels
  PUBLIC
  .
)
target_sources( fluidMulticomponentThermophysicalTransportModels
  PRIVATE
  fluidMulticomponentThermophysicalTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  fluidMulticomponentThermophysicalTransportModel.H
  fluidMulticomponentThermophysicalTransportModels.H
)
install( TARGETS fluidMulticomponentThermophysicalTransportModels )
