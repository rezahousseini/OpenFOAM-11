add_library( waves )
target_link_libraries( waves
  PRIVATE
  OpenFOAM
  atmosphericModels
  dynamicMesh
  #finiteVolume
  #meshTools
)
target_include_directories( waves
  PUBLIC
  .
)
target_sources( waves
  PRIVATE
  derivedFvPatchFields/waveAlpha/waveAlphaFvPatchScalarField.C
  derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchFields.C
  derivedFvPatchFields/waveVelocity/waveVelocityFvPatchVectorField.C
  fvModels/forcing/forcing.C
  fvModels/isotropicDamping/isotropicDamping.C
  fvModels/verticalDamping/verticalDamping.C
  fvModels/waveForcing/waveForcing.C
  waveModels/Airy/Airy.C
  waveModels/Stokes2/Stokes2.C
  waveModels/Stokes5/Stokes5.C
  waveModels/solitary/solitary.C
  waveModels/waveModel/waveModel.C
  waveModels/waveModel/waveModelNew.C
  waveSuperpositions/waveAtmBoundaryLayerSuperposition/waveAtmBoundaryLayerSuperposition.C
  waveSuperpositions/waveSuperposition/waveSuperposition.C
  waveSuperpositions/waveSuperposition/waveSuperpositionNew.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  derivedFvPatchFields/waveAlpha/waveAlphaFvPatchScalarField.H
  derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchField.H
  derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchFields.H
  derivedFvPatchFields/waveInletOutlet/waveInletOutletFvPatchFieldsFwd.H
  derivedFvPatchFields/waveVelocity/waveVelocityFvPatchVectorField.H
  fvModels/forcing/forcing.H
  fvModels/isotropicDamping/isotropicDamping.H
  fvModels/verticalDamping/verticalDamping.H
  fvModels/waveForcing/waveForcing.H
  waveModels/Airy/Airy.H
  waveModels/Stokes2/Stokes2.H
  waveModels/Stokes5/Stokes5.H
  waveModels/solitary/solitary.H
  waveModels/waveModel/waveModel.H
  waveSuperpositions/waveAtmBoundaryLayerSuperposition/waveAtmBoundaryLayerSuperposition.H
  waveSuperpositions/waveSuperposition/waveSuperposition.H
)
install( TARGETS waves )
