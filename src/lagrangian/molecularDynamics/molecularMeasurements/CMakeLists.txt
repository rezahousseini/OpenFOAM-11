add_library( molecularMeasurements )
target_link_libraries( molecularMeasurements
  PRIVATE
  OpenFOAM
)
target_include_directories( molecularMeasurements
  PUBLIC
  .
)
target_sources( molecularMeasurements
  PRIVATE
  distribution/distribution.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  bufferedAccumulator/bufferedAccumulator.H
  bufferedAccumulator/bufferedAccumulatorI.H
  correlationFunction/correlationFunction.H
  correlationFunction/correlationFunctionI.H
  distribution/distribution.H
  distribution/distributionI.H
)
install( TARGETS molecularMeasurements )
