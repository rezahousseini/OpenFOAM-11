add_library( solidThermophysicalTransportModels )
target_link_libraries( solidThermophysicalTransportModels
  PRIVATE
  OpenFOAM
  fluidThermophysicalModels

  PUBLIC
  solidThermo
  thermophysicalTransportModel
)
target_include_directories( solidThermophysicalTransportModels
  PUBLIC
  .
)
target_sources( solidThermophysicalTransportModels
  PRIVATE
  anisotropic/anisotropic.C
  isotropic/isotropic.C
  solidThermophysicalTransportModel/solidThermophysicalTransportModel.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  anisotropic/anisotropic.H
  isotropic/isotropic.H
  solidThermophysicalTransportModel/solidThermophysicalTransportModel.H
)
install( TARGETS solidThermophysicalTransportModels )
