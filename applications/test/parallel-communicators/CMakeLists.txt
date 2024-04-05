add_executable( Test-parallel-communicators )
target_link_libraries( Test-parallel-communicators
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-parallel-communicators
  PUBLIC
  .
)
target_sources( Test-parallel-communicators
  PRIVATE
  Test-parallel-communicators.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-parallel-communicators COMMAND Test-parallel-communicators
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)