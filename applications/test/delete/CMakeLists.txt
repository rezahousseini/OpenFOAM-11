add_executable( Test-delete )
target_link_libraries( Test-delete
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-delete
  PUBLIC
  .
)
target_sources( Test-delete
  PRIVATE
  Test-delete.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-delete COMMAND Test-delete
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)