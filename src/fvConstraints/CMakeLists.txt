add_library( fvConstraints )
target_link_libraries( fvConstraints
  PRIVATE
  OpenFOAM
  fluidThermophysicalModels
)
target_include_directories( fvConstraints
  PUBLIC
  .
)
target_sources( fvConstraints
  PRIVATE
  bound/boundConstraint.C
  fixedTemperature/fixedTemperatureConstraint.C
  fixedValue/fixedValueConstraint.C
  limitMag/limitMag.C
  limitPressure/limitPressure.C
  limitTemperature/limitTemperature.C
  meanVelocityForce/meanVelocityForce.C
  meanVelocityForce/patchMeanVelocityForce/patchMeanVelocityForce.C
  zeroDimensionalFixedPressure/zeroDimensionalFixedPressureConstraint.C
  zeroDimensionalFixedPressure/zeroDimensionalFixedPressureModel.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  bound/boundConstraint.H
  fixedTemperature/fixedTemperatureConstraint.H
  fixedValue/fixedValueConstraint.H
  limitMag/limitMag.H
  limitPressure/limitPressure.H
  limitTemperature/limitTemperature.H
  meanVelocityForce/meanVelocityForce.H
  meanVelocityForce/patchMeanVelocityForce/patchMeanVelocityForce.H
  zeroDimensionalFixedPressure/zeroDimensionalFixedPressureConstraint.H
  zeroDimensionalFixedPressure/zeroDimensionalFixedPressureModel.H
)
install( TARGETS fvConstraints )
