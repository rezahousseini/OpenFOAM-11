add_library( filmCompressibleMomentumTransportModels )
target_link_libraries( filmCompressibleMomentumTransportModels
  PRIVATE
  compressibleMomentumTransportModels
  momentumTransportModels
)
target_include_directories( filmCompressibleMomentumTransportModels
  PUBLIC
  .
)
target_sources( filmCompressibleMomentumTransportModels
  PRIVATE
  filmCompressibleMomentumTransportModel.C
  filmCompressibleMomentumTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  filmCompressibleMomentumTransportModel.H
  filmCompressibleMomentumTransportModels.H
  makeFilmCompressibleMomentumTransportModel.H
)
install( TARGETS filmCompressibleMomentumTransportModels )