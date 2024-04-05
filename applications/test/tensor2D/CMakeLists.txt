add_executable( Test-tensor2D )
target_link_libraries( Test-tensor2D
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-tensor2D
  PUBLIC
  .
)
target_sources( Test-tensor2D
  PRIVATE
  Test-tensor2D.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-tensor2D COMMAND Test-tensor2D
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)