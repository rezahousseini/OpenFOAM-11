add_executable( Test-dynamicIndexedOctree )
target_link_libraries( Test-dynamicIndexedOctree
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( Test-dynamicIndexedOctree
  PUBLIC
  .
)
target_sources( Test-dynamicIndexedOctree
  PRIVATE
  Test-dynamicIndexedOctree.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-dynamicIndexedOctree COMMAND Test-dynamicIndexedOctree
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)