add_library( shockFluid )
target_link_libraries( shockFluid
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  finiteVolume
  fluidSolver
  fluidThermoThermophysicalTransportModels
  fluidThermophysicalModels
)
target_include_directories( shockFluid
  PUBLIC
  .
)
target_sources( shockFluid
  PRIVATE
  correctDensity.C
  derivedFvPatchFields/T/smoluchowskiJumpTFvPatchScalarField.C
  derivedFvPatchFields/U/maxwellSlipUFvPatchVectorField.C
  derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchFields.C
  derivedFvPatchFields/rho/fixedRhoFvPatchScalarField.C
  fluxPredictor.C
  momentumPredictor.C
  moveMesh.C
  prePredictor.C
  pressureCorrector.C
  setRDeltaT.C
  shockFluid.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  derivedFvPatchFields/T/smoluchowskiJumpTFvPatchScalarField.H
  derivedFvPatchFields/U/maxwellSlipUFvPatchVectorField.H
  derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchField.H
  derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchFields.H
  derivedFvPatchFields/mixedFixedValueSlip/mixedFixedValueSlipFvPatchFieldsFwd.H
  derivedFvPatchFields/rho/fixedRhoFvPatchScalarField.H
  shockFluid.H
)
install( TARGETS shockFluid )