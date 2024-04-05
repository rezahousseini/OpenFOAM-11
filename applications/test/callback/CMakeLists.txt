add_executable( Test-callback )
target_link_libraries( Test-callback
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-callback
  PUBLIC
  .
)
target_sources( Test-callback
  PRIVATE
  Test-callback.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-callback COMMAND Test-callback
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)