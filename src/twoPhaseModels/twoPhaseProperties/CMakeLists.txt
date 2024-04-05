add_library( twoPhaseProperties )
target_link_libraries( twoPhaseProperties
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( twoPhaseProperties
  PUBLIC
  .
)
target_sources( twoPhaseProperties
  PRIVATE
  alphaFixedPressure/alphaFixedPressureFvPatchScalarField.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  alphaFixedPressure/alphaFixedPressureFvPatchScalarField.H
)
install( TARGETS twoPhaseProperties )
