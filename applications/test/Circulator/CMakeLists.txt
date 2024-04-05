add_executable( Test-Circulator )
target_link_libraries( Test-Circulator
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Circulator
  PUBLIC
  .
)
target_sources( Test-Circulator
  PRIVATE
  Test-Circulator.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Circulator COMMAND Test-Circulator
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)