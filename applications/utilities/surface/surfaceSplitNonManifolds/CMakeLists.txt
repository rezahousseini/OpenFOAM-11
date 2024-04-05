add_executable( surfaceSplitNonManifolds )
target_link_libraries( surfaceSplitNonManifolds
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceSplitNonManifolds
  PUBLIC
  .
)
target_sources( surfaceSplitNonManifolds
  PRIVATE
  surfaceSplitNonManifolds.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceSplitNonManifolds )
