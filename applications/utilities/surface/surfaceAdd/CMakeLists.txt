add_executable( surfaceAdd )
target_link_libraries( surfaceAdd
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceAdd
  PUBLIC
  .
)
target_sources( surfaceAdd
  PRIVATE
  surfaceAdd.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceAdd )
