add_executable( Test-findCell-octree )
target_link_libraries( Test-findCell-octree
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-findCell-octree
  PUBLIC
  .
)
target_sources( Test-findCell-octree
  PRIVATE
  Test-findCell-octree.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-findCell-octree COMMAND Test-findCell-octree
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)