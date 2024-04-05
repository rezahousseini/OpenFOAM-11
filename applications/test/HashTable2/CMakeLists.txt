add_executable( Test-HashTable2 )
target_link_libraries( Test-HashTable2
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-HashTable2
  PUBLIC
  .
)
target_sources( Test-HashTable2
  PRIVATE
  Test-HashTable2.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-HashTable2 COMMAND Test-HashTable2
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)