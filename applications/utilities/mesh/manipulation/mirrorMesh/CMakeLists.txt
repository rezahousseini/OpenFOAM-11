add_executable( mirrorMesh )
target_link_libraries( mirrorMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatches
)
target_include_directories( mirrorMesh
  PUBLIC
  .
)
target_sources( mirrorMesh
  PRIVATE
  mirrorFvMesh.C
  mirrorMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  mirrorFvMesh.H
  readMirrorDict.H
)
install( TARGETS mirrorMesh )
