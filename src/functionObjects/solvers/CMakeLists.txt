add_library( solverFunctionObjects )
target_link_libraries( solverFunctionObjects
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  incompressibleMomentumTransportModels
  interfaceCompression
)
target_include_directories( solverFunctionObjects
  PUBLIC
  .
)
target_sources( solverFunctionObjects
  PRIVATE
  phaseScalarTransport/phaseScalarTransport.C
  scalarTransport/scalarTransport.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  phaseScalarTransport/phaseScalarTransport.H
  scalarTransport/scalarTransport.H
)
install( TARGETS solverFunctionObjects )
