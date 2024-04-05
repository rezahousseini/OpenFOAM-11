add_executable( surfaceAutoPatch )
target_link_libraries( surfaceAutoPatch
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceAutoPatch
  PUBLIC
  .
)
target_sources( surfaceAutoPatch
  PRIVATE
  surfaceAutoPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceAutoPatch )
