add_executable( Test-PackedList1 )
target_link_libraries( Test-PackedList1
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-PackedList1
  PUBLIC
  .
)
target_sources( Test-PackedList1
  PRIVATE
  Test-PackedList1.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PackedList1 COMMAND Test-PackedList1
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)