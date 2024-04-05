add_executable( Test-OStringStream )
target_link_libraries( Test-OStringStream
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-OStringStream
  PUBLIC
  .
)
target_sources( Test-OStringStream
  PRIVATE
  Test-OStringStream.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-OStringStream COMMAND Test-OStringStream
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)