add_executable( Test-pointField )
target_link_libraries( Test-pointField
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-pointField
  PUBLIC
  .
)
target_sources( Test-pointField
  PRIVATE
  Test-PointField.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-pointField COMMAND Test-pointField
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)