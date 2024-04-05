add_library( ptscotchDecomp )
target_link_libraries( ptscotchDecomp
  PRIVATE
  OpenFOAM
  decompositionMethods
)
target_include_directories( ptscotchDecomp
  PUBLIC
  .
)
target_sources( ptscotchDecomp
  PRIVATE
  ptscotchDecomp.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  ptscotchDecomp.H
)
install( TARGETS ptscotchDecomp )
