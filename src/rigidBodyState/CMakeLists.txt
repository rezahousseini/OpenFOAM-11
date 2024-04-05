add_library( rigidBodyState )
target_link_libraries( rigidBodyState
  PRIVATE
  OpenFOAM
  OSspecific
  dynamicMesh
  finiteVolume
  fvMeshMovers
  rigidBodyDynamics
)
target_include_directories( rigidBodyState
  PUBLIC
  .
)
target_sources( rigidBodyState
  PRIVATE
  rigidBodyPoints/rigidBodyPoints.C
  rigidBodyState/rigidBodyState.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  rigidBodyPoints/rigidBodyPoints.H
  rigidBodyState/rigidBodyState.H
)
install( TARGETS rigidBodyState )
