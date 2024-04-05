add_executable( Test-globalMeshData )
target_link_libraries( Test-globalMeshData
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-globalMeshData
  PUBLIC
  .
)
target_sources( Test-globalMeshData
  PRIVATE
  Test-globalMeshData.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-globalMeshData COMMAND Test-globalMeshData
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)