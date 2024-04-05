add_executable( combinePatchFaces )
target_link_libraries( combinePatchFaces
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatches
)
target_include_directories( combinePatchFaces
  PUBLIC
  .
)
target_sources( combinePatchFaces
  PRIVATE
  combinePatchFaces.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS combinePatchFaces )
