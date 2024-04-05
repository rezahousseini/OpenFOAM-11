add_executable( Test-wordRe )
target_link_libraries( Test-wordRe
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-wordRe
  PUBLIC
  .
)
target_sources( Test-wordRe
  PRIVATE
  Test-wordRe.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-wordRe COMMAND Test-wordRe
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)