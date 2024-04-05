add_executable( Test-sphericalTensorField )
target_link_libraries( Test-sphericalTensorField
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( Test-sphericalTensorField
  PUBLIC
  .
)
target_sources( Test-sphericalTensorField
  PRIVATE
  Test-sphericalTensorField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-sphericalTensorField COMMAND Test-sphericalTensorField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)