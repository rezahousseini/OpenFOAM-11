add_executable( Test-DynamicList )
target_link_libraries( Test-DynamicList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-DynamicList
  PUBLIC
  .
)
target_sources( Test-DynamicList
  PRIVATE
  Test-DynamicList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-DynamicList COMMAND Test-DynamicList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)