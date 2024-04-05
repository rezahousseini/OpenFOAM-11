add_library( fvMeshTopoChangers )
target_link_libraries( fvMeshTopoChangers
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
)
target_include_directories( fvMeshTopoChangers
  PUBLIC
  .
)
target_sources( fvMeshTopoChangers
  PRIVATE
  movingCone/fvMeshTopoChangersMovingCone.C
  refiner/fvMeshTopoChangersRefiner.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  meshToMesh/MeshToMeshMapGeometricFields.H
  meshToMesh/fvMeshTopoChangersMeshToMesh.H
  meshToMesh/meshToMeshAdjustTimeStep/meshToMeshAdjustTimeStepFunctionObject.H
  movingCone/fvMeshTopoChangersMovingCone.H
  raw/fvMeshTopoChangersRaw.H
  refiner/fvMeshTopoChangersRefiner.H
)
install( TARGETS fvMeshTopoChangers )
