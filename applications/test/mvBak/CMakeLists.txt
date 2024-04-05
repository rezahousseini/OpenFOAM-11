add_executable( Test-mvBak )
target_link_libraries( Test-mvBak
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-mvBak
  PUBLIC
  .
)
target_sources( Test-mvBak
  PRIVATE
  Test-mvBak.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-mvBak COMMAND Test-mvBak
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)