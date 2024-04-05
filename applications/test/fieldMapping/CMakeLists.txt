add_executable( Test-fieldMapping )
target_link_libraries( Test-fieldMapping
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
)
target_include_directories( Test-fieldMapping
  PUBLIC
  .
)
target_sources( Test-fieldMapping
  PRIVATE
  Test-fieldMapping.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-fieldMapping COMMAND Test-fieldMapping
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)