add_executable( Test-UIndirectList )
target_link_libraries( Test-UIndirectList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-UIndirectList
  PUBLIC
  .
)
target_sources( Test-UIndirectList
  PRIVATE
  Test-UIndirectList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-UIndirectList COMMAND Test-UIndirectList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)