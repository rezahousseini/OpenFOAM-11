add_executable( Test-codeStream )
target_link_libraries( Test-codeStream
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-codeStream
  PUBLIC
  .
)
target_sources( Test-codeStream
  PRIVATE
  Test-codeStream.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-codeStream COMMAND Test-codeStream
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)