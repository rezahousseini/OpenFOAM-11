add_executable( surfaceCoarsen )
target_link_libraries( surfaceCoarsen
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceCoarsen
  PUBLIC
  .
)
target_sources( surfaceCoarsen
  PRIVATE
  bunnylod/progmesh.C
  bunnylod/vector.C
  surfaceCoarsen.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceCoarsen )
