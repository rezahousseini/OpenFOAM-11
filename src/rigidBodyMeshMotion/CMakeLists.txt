add_library( rigidBodyMeshMotion )
target_link_libraries( rigidBodyMeshMotion
  PRIVATE
  OpenFOAM
  OSspecific
  dynamicMesh
  finiteVolume
  forces
  meshTools
  rigidBodyDynamics
)
target_include_directories( rigidBodyMeshMotion
  PUBLIC
  .
)
target_sources( rigidBodyMeshMotion
  PRIVATE
  rigidBodyMeshMotion/rigidBodyMeshMotion.C
  rigidBodyMeshMotionSolver/rigidBodyMeshMotionSolver.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  rigidBodyMeshMotion/rigidBodyMeshMotion.H
  rigidBodyMeshMotionSolver/rigidBodyMeshMotionSolver.H
)
install( TARGETS rigidBodyMeshMotion )
