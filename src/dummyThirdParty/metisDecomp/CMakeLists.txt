add_library( metisDecomp )
target_link_libraries( metisDecomp
  PRIVATE
  OpenFOAM
  decompositionMethods
  metisDecomp
)
target_include_directories( metisDecomp
  PUBLIC
  .
)
target_sources( metisDecomp
  PRIVATE
  dummyMetisDecomp.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  metis.h
)
install( TARGETS metisDecomp )
