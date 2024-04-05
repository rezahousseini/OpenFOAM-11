add_executable( Test-Map )
target_link_libraries( Test-Map
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Map
  PUBLIC
  .
)
target_sources( Test-Map
  PRIVATE
  Test-Map.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Map COMMAND Test-Map
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)