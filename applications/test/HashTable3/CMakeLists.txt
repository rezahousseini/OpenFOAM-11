add_executable( Test-HashTable3 )
target_link_libraries( Test-HashTable3
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-HashTable3
  PUBLIC
  .
)
target_sources( Test-HashTable3
  PRIVATE
  Test-HashTable3.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-HashTable3 COMMAND Test-HashTable3
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)