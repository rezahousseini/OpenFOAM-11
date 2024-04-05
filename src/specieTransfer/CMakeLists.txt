add_library( specieTransfer )
target_link_libraries( specieTransfer
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  #finiteVolume
  fluidThermophysicalModels
  fluidThermophysicalTransportModel
  #meshTools
  #momentumTransportModels
  multicomponentThermophysicalModels
  #physicalProperties
  #specie
  thermophysicalTransportModel
)
target_include_directories( specieTransfer
  PUBLIC
  .
)
target_sources( specieTransfer
  PRIVATE
  derivedFvPatchFields/adsorptionMassFraction/adsorptionMassFractionFvPatchScalarField.C
  derivedFvPatchFields/semiPermeableBaffleMassFraction/semiPermeableBaffleMassFractionFvPatchScalarField.C
  derivedFvPatchFields/specieTransferMassFraction/specieTransferMassFractionFvPatchScalarField.C
  derivedFvPatchFields/specieTransferTemperature/specieTransferTemperatureFvPatchScalarField.C
  derivedFvPatchFields/specieTransferVelocity/specieTransferVelocityFvPatchVectorField.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  derivedFvPatchFields/adsorptionMassFraction/adsorptionMassFractionFvPatchScalarField.H
  derivedFvPatchFields/semiPermeableBaffleMassFraction/semiPermeableBaffleMassFractionFvPatchScalarField.H
  derivedFvPatchFields/specieTransferMassFraction/specieTransferMassFractionFvPatchScalarField.H
  derivedFvPatchFields/specieTransferTemperature/specieTransferTemperatureFvPatchScalarField.H
  derivedFvPatchFields/specieTransferVelocity/specieTransferVelocityFvPatchVectorField.H
)
install( TARGETS specieTransfer )
