add_executable( surfaceOrient )
target_link_libraries( surfaceOrient
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceOrient
  PUBLIC
  .
)
target_sources( surfaceOrient
  PRIVATE
  surfaceOrient.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceOrient )
