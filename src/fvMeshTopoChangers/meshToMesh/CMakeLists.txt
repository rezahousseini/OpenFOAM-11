add_library( meshToMeshTopoChanger )
target_link_libraries( meshToMeshTopoChanger
  PRIVATE

)
target_include_directories( meshToMeshTopoChanger
  PUBLIC
  .
)
target_sources( meshToMeshTopoChanger
  PRIVATE
  fvMeshTopoChangersMeshToMesh.C
  meshToMeshAdjustTimeStep/meshToMeshAdjustTimeStepFunctionObject.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  MeshToMeshMapGeometricFields.H
  fvMeshTopoChangersMeshToMesh.H
  meshToMeshAdjustTimeStep/meshToMeshAdjustTimeStepFunctionObject.H
)
install( TARGETS meshToMeshTopoChanger )