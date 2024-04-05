add_executable( Test-ListHashTable )
target_link_libraries( Test-ListHashTable
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-ListHashTable
  PUBLIC
  .
)
target_sources( Test-ListHashTable
  PRIVATE
  Test-ListHashTable.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-ListHashTable COMMAND Test-ListHashTable
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)