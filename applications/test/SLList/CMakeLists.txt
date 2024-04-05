add_executable( Test-SLList )
target_link_libraries( Test-SLList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-SLList
  PUBLIC
  .
)
target_sources( Test-SLList
  PRIVATE
  Test-SLList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-SLList COMMAND Test-SLList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)