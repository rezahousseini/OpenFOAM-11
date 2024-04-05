add_library( fvMeshStitchers )
target_link_libraries( fvMeshStitchers
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
)
target_include_directories( fvMeshStitchers
  PUBLIC
  .
)
target_sources( fvMeshStitchers
  PRIVATE
  moving/fvMeshStitchersMoving.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  moving/fvMeshStitchersMoving.H
  moving/meshPhiCorrectInfo.H
  moving/meshPhiCorrectInfoI.H
  moving/meshPhiPreCorrectInfo.H
  moving/meshPhiPreCorrectInfoI.H
)
install( TARGETS fvMeshStitchers )
