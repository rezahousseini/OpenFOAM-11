add_executable( Test-symmTensorField )
target_link_libraries( Test-symmTensorField
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-symmTensorField
  PUBLIC
  .
)
target_sources( Test-symmTensorField
  PRIVATE
  Test-symmTensorField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-symmTensorField COMMAND Test-symmTensorField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)