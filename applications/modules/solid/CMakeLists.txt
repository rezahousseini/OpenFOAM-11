add_library( solid )
target_link_libraries( solid
  PRIVATE
  OpenFOAM
  finiteVolume

  PUBLIC
  solidThermophysicalTransportModels
)
target_include_directories( solid
  PUBLIC
  .
)
target_sources( solid
  PRIVATE
  solid.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  solid.H
)
install( TARGETS solid )
