add_library( fvMeshDistributors )
target_link_libraries( fvMeshDistributors
  PRIVATE
  OpenFOAM
  decompositionMethods
  dynamicMesh
  finiteVolume
)
target_include_directories( fvMeshDistributors
  PUBLIC
  .
)
target_sources( fvMeshDistributors
  PRIVATE
  distributor/fvMeshDistributorsDistributor.C
  loadBalancer/fvMeshDistributorsLoadBalancer.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  distributor/fvMeshDistributorsDistributor.H
  loadBalancer/fvMeshDistributorsLoadBalancer.H
)
install( TARGETS fvMeshDistributors )
