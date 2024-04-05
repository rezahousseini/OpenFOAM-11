add_executable( Test-sizeof )
target_link_libraries( Test-sizeof
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-sizeof
  PUBLIC
  .
)
target_sources( Test-sizeof
  PRIVATE
  Test-sizeof.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-sizeof COMMAND Test-sizeof
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)