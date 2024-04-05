add_executable( Test-liquid )
target_link_libraries( Test-liquid
  PRIVATE
  OpenFOAM
  thermophysicalProperties
)
target_include_directories( Test-liquid
  PUBLIC
  .
)
target_sources( Test-liquid
  PRIVATE
  Test-liquid.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-liquid COMMAND Test-liquid
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)