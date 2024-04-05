add_executable( Test-labelRanges )
target_link_libraries( Test-labelRanges
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-labelRanges
  PUBLIC
  .
)
target_sources( Test-labelRanges
  PRIVATE
  Test-labelRanges.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-labelRanges COMMAND Test-labelRanges
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)