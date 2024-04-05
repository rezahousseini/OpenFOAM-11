add_library( atmosphericModels )
target_link_libraries( atmosphericModels
  PRIVATE
  OpenFOAM
  #finiteVolume
  fvModels
  incompressibleMomentumTransportModels
  #meshTools
  momentumTransportModels
  #physicalProperties
  triSurface
)
target_include_directories( atmosphericModels
  PUBLIC
  .
)
target_sources( atmosphericModels
  PRIVATE
  atmosphericTurbulentTransportModels.C
  derivedFvPatchFields/atmBoundaryLayer/atmBoundaryLayer.C
  derivedFvPatchFields/atmBoundaryLayerInletEpsilon/atmBoundaryLayerInletEpsilonFvPatchScalarField.C
  derivedFvPatchFields/atmBoundaryLayerInletK/atmBoundaryLayerInletKFvPatchScalarField.C
  derivedFvPatchFields/atmBoundaryLayerInletVelocity/atmBoundaryLayerInletVelocityFvPatchVectorField.C
  derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.C
  porosityModels/powerLawLopesdaCosta/powerLawLopesdaCosta.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  derivedFvPatchFields/atmBoundaryLayer/atmBoundaryLayer.H
  derivedFvPatchFields/atmBoundaryLayerInletEpsilon/atmBoundaryLayerInletEpsilonFvPatchScalarField.H
  derivedFvPatchFields/atmBoundaryLayerInletK/atmBoundaryLayerInletKFvPatchScalarField.H
  derivedFvPatchFields/atmBoundaryLayerInletVelocity/atmBoundaryLayerInletVelocityFvPatchVectorField.H
  derivedFvPatchFields/nutkAtmRoughWallFunction/nutkAtmRoughWallFunctionFvPatchScalarField.H
  kEpsilonLopesdaCosta/kEpsilonLopesdaCosta.H
  porosityModels/powerLawLopesdaCosta/powerLawLopesdaCosta.H
)
install( TARGETS atmosphericModels )
