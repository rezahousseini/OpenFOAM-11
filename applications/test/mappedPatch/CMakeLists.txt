add_executable( Test-mappedPatch )
target_link_libraries( Test-mappedPatch
  PRIVATE
  OpenFOAM
  fileFormats
  finiteVolume
  meshTools
)
target_include_directories( Test-mappedPatch
  PUBLIC
  .
)
target_sources( Test-mappedPatch
  PRIVATE
  Test-mappedPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-mappedPatch COMMAND Test-mappedPatch
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)