add_executable( Test-sortList )
target_link_libraries( Test-sortList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-sortList
  PUBLIC
  .
)
target_sources( Test-sortList
  PRIVATE
  Test-sortList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-sortList COMMAND Test-sortList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)