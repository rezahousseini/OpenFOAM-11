add_executable( Test-Function1 )
target_link_libraries( Test-Function1
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Function1
  PUBLIC
  .
)
target_sources( Test-Function1
  PRIVATE
  Test-Function1.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Function1 COMMAND Test-Function1
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)