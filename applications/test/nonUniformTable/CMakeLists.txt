add_executable( Test-nonUniformTable )
target_link_libraries( Test-nonUniformTable
  PRIVATE
  OpenFOAM
  thermophysicalProperties
)
target_include_directories( Test-nonUniformTable
  PUBLIC
  .
)
target_sources( Test-nonUniformTable
  PRIVATE
  Test-nonUniformTable.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-nonUniformTable COMMAND Test-nonUniformTable
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)