add_executable( Test-tensor )
target_link_libraries( Test-tensor
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-tensor
  PUBLIC
  .
)
target_sources( Test-tensor
  PRIVATE
  Test-tensor.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-tensor COMMAND Test-tensor
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)