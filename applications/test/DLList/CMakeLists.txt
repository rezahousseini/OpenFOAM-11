add_executable( Test-DLList )
target_link_libraries( Test-DLList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-DLList
  PUBLIC
  .
)
target_sources( Test-DLList
  PRIVATE
  Test-DLList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-DLList COMMAND Test-DLList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)