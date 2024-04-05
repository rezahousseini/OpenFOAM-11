add_executable( Test-volPointInterpolation )
target_link_libraries( Test-volPointInterpolation
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-volPointInterpolation
  PUBLIC
  .
)
target_sources( Test-volPointInterpolation
  PRIVATE
  Test-volPointInterpolation.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-volPointInterpolation COMMAND Test-volPointInterpolation
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)