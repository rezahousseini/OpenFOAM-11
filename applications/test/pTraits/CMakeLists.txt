add_executable( Test-pTraits )
target_link_libraries( Test-pTraits
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-pTraits
  PUBLIC
  .
)
target_sources( Test-pTraits
  PRIVATE
  Test-pTraits.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-pTraits COMMAND Test-pTraits
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)