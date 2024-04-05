add_executable( surfaceInertia )
target_link_libraries( surfaceInertia
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceInertia
  PUBLIC
  .
)
target_sources( surfaceInertia
  PRIVATE
  surfaceInertia.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceInertia )
