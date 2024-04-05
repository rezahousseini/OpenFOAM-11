add_executable( Test-dictionary )
target_link_libraries( Test-dictionary
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-dictionary
  PUBLIC
  .
)
target_sources( Test-dictionary
  PRIVATE
  Test-dictionary.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-dictionary COMMAND Test-dictionary
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)