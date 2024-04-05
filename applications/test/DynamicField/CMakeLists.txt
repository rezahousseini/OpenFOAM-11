add_executable( Test-DynamicField )
target_link_libraries( Test-DynamicField
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-DynamicField
  PUBLIC
  .
)
target_sources( Test-DynamicField
  PRIVATE
  Test-DynamicField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-DynamicField COMMAND Test-DynamicField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)