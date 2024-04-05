add_executable( Test-alloc )
target_link_libraries( Test-alloc
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-alloc
  PUBLIC
  .
)
target_sources( Test-alloc
  PRIVATE
  Test-alloc.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-alloc COMMAND Test-alloc
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)