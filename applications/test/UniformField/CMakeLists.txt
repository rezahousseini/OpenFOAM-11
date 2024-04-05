add_executable( Test-UniformField )
target_link_libraries( Test-UniformField
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-UniformField
  PUBLIC
  .
)
target_sources( Test-UniformField
  PRIVATE
  Test-UniformField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-UniformField COMMAND Test-UniformField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)