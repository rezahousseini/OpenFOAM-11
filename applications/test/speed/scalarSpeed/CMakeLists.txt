add_executable( Test-scalarSpeed )
target_link_libraries( Test-scalarSpeed
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-scalarSpeed
  PUBLIC
  .
)
target_sources( Test-scalarSpeed
  PRIVATE
  Test-scalarSpeed.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-scalarSpeed COMMAND Test-scalarSpeed
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)