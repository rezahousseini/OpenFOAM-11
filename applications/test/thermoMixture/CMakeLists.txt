add_executable( Test-thermoMixture )
target_link_libraries( Test-thermoMixture
  PRIVATE
  OpenFOAM
  specie
)
target_include_directories( Test-thermoMixture
  PUBLIC
  .
)
target_sources( Test-thermoMixture
  PRIVATE
  Test-thermoMixture.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-thermoMixture COMMAND Test-thermoMixture
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)