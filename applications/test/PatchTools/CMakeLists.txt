add_executable( Test-PatchTools )
target_link_libraries( Test-PatchTools
  PRIVATE
  OpenFOAM
  fileFormats
  finiteVolume
)
target_include_directories( Test-PatchTools
  PUBLIC
  .
)
target_sources( Test-PatchTools
  PRIVATE
  Test-PatchTools.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PatchTools COMMAND Test-PatchTools
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)