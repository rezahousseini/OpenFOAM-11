add_executable( Test-SHA1 )
target_link_libraries( Test-SHA1
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-SHA1
  PUBLIC
  .
)
target_sources( Test-SHA1
  PRIVATE
  Test-SHA1.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-SHA1 COMMAND Test-SHA1
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)