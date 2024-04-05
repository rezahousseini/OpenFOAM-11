add_library( filmThermophysicalTransportModels )
target_link_libraries( filmThermophysicalTransportModels
  PRIVATE
  fluidThermophysicalTransportModel
)
target_include_directories( filmThermophysicalTransportModels
  PUBLIC
  .
)
target_sources( filmThermophysicalTransportModels
  PRIVATE
  filmThermophysicalTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  filmThermophysicalTransportModel.H
  filmThermophysicalTransportModels.H
)
install( TARGETS filmThermophysicalTransportModels )