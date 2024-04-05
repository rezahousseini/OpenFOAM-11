add_executable( Test-PackedList )
target_link_libraries( Test-PackedList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-PackedList
  PUBLIC
  .
)
target_sources( Test-PackedList
  PRIVATE
  Test-PackedList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PackedList COMMAND Test-PackedList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)