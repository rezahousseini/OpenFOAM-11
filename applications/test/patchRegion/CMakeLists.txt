add_executable( Test-patchRegion )
target_link_libraries( Test-patchRegion
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-patchRegion
  PUBLIC
  .
)
target_sources( Test-patchRegion
  PRIVATE
  Test-patchRegion.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-patchRegion COMMAND Test-patchRegion
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)