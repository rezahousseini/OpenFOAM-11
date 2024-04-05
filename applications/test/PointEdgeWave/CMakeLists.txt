add_executable( Test-PointEdgeWave )
target_link_libraries( Test-PointEdgeWave
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( Test-PointEdgeWave
  PUBLIC
  .
)
target_sources( Test-PointEdgeWave
  PRIVATE
  Test-PointEdgeWave.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PointEdgeWave COMMAND Test-PointEdgeWave
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)