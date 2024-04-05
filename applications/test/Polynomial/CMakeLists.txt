add_executable( Test-Polynomial )
target_link_libraries( Test-Polynomial
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Polynomial
  PUBLIC
  .
)
target_sources( Test-Polynomial
  PRIVATE
  Test-Polynomial.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Polynomial COMMAND Test-Polynomial
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)