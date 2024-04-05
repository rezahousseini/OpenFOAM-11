add_executable( Test-CompactIOList )
target_link_libraries( Test-CompactIOList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-CompactIOList
  PUBLIC
  .
)
target_sources( Test-CompactIOList
  PRIVATE
  Test-CompactIOList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-CompactIOList COMMAND Test-CompactIOList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)