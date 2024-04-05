add_executable( Test-ODE )
target_link_libraries( Test-ODE
  PRIVATE
  ODE
  OpenFOAM
)
target_include_directories( Test-ODE
  PUBLIC
  .
)
target_sources( Test-ODE
  PRIVATE
  Test-ODE.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-ODE COMMAND Test-ODE
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)