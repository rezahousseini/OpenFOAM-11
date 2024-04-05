add_library( distributed )
target_link_libraries( distributed
  PRIVATE
  OpenFOAM
  decompositionMethods
  meshTools
)
target_include_directories( distributed
  PUBLIC
  .
)
target_sources( distributed
  PRIVATE
  distributedTriSurfaceMesh/distributedTriSurfaceMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  distributedTriSurfaceMesh/distributedTriSurfaceMesh.H
)
install( TARGETS distributed )
