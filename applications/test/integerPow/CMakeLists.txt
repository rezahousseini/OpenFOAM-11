add_executable( Test-integerPow )
target_link_libraries( Test-integerPow
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-integerPow
  PUBLIC
  .
)
target_sources( Test-integerPow
  PRIVATE
  Test-integerPow.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-integerPow COMMAND Test-integerPow
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)