add_executable( Test-fileName )
target_link_libraries( Test-fileName
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-fileName
  PUBLIC
  .
)
target_sources( Test-fileName
  PRIVATE
  Test-fileName.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-fileName COMMAND Test-fileName
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)