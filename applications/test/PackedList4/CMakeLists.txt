add_executable( Test-PackedList4 )
target_link_libraries( Test-PackedList4
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-PackedList4
  PUBLIC
  .
)
target_sources( Test-PackedList4
  PRIVATE
  Test-PackedList4.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PackedList4 COMMAND Test-PackedList4
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)