add_executable( Test-quaternion )
target_link_libraries( Test-quaternion
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-quaternion
  PUBLIC
  .
)
target_sources( Test-quaternion
  PRIVATE
  Test-quaternion.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-quaternion COMMAND Test-quaternion
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)