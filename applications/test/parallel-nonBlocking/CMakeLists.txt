add_executable( Test-parallel-nonBlocking )
target_link_libraries( Test-parallel-nonBlocking
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-parallel-nonBlocking
  PUBLIC
  .
)
target_sources( Test-parallel-nonBlocking
  PRIVATE
  Test-parallel-nonBlocking.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-parallel-nonBlocking COMMAND Test-parallel-nonBlocking
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)