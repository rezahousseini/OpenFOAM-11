add_executable( Test-simpleMatrix )
target_link_libraries( Test-simpleMatrix
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-simpleMatrix
  PUBLIC
  .
)
target_sources( Test-simpleMatrix
  PRIVATE
  Test-simpleMatrix.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-simpleMatrix COMMAND Test-simpleMatrix
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)