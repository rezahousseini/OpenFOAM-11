add_executable( porousSimpleFoam )
target_link_libraries( porousSimpleFoam
  PRIVATE
  OpenFOAM
  fvConstraints
  fvModels
  incompressibleMomentumTransportModels
  sampling
)
target_include_directories( porousSimpleFoam
  PUBLIC
  .
)
target_sources( porousSimpleFoam
  PRIVATE
  porousSimpleFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  UEqn.H
  createFields.H
  createPorousZones.H
  pEqn.H
)
install( TARGETS porousSimpleFoam )
