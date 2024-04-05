add_executable( Test-memInfo )
target_link_libraries( Test-memInfo
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-memInfo
  PUBLIC
  .
)
target_sources( Test-memInfo
  PRIVATE
  Test-memInfo.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-memInfo COMMAND Test-memInfo
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)