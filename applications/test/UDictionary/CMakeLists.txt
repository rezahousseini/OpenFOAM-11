add_executable( Test-UDictionary )
target_link_libraries( Test-UDictionary
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-UDictionary
  PUBLIC
  .
)
target_sources( Test-UDictionary
  PRIVATE
  Test-UDictionary.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-UDictionary COMMAND Test-UDictionary
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)