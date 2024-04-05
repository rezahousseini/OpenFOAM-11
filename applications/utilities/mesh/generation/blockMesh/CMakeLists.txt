add_executable( blockMesh_exe )
target_link_libraries( blockMesh_exe
  PRIVATE
  OpenFOAM
  blockMesh
  dynamicMesh
  fileFormats
  genericPatches
  meshTools
)
target_include_directories( blockMesh_exe
  PUBLIC
  .
)
target_sources( blockMesh_exe
  PRIVATE
  blockMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  mergePatchPairs.H
)
install( TARGETS blockMesh_exe )
