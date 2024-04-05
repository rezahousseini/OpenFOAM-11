add_executable( Test-fieldDependency )
target_link_libraries( Test-fieldDependency
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( Test-fieldDependency
  PUBLIC
  .
)
target_sources( Test-fieldDependency
  PRIVATE
  Test-fieldDependency.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-fieldDependency COMMAND Test-fieldDependency
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)