add_library( Pstream )
target_link_libraries( Pstream
  PRIVATE
  OSspecific
)
target_include_directories( Pstream
  PUBLIC
  .
  PRIVATE
  $<TARGET_PROPERTY:OpenFOAM,INCLUDE_DIRECTORIES> # break cyclic dependency with target OpenFOAM
)
target_sources( Pstream
  PRIVATE
  UIPread.C
  UOPwrite.C
  UPstream.C
)
install( TARGETS Pstream )
