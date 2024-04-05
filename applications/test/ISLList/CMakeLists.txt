add_executable( Test-ISLList )
target_link_libraries( Test-ISLList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-ISLList
  PUBLIC
  .
)
target_sources( Test-ISLList
  PRIVATE
  Test-ISLList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-ISLList COMMAND Test-ISLList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)