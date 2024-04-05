add_executable( Test-patchToPatch )
target_link_libraries( Test-patchToPatch
  PRIVATE
  OpenFOAM
  fileFormats
  meshTools
)
target_include_directories( Test-patchToPatch
  PUBLIC
  .
)
target_sources( Test-patchToPatch
  PRIVATE
  Test-patchToPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-patchToPatch COMMAND Test-patchToPatch
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)