add_executable( Test-dimensionedType )
target_link_libraries( Test-dimensionedType
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-dimensionedType
  PUBLIC
  .
)
target_sources( Test-dimensionedType
  PRIVATE
  Test-dimensionedType.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-dimensionedType COMMAND Test-dimensionedType
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)