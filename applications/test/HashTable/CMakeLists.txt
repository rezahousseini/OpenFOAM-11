add_executable( Test-hashTable )
target_link_libraries( Test-hashTable
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-hashTable
  PUBLIC
  .
)
target_sources( Test-hashTable
  PRIVATE
  Test-hashTable.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-hashTable COMMAND Test-hashTable
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)