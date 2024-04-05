add_executable( autoRefineMesh )
target_link_libraries( autoRefineMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  lagrangian
  meshTools
  triSurface
)
target_include_directories( autoRefineMesh
  PUBLIC
  .
)
target_sources( autoRefineMesh
  PRIVATE
  autoRefineMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS autoRefineMesh )
