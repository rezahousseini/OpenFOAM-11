add_executable( Test-findTimes )
target_link_libraries( Test-findTimes
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-findTimes
  PUBLIC
  .
)
target_sources( Test-findTimes
  PRIVATE
  Test-findTimes.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-findTimes COMMAND Test-findTimes
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)