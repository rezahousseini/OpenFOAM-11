add_executable( Test-Matrix )
target_link_libraries( Test-Matrix
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Matrix
  PUBLIC
  .
)
target_sources( Test-Matrix
  PRIVATE
  Test-Matrix.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Matrix COMMAND Test-Matrix
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)