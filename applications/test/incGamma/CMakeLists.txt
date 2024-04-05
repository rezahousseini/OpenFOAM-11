add_executable( Test-incGamma )
target_link_libraries( Test-incGamma
  PRIVATE
  OpenFOAM
  sampling
)
target_include_directories( Test-incGamma
  PUBLIC
  .
)
target_sources( Test-incGamma
  PRIVATE
  Test-incGamma.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-incGamma COMMAND Test-incGamma
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)