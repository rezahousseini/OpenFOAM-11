add_executable( splitBaffles )
target_link_libraries( splitBaffles
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatches
  meshTools
)
target_include_directories( splitBaffles
  PUBLIC
  .
)
target_sources( splitBaffles
  PRIVATE
  splitBaffles.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS splitBaffles )
