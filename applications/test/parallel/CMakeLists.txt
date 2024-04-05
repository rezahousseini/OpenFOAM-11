add_executable( Test-parallel )
target_link_libraries( Test-parallel
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-parallel
  PUBLIC
  .
)
target_sources( Test-parallel
  PRIVATE
  Test-parallel.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-parallel COMMAND Test-parallel
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)