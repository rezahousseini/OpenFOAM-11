add_executable( surfaceRefineRedGreen )
target_link_libraries( surfaceRefineRedGreen
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceRefineRedGreen
  PUBLIC
  .
)
target_sources( surfaceRefineRedGreen
  PRIVATE
  surfaceRefineRedGreen.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceRefineRedGreen )
