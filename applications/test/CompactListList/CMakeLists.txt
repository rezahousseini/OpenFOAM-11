add_executable( Test-CompactListList )
target_link_libraries( Test-CompactListList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-CompactListList
  PUBLIC
  .
)
target_sources( Test-CompactListList
  PRIVATE
  Test-CompactListList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-CompactListList COMMAND Test-CompactListList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)