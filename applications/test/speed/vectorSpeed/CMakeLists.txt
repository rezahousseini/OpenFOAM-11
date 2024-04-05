add_executable( Test-vectorSpeed )
target_link_libraries( Test-vectorSpeed
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-vectorSpeed
  PUBLIC
  .
)
target_sources( Test-vectorSpeed
  PRIVATE
  Test-vectorSpeed.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-vectorSpeed COMMAND Test-vectorSpeed
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)