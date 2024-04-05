add_library( incompressibleTwoPhases )
target_link_libraries( incompressibleTwoPhases
  PRIVATE
  OpenFOAM
  twoPhaseMixture
)
target_include_directories( incompressibleTwoPhases
  PUBLIC
  .
)
target_sources( incompressibleTwoPhases
  PRIVATE
  incompressibleTwoPhases.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  incompressibleTwoPhases.H
)
install( TARGETS incompressibleTwoPhases )
