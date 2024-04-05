add_executable( adjointShapeOptimisationFoam )
target_link_libraries( adjointShapeOptimisationFoam
  PRIVATE
  OpenFOAM
  fvConstraints
  fvModels
  incompressibleMomentumTransportModels
)
target_include_directories( adjointShapeOptimisationFoam
  PUBLIC
  .
)
target_sources( adjointShapeOptimisationFoam
  PRIVATE
  adjointOutletPressure/adjointOutletPressureFvPatchScalarField.C
  adjointOutletVelocity/adjointOutletVelocityFvPatchVectorField.C
  adjointShapeOptimisationFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  adjointContinuityErrs.H
  adjointOutletPressure/adjointOutletPressureFvPatchScalarField.H
  adjointOutletVelocity/adjointOutletVelocityFvPatchVectorField.H
  createFields.H
  createPhia.H
  initAdjointContinuityErrs.H
)
install( TARGETS adjointShapeOptimisationFoam )
