add_executable( Test-decomposedBlockData )
target_link_libraries( Test-decomposedBlockData
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-decomposedBlockData
  PUBLIC
  .
)
target_sources( Test-decomposedBlockData
  PRIVATE
  Test-decomposedBlockData.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-decomposedBlockData COMMAND Test-decomposedBlockData
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)