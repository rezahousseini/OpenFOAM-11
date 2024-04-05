add_executable( Test-FixedList )
target_link_libraries( Test-FixedList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-FixedList
  PUBLIC
  .
)
target_sources( Test-FixedList
  PRIVATE
  Test-FixedList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-FixedList COMMAND Test-FixedList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)