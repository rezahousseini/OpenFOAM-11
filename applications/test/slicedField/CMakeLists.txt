add_executable( Test-slicedField )
target_link_libraries( Test-slicedField
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-slicedField
  PUBLIC
  .
)
target_sources( Test-slicedField
  PRIVATE
  Test-slicedField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-slicedField COMMAND Test-slicedField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)