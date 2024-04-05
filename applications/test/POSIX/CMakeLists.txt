add_executable( Test-POSIX )
target_link_libraries( Test-POSIX
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-POSIX
  PUBLIC
  .
)
target_sources( Test-POSIX
  PRIVATE
  Test-POSIX.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-POSIX COMMAND Test-POSIX
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)