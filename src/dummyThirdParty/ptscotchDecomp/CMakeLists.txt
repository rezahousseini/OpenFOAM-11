add_library( ptscotchDecomp )
target_link_libraries( ptscotchDecomp
  PRIVATE
  OpenFOAM
  decompositionMethods
  ptscotchDecomp
)
target_include_directories( ptscotchDecomp
  PUBLIC
  .
)
target_sources( ptscotchDecomp
  PRIVATE
  dummyPtscotchDecomp.C
)
install( TARGETS ptscotchDecomp )
