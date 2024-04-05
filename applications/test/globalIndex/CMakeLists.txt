add_executable( Test-globalIndex )
target_link_libraries( Test-globalIndex
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-globalIndex
  PUBLIC
  .
)
target_sources( Test-globalIndex
  PRIVATE
  Test-globalIndex.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-globalIndex COMMAND Test-globalIndex
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)