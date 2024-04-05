add_executable( Test-rigidBodyDynamics )
target_link_libraries( Test-rigidBodyDynamics
  PRIVATE
  OpenFOAM
  rigidBodyDynamics
)
target_include_directories( Test-rigidBodyDynamics
  PUBLIC
  .
)
target_sources( Test-rigidBodyDynamics
  PRIVATE
  Test-rigidBodyDynamics.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-rigidBodyDynamics COMMAND Test-rigidBodyDynamics
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)