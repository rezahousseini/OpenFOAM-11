add_executable( rhoPorousSimpleFoam )
target_link_libraries( rhoPorousSimpleFoam
  PRIVATE
  OpenFOAM
  #Pstream
  compressibleMomentumTransportModels
  coupledThermophysicalTransportModels
  #finiteVolume
  fluidThermophysicalModels
  fluidThermophysicalTransportModel
  fluidThermoThermophysicalTransportModels
  fvConstraints
  fvModels
  #meshTools
  #momentumTransportModels
  #physicalProperties
  sampling
  #specie
  #thermophysicalTransportModel
)
target_include_directories( rhoPorousSimpleFoam
  PUBLIC
  .
)
target_sources( rhoPorousSimpleFoam
  PRIVATE
  rhoPorousSimpleFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  EEqn.H
  UEqn.H
  createFields.H
  createZones.H
  pEqn.H
)
install( TARGETS rhoPorousSimpleFoam )
