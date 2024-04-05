add_executable( Test-hashSet )
target_link_libraries( Test-hashSet
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-hashSet
  PUBLIC
  .
)
target_sources( Test-hashSet
  PRIVATE
  Test-hashSet.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-hashSet COMMAND Test-hashSet
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)