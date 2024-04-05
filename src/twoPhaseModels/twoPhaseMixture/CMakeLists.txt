add_library( twoPhaseMixture )
target_link_libraries( twoPhaseMixture
  PRIVATE
  OpenFOAM
  physicalProperties

  PUBLIC
  finiteVolume
)
target_include_directories( twoPhaseMixture
  PUBLIC
  .
)
target_sources( twoPhaseMixture
  PRIVATE
  twoPhaseMixture.C
  twoPhases.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  twoPhaseMixture.H
  twoPhases.H
)
install( TARGETS twoPhaseMixture )
