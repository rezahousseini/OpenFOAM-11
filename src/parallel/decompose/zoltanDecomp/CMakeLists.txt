add_library( zoltanDecomp )
target_link_libraries( zoltanDecomp
  PRIVATE
  OpenFOAM
  decompositionMethods
)
target_include_directories( zoltanDecomp
  PUBLIC
  .
)
target_sources( zoltanDecomp
  PRIVATE
  zoltanDecomp.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  zoltanDecomp.H
)
install( TARGETS zoltanDecomp )
