add_library( metisDecomp )
target_link_libraries( metisDecomp
  PRIVATE
  OpenFOAM
  decompositionMethods
  ${METIS_LIBRARY}
)
target_include_directories( metisDecomp
  PUBLIC
  .
  PRIVATE
  ${METIS_INCLUDE_DIRECTORY}
)
target_sources( metisDecomp
  PRIVATE
  metisDecomp.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  metisDecomp.H
)
install( TARGETS metisDecomp )
