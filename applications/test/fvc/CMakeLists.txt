add_executable( Test-fvc )
target_link_libraries( Test-fvc
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-fvc
  PUBLIC
  .
)
target_sources( Test-fvc
  PRIVATE
  Test-fvc.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-fvc COMMAND Test-fvc
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)