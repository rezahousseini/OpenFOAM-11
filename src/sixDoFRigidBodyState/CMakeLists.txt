add_library( sixDoFRigidBodyState )
target_link_libraries( sixDoFRigidBodyState
  PRIVATE
  OpenFOAM
  dynamicMesh
  #finiteVolume
  fvMeshMovers
  sixDoFRigidBodyMotion
)
target_include_directories( sixDoFRigidBodyState
  PUBLIC
  .
)
target_sources( sixDoFRigidBodyState
  PRIVATE
  sixDoFRigidBodyControl/sixDoFRigidBodyControl.C
  sixDoFRigidBodyState/sixDoFRigidBodyState.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  sixDoFRigidBodyControl/sixDoFRigidBodyControl.H
  sixDoFRigidBodyState/sixDoFRigidBodyState.H
)
install( TARGETS sixDoFRigidBodyState )
