add_executable( foamToStarMesh )
target_link_libraries( foamToStarMesh
  PRIVATE
  OpenFOAM
  conversion
)
target_include_directories( foamToStarMesh
  PUBLIC
  .
)
target_sources( foamToStarMesh
  PRIVATE
  foamToStarMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  getTimeIndex.H
)
install( TARGETS foamToStarMesh )
