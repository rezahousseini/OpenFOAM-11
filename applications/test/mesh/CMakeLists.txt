add_executable( Test-mesh )
target_link_libraries( Test-mesh
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( Test-mesh
  PUBLIC
  .
)
target_sources( Test-mesh
  PRIVATE
  Test-mesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-mesh COMMAND Test-mesh
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)