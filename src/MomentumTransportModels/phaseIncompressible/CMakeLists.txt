add_library( phaseIncompressibleMomentumTransportModels )
target_link_libraries( phaseIncompressibleMomentumTransportModels
  PRIVATE
  OpenFOAM

  PUBLIC
  incompressibleMomentumTransportModels
)
target_include_directories( phaseIncompressibleMomentumTransportModels
  PUBLIC
  .
)
target_sources( phaseIncompressibleMomentumTransportModels
  PRIVATE
  phaseIncompressibleMomentumTransportModel.C
  phaseIncompressibleMomentumTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  makePhaseIncompressibleMomentumTransportModel.H
  phaseIncompressibleMomentumTransportModel.H
  phaseIncompressibleMomentumTransportModels.H
)
install( TARGETS phaseIncompressibleMomentumTransportModels )
