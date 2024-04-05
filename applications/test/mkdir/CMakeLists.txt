add_executable( Test-mkdir )
target_link_libraries( Test-mkdir
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-mkdir
  PUBLIC
  .
)
target_sources( Test-mkdir
  PRIVATE
  Test-mkdir.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-mkdir COMMAND Test-mkdir
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)