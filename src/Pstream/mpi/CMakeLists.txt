add_library( Pstream )
target_link_libraries( Pstream
  PRIVATE
  OSspecific
  MPI::MPI_CXX
)
target_include_directories( Pstream
  PUBLIC
  .
  PRIVATE
  $<TARGET_PROPERTY:OpenFOAM,INCLUDE_DIRECTORIES> # break cyclic dependency with target OpenFOAM
)
target_sources( Pstream
  PRIVATE
  PstreamGlobals.C
  UIPread.C
  UOPwrite.C
  UPstream.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  PstreamGlobals.H
  allReduce.H
)
install( TARGETS Pstream )
