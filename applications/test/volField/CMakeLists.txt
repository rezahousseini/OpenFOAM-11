add_executable( Test-volField )
target_link_libraries( Test-volField
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-volField
  PUBLIC
  .
)
target_sources( Test-volField
  PRIVATE
  Test-volField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-volField COMMAND Test-volField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)