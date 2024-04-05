add_library( scotchDecomp )
target_link_libraries( scotchDecomp
  PRIVATE
  OpenFOAM
  decompositionMethods
)
target_include_directories( scotchDecomp
  PUBLIC
  .
)
target_sources( scotchDecomp
  PRIVATE
  scotchDecomp.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  scotchDecomp.H
)
install( TARGETS scotchDecomp )
