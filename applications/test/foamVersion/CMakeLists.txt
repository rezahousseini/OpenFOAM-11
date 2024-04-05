add_executable( Test-foamVersionString )
target_link_libraries( Test-foamVersionString
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-foamVersionString
  PUBLIC
  .
)
target_sources( Test-foamVersionString
  PRIVATE
  Test-foamVersionString.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-foamVersionString COMMAND Test-foamVersionString
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)