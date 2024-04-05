add_library( compressibleMomentumTransportModels )
target_link_libraries( compressibleMomentumTransportModels
  PRIVATE
  OpenFOAM

  PUBLIC
  momentumTransportModels
)
target_include_directories( compressibleMomentumTransportModels
  PUBLIC
  .
)
target_sources( compressibleMomentumTransportModels
  PRIVATE
  compressibleMomentumTransportModel.C
  compressibleMomentumTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  RAS/buoyantKEpsilon/buoyantKEpsilon.H
  compressibleMomentumTransportModel.H
  compressibleMomentumTransportModels.H
  makeCompressibleMomentumTransportModel.H
)
install( TARGETS compressibleMomentumTransportModels )
