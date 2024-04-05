add_executable( checkMesh )
target_link_libraries( checkMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
  sampling
  surfMesh
)
target_include_directories( checkMesh
  PUBLIC
  .
)
target_sources( checkMesh
  PRIVATE
  checkGeometry.C
  checkMesh.C
  checkMeshQuality.C
  checkTools.C
  checkTopology.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  checkGeometry.H
  checkMeshQuality.H
  checkTools.H
  checkTopology.H
)
install( TARGETS checkMesh )
