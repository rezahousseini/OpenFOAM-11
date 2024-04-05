add_executable( surfacePointMerge )
target_link_libraries( surfacePointMerge
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfacePointMerge
  PUBLIC
  .
)
target_sources( surfacePointMerge
  PRIVATE
  surfacePointMerge.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfacePointMerge )
