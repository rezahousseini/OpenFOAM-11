add_executable( mergeMeshes )
target_link_libraries( mergeMeshes
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( mergeMeshes
  PUBLIC
  .
)
target_sources( mergeMeshes
  PRIVATE
  mergeMeshes.C
  mergePolyMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createTimes.H
  mergePolyMesh.H
)
install( TARGETS mergeMeshes )
