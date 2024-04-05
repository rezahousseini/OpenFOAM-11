add_executable( foamToEnsight )
target_link_libraries( foamToEnsight
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatchFields
  lagrangian
  sampling
)
target_include_directories( foamToEnsight
  PUBLIC
  .
)
target_sources( foamToEnsight
  PRIVATE
  ensightMesh.C
  ensightParticlePositions.C
  foamToEnsight.C
  itoa.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  cellSets.H
  checkData.H
  checkMeshMoving.H
  ensightAsciiStream.H
  ensightBinaryStream.H
  ensightCaseTail.H
  ensightCloudField.H
  ensightField.H
  ensightMesh.H
  ensightParticlePositions.H
  ensightStream.H
  faceSets.H
  itoa.H
)
install( TARGETS foamToEnsight )
