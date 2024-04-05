add_executable( Test-distribution )
target_link_libraries( Test-distribution
  PRIVATE
  OpenFOAM
  sampling
)
target_include_directories( Test-distribution
  PUBLIC
  .
)
target_sources( Test-distribution
  PRIVATE
  Test-distribution.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-distribution COMMAND Test-distribution
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)