add_library( MGridGen_dummy )
target_link_libraries( MGridGen_dummy
  PRIVATE
  OpenFOAM
)
target_include_directories( MGridGen_dummy
  PUBLIC
  .
)
target_sources( MGridGen_dummy
  PRIVATE
  dummyMGridGen.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  mgridgen.h
)
install( TARGETS MGridGen_dummy )
