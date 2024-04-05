add_executable( surfaceClean )
target_link_libraries( surfaceClean
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceClean
  PUBLIC
  .
)
target_sources( surfaceClean
  PRIVATE
  collapseBase.C
  collapseEdge.C
  surfaceClean.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  collapseBase.H
  collapseEdge.H
)
install( TARGETS surfaceClean )
