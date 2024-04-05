add_library( scotchDecomp )
target_link_libraries( scotchDecomp
  PRIVATE
  OpenFOAM
  decompositionMethods
  scotchDecomp
)
target_include_directories( scotchDecomp
  PUBLIC
  .
)
target_sources( scotchDecomp
  PRIVATE
  dummyScotchDecomp.C
)
install( TARGETS scotchDecomp )
