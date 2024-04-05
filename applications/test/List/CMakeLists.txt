add_executable( Test-List )
target_link_libraries( Test-List
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-List
  PUBLIC
  .
)
target_sources( Test-List
  PRIVATE
  Test-List.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-List COMMAND Test-List
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)