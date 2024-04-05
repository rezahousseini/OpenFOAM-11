add_library( XiFluid )
target_link_libraries( XiFluid
  PRIVATE
  OpenFOAM
  XiIgnition
  compressibleMomentumTransportModels
  finiteVolume
  fluidSolver
  fluidThermophysicalModels
  fluidThermophysicalTransportModel
  isothermalFluid
  laminarFlameSpeedModels
  multicomponentThermophysicalModels
  thermophysicalTransportModel
)
target_include_directories( XiFluid
  PUBLIC
  .
)
target_sources( XiFluid
  PRIVATE
  XiFluid.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  XiFluid.H
)
install( TARGETS XiFluid )
