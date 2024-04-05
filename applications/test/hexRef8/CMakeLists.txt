add_executable( Test-hexRef8 )
target_link_libraries( Test-hexRef8
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
)
target_include_directories( Test-hexRef8
  PUBLIC
  .
)
target_sources( Test-hexRef8
  PRIVATE
  Test-hexRef8.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-hexRef8 COMMAND Test-hexRef8
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)