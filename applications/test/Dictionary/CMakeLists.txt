add_executable( Test-Dictionary )
target_link_libraries( Test-Dictionary
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Dictionary
  PUBLIC
  .
)
target_sources( Test-Dictionary
  PRIVATE
  Test-Dictionary.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Dictionary COMMAND Test-Dictionary
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)