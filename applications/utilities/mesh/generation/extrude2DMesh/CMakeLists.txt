add_subdirectory( extrude2DMesh )
add_executable( extrude2DMesh_exe )
target_link_libraries( extrude2DMesh_exe
  PRIVATE
  OpenFOAM
  dynamicMesh
  extrude2DMesh
  genericPatches
  surfMesh
)
target_include_directories( extrude2DMesh_exe
  PUBLIC
  .
)
target_sources( extrude2DMesh_exe
  PRIVATE
  extrude2DMesh.C
)
install( TARGETS extrude2DMesh_exe )
