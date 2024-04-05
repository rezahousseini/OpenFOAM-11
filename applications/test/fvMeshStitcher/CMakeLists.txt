add_executable( Test-fvMeshStitcher )
target_link_libraries( Test-fvMeshStitcher
  PRIVATE
  OpenFOAM
  fileFormats
  finiteVolume
  meshTools
)
target_include_directories( Test-fvMeshStitcher
  PUBLIC
  .
)
target_sources( Test-fvMeshStitcher
  PRIVATE
  Test-fvMeshStitcher.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-fvMeshStitcher COMMAND Test-fvMeshStitcher
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)