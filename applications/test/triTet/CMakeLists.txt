add_executable( Test-triTet )
target_link_libraries( Test-triTet
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-triTet
  PUBLIC
  .
)
target_sources( Test-triTet
  PRIVATE
  Test-triTet.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-triTet COMMAND Test-triTet
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)