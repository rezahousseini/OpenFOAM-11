add_executable( Test-prefixOSstream )
target_link_libraries( Test-prefixOSstream
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-prefixOSstream
  PUBLIC
  .
)
target_sources( Test-prefixOSstream
  PRIVATE
  Test-prefixOSstream.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-prefixOSstream COMMAND Test-prefixOSstream
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)