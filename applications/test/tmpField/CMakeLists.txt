add_executable( Test-tmpField )
target_link_libraries( Test-tmpField
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-tmpField
  PUBLIC
  .
)
target_sources( Test-tmpField
  PRIVATE
  Test-tmpField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-tmpField COMMAND Test-tmpField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)