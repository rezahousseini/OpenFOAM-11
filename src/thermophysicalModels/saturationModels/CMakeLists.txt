add_library( saturationModels )
target_link_libraries( saturationModels
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( saturationModels
  PUBLIC
  .
)
target_sources( saturationModels
  PRIVATE
  Antoine/Antoine.C
  ArdenBuck/ArdenBuck.C
  constantPressure/constantPressure.C
  constantTemperature/constantTemperature.C
  function1Temperature/function1Temperature.C
  polynomialTemperature/polynomialTemperature.C
  saturationPressureModel/saturationPressureModel.C
  saturationPressureModel/saturationPressureModelNew.C
  saturationTemperatureModel/saturationTemperatureModel.C
  saturationTemperatureModel/saturationTemperatureModelNew.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Antoine/Antoine.H
  AntoineExtended/AntoineExtended.H
  ArdenBuck/ArdenBuck.H
  constantPressure/constantPressure.H
  constantTemperature/constantTemperature.H
  function1Temperature/function1Temperature.H
  polynomialTemperature/polynomialTemperature.H
  saturationPressureModel/saturationPressureModel.H
  saturationTemperatureModel/saturationTemperatureModel.H
)
install( TARGETS saturationModels )
