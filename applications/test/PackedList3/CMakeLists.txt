add_executable( Test-PackedList3 )
target_link_libraries( Test-PackedList3
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-PackedList3
  PUBLIC
  .
)
target_sources( Test-PackedList3
  PRIVATE
  Test-PackedList3.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PackedList3 COMMAND Test-PackedList3
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)