add_executable( foamToEnsightParts )
target_link_libraries( foamToEnsightParts
  PRIVATE
  OpenFOAM
  conversion
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
)
target_include_directories( foamToEnsightParts
  PUBLIC
  .
)
target_sources( foamToEnsightParts
  PRIVATE
  foamToEnsightParts.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  checkHasMovingMesh.H
  ensightOutputCase.H
  ensightOutputFunctions.H
  findFields.H
  getTimeIndex.H
  moveMesh.H
)
install( TARGETS foamToEnsightParts )
