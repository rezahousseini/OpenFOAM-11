add_library( compressibleTwoPhases )
target_link_libraries( compressibleTwoPhases
  PRIVATE
  OpenFOAM
  fluidThermophysicalModels

  PUBLIC
  twoPhaseMixture
)
target_include_directories( compressibleTwoPhases
  PUBLIC
  .
)
target_sources( compressibleTwoPhases
  PRIVATE
  compressibleTwoPhases.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  compressibleTwoPhases.H
)
install( TARGETS compressibleTwoPhases )
