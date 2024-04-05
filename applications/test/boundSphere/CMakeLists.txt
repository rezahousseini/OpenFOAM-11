add_executable( Test-boundSphere )
target_link_libraries( Test-boundSphere
  PRIVATE
  OpenFOAM
  fileFormats
)
target_include_directories( Test-boundSphere
  PUBLIC
  .
)
target_sources( Test-boundSphere
  PRIVATE
  Test-boundSphere.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-boundSphere COMMAND Test-boundSphere
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)