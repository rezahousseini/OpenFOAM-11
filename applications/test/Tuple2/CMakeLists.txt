add_executable( Test-Tuple2 )
target_link_libraries( Test-Tuple2
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-Tuple2
  PUBLIC
  .
)
target_sources( Test-Tuple2
  PRIVATE
  Test-Tuple2.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-Tuple2 COMMAND Test-Tuple2
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)