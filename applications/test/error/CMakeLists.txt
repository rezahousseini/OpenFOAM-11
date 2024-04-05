add_executable( Test-error )
target_link_libraries( Test-error
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-error
  PUBLIC
  .
)
target_sources( Test-error
  PRIVATE
  Test-error.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-error COMMAND Test-error
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)