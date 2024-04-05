add_library( fluidThermophysicalModels )
target_link_libraries( fluidThermophysicalModels
  PRIVATE
  OpenFOAM

  PUBLIC
  finiteVolume
  physicalProperties
  specie
  thermophysicalProperties
)
target_include_directories( fluidThermophysicalModels
  PUBLIC
  .
)
target_sources( fluidThermophysicalModels
  PRIVATE
  basicThermo/basicThermo.C
  derivedFvPatchFields/energyJump/energyJumpFvPatchScalarField.C
  derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.C
  derivedFvPatchFields/gradientEnergy/gradientEnergyCalculatedTemperatureFvPatchScalarField.C
  derivedFvPatchFields/gradientEnergy/gradientEnergyFvPatchScalarField.C
  derivedFvPatchFields/mixedEnergy/mixedEnergyCalculatedTemperatureFvPatchScalarField.C
  derivedFvPatchFields/mixedEnergy/mixedEnergyFvPatchScalarField.C
  fluidThermo/fluidThermo.C
  fluidThermo/hydrostaticInitialisation.C
  psiThermo/psiThermo.C
  psiThermo/psiThermos.C
  rhoThermo/liquidThermo.C
  rhoThermo/rhoThermo.C
  rhoThermo/rhoThermos.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  basicThermo/basicThermo.H
  derivedFvPatchFields/energyJump/energyJumpFvPatchScalarField.H
  derivedFvPatchFields/fixedEnergy/fixedEnergyFvPatchScalarField.H
  derivedFvPatchFields/gradientEnergy/gradientEnergyCalculatedTemperatureFvPatchScalarField.H
  derivedFvPatchFields/gradientEnergy/gradientEnergyFvPatchScalarField.H
  derivedFvPatchFields/mixedEnergy/mixedEnergyCalculatedTemperatureFvPatchScalarField.H
  derivedFvPatchFields/mixedEnergy/mixedEnergyFvPatchScalarField.H
  fluidThermo/fluidThermo.H
  fluidThermo/hydrostaticInitialisation.H
  heThermo/heThermo.H
  mixtures/basicMixture/basicMixture.H
  mixtures/pureMixture/pureMixture.H
  psiThermo/hePsiThermo.H
  psiThermo/psiThermo.H
  rhoThermo/heRhoThermo.H
  rhoThermo/liquidThermo.H
  rhoThermo/rhoThermo.H
)
install( TARGETS fluidThermophysicalModels )
