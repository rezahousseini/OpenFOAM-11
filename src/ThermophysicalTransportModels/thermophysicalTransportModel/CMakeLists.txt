add_library( thermophysicalTransportModel )
target_link_libraries( thermophysicalTransportModel
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( thermophysicalTransportModel
  PUBLIC
  .
)
target_sources( thermophysicalTransportModel
  PRIVATE
  thermophysicalTransportModel.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  thermophysicalTransportModel.H
)
install( TARGETS thermophysicalTransportModel )
