add_executable( Test-IndirectList )
target_link_libraries( Test-IndirectList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-IndirectList
  PUBLIC
  .
)
target_sources( Test-IndirectList
  PRIVATE
  Test-IndirectList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-IndirectList COMMAND Test-IndirectList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)