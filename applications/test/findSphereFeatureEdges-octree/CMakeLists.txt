add_executable( Test-findSphereFeatureEdges-octree )
target_link_libraries( Test-findSphereFeatureEdges-octree
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-findSphereFeatureEdges-octree
  PUBLIC
  .
)
target_sources( Test-findSphereFeatureEdges-octree
  PRIVATE
  Test-findSphereFeatureEdges-octree.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-findSphereFeatureEdges-octree COMMAND Test-findSphereFeatureEdges-octree
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)