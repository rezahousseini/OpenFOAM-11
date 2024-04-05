add_executable( foamToSurface )
target_link_libraries( foamToSurface
  PRIVATE
  OpenFOAM
  surfMesh
)
target_include_directories( foamToSurface
  PUBLIC
  .
)
target_sources( foamToSurface
  PRIVATE
  foamToSurface.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  getTimeIndex.H
)
install( TARGETS foamToSurface )
