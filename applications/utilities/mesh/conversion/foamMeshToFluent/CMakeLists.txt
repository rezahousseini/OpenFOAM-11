add_executable( foamMeshToFluent )
target_link_libraries( foamMeshToFluent
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( foamMeshToFluent
  PUBLIC
  .
)
target_sources( foamMeshToFluent
  PRIVATE
  fluentFvMesh.C
  foamMeshToFluent.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  fluentFvMesh.H
)
install( TARGETS foamMeshToFluent )
