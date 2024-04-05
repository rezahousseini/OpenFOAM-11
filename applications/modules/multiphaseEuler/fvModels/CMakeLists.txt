add_library( multiphaseEulerFoamFvModels )
target_link_libraries( multiphaseEulerFoamFvModels
  PRIVATE
  OpenFOAM
  finiteVolume
  phaseCompressibleMomentumTransportModels
  phaseSystem
)
target_include_directories( multiphaseEulerFoamFvModels
  PUBLIC
  .
)
target_sources( multiphaseEulerFoamFvModels
  PRIVATE
  interfaceTurbulenceDamping/interfaceTurbulenceDamping.C
  phaseTurbulenceStabilisation/phaseTurbulenceStabilisation.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  interfaceTurbulenceDamping/interfaceTurbulenceDamping.H
  phaseTurbulenceStabilisation/phaseTurbulenceStabilisation.H
)
install( TARGETS multiphaseEulerFoamFvModels )