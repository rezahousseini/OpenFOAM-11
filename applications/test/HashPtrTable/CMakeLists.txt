add_executable( Test-hashPtrTable )
target_link_libraries( Test-hashPtrTable
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-hashPtrTable
  PUBLIC
  .
)
target_sources( Test-hashPtrTable
  PRIVATE
  Test-hashPtrTable.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-hashPtrTable COMMAND Test-hashPtrTable
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)