add_executable( Test-regex )
target_link_libraries( Test-regex
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-regex
  PUBLIC
  .
)
target_sources( Test-regex
  PRIVATE
  Test-regex.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-regex COMMAND Test-regex
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)