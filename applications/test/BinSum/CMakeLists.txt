add_executable( Test-BinSum )
target_link_libraries( Test-BinSum
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-BinSum
  PUBLIC
  .
)
target_sources( Test-BinSum
  PRIVATE
  Test-BinSum.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-BinSum COMMAND Test-BinSum
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)