add_library( phaseCompressibleMomentumTransportModels )
target_link_libraries( phaseCompressibleMomentumTransportModels
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  finiteVolume
)
target_include_directories( phaseCompressibleMomentumTransportModels
  PUBLIC
  .
)
target_sources( phaseCompressibleMomentumTransportModels
  PRIVATE
  derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonmWallFunction/epsilonmWallFunctionFvPatchScalarField.C
  phaseCompressibleMomentumTransportModel.C
  phaseCompressibleMomentumTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  LES/Niceno/NicenoKEqn.H
  LES/SmagorinskyZhang/SmagorinskyZhang.H
  LES/continuousGasKEqn/continuousGasKEqn.H
  RAS/LaheyKEpsilon/LaheyKEpsilon.H
  RAS/continuousGasKEpsilon/continuousGasKEpsilon.H
  RAS/kOmegaSSTSato/kOmegaSSTSato.H
  RAS/mixtureKEpsilon/mixtureKEpsilon.H
  derivedFvPatchFields/wallFunctions/epsilonWallFunctions/epsilonmWallFunction/epsilonmWallFunctionFvPatchScalarField.H
  makePhaseCompressibleMomentumTransportModel.H
  phaseCompressibleMomentumTransportModel.H
  phaseCompressibleMomentumTransportModels.H
)
install( TARGETS phaseCompressibleMomentumTransportModels )
