add_executable( Test-tokenise )
target_link_libraries( Test-tokenise
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-tokenise
  PUBLIC
  .
)
target_sources( Test-tokenise
  PRIVATE
  Test-tokenise.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-tokenise COMMAND Test-tokenise
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)