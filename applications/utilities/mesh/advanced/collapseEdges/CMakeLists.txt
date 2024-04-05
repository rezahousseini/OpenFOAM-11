add_executable( collapseEdges )
target_link_libraries( collapseEdges
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatches
  meshTools
)
target_include_directories( collapseEdges
  PUBLIC
  .
)
target_sources( collapseEdges
  PRIVATE
  collapseEdges.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS collapseEdges )
