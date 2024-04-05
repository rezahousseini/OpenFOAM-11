add_executable( Test-IOField )
target_link_libraries( Test-IOField
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-IOField
  PUBLIC
  .
)
target_sources( Test-IOField
  PRIVATE
  Test-IOField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-IOField COMMAND Test-IOField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)