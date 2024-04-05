add_executable( Test-NamedEnum )
target_link_libraries( Test-NamedEnum
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-NamedEnum
  PUBLIC
  .
)
target_sources( Test-NamedEnum
  PRIVATE
  Test-namedEnum.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-NamedEnum COMMAND Test-NamedEnum
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)