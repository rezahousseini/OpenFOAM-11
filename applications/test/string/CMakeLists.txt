add_executable( Test-string )
target_link_libraries( Test-string
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-string
  PUBLIC
  .
)
target_sources( Test-string
  PRIVATE
  Test-string.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-string COMMAND Test-string
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)