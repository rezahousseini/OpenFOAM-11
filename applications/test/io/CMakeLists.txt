add_executable( Test-io )
target_link_libraries( Test-io
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-io
  PUBLIC
  .
)
target_sources( Test-io
  PRIVATE
  Test-io.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-io COMMAND Test-io
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)