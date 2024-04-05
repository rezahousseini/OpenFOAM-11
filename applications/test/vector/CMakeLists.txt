add_executable( Test-vector )
target_link_libraries( Test-vector
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-vector
  PUBLIC
  .
)
target_sources( Test-vector
  PRIVATE
  Test-vector.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-vector COMMAND Test-vector
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)