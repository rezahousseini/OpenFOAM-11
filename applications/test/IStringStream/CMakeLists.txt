add_executable( Test-IStringStream )
target_link_libraries( Test-IStringStream
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-IStringStream
  PUBLIC
  .
)
target_sources( Test-IStringStream
  PRIVATE
  Test-IStringStream.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-IStringStream COMMAND Test-IStringStream
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)