add_executable( Test-fileNameClean )
target_link_libraries( Test-fileNameClean
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-fileNameClean
  PUBLIC
  .
)
target_sources( Test-fileNameClean
  PRIVATE
  Test-fileNameClean.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-fileNameClean COMMAND Test-fileNameClean
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)