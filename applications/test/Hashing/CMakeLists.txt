add_executable( Test-Hashing )
target_link_libraries( Test-Hashing
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Hashing
  PUBLIC
  .
)
target_sources( Test-Hashing
  PRIVATE
  Test-Hashing.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Hashing COMMAND Test-Hashing
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)