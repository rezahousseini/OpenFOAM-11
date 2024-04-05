add_executable( Test-cubicEqn )
target_link_libraries( Test-cubicEqn
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-cubicEqn
  PUBLIC
  .
)
target_sources( Test-cubicEqn
  PRIVATE
  Test-cubicEqn.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-cubicEqn COMMAND Test-cubicEqn
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)