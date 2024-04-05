add_executable( surfaceSubset )
target_link_libraries( surfaceSubset
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceSubset
  PUBLIC
  .
)
target_sources( surfaceSubset
  PRIVATE
  surfaceSubset.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceSubset )
