add_executable( Test-PatchEdgeFaceWave )
target_link_libraries( Test-PatchEdgeFaceWave
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-PatchEdgeFaceWave
  PUBLIC
  .
)
target_sources( Test-PatchEdgeFaceWave
  PRIVATE
  Test-PatchEdgeFaceWave.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PatchEdgeFaceWave COMMAND Test-PatchEdgeFaceWave
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)