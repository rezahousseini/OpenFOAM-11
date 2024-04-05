add_executable( Test-stringList )
target_link_libraries( Test-stringList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-stringList
  PUBLIC
  .
)
target_sources( Test-stringList
  PRIVATE
  Test-stringList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-stringList COMMAND Test-stringList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)