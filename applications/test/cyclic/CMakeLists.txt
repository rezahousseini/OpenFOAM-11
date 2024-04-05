add_executable( Test-cyclic )
target_link_libraries( Test-cyclic
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-cyclic
  PUBLIC
  .
)
target_sources( Test-cyclic
  PRIVATE
  Test-cyclic.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
add_test( NAME Test-cyclic COMMAND Test-cyclic
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)