add_executable( Test-ListOps )
target_link_libraries( Test-ListOps
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-ListOps
  PUBLIC
  .
)
target_sources( Test-ListOps
  PRIVATE
  Test-ListOps.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-ListOps COMMAND Test-ListOps
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)