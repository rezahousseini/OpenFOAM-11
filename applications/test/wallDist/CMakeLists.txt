add_executable( Test-wallDist )
target_link_libraries( Test-wallDist
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-wallDist
  PUBLIC
  .
)
target_sources( Test-wallDist
  PRIVATE
  Test-wallDist.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-wallDist COMMAND Test-wallDist
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)