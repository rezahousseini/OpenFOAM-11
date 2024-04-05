add_executable( Test-syncTools )
target_link_libraries( Test-syncTools
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-syncTools
  PUBLIC
  .
)
target_sources( Test-syncTools
  PRIVATE
  Test-syncTools.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-syncTools COMMAND Test-syncTools
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)