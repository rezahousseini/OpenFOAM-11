add_library( sixDoFRigidBodyMotion )
target_link_libraries( sixDoFRigidBodyMotion
  PRIVATE
  OpenFOAM
  dynamicMesh
  #finiteVolume
  forces
  #meshTools
  rigidBodyDynamics
)
target_include_directories( sixDoFRigidBodyMotion
  PUBLIC
  .
)
target_sources( sixDoFRigidBodyMotion
  PRIVATE
  sixDoFRigidBodyMotion/constraints/axis/sixDoFRigidBodyMotionAxisConstraint.C
  sixDoFRigidBodyMotion/constraints/line/sixDoFRigidBodyMotionLineConstraint.C
  sixDoFRigidBodyMotion/constraints/orientation/sixDoFRigidBodyMotionOrientationConstraint.C
  sixDoFRigidBodyMotion/constraints/plane/sixDoFRigidBodyMotionPlaneConstraint.C
  sixDoFRigidBodyMotion/constraints/point/sixDoFRigidBodyMotionPointConstraint.C
  sixDoFRigidBodyMotion/constraints/sixDoFRigidBodyMotionConstraint/sixDoFRigidBodyMotionConstraint.C
  sixDoFRigidBodyMotion/constraints/sixDoFRigidBodyMotionConstraint/sixDoFRigidBodyMotionConstraintNew.C
  sixDoFRigidBodyMotion/restraints/axialAngularSpring/axialAngularSpring.C
  sixDoFRigidBodyMotion/restraints/linearAxialAngularSpring/linearAxialAngularSpring.C
  sixDoFRigidBodyMotion/restraints/linearDamper/linearDamper.C
  sixDoFRigidBodyMotion/restraints/linearSpring/linearSpring.C
  sixDoFRigidBodyMotion/restraints/sixDoFRigidBodyMotionRestraint/sixDoFRigidBodyMotionRestraint.C
  sixDoFRigidBodyMotion/restraints/sixDoFRigidBodyMotionRestraint/sixDoFRigidBodyMotionRestraintNew.C
  sixDoFRigidBodyMotion/restraints/sphericalAngularDamper/sphericalAngularDamper.C
  sixDoFRigidBodyMotion/restraints/sphericalAngularSpring/sphericalAngularSpring.C
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotion.C
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotionIO.C
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotionState.C
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotionStateIO.C
  sixDoFRigidBodyMotionSolver/sixDoFRigidBodyMotionSolver.C
  sixDoFSolvers/CrankNicolson/CrankNicolson.C
  sixDoFSolvers/Newmark/Newmark.C
  sixDoFSolvers/sixDoFSolver/sixDoFSolver.C
  sixDoFSolvers/sixDoFSolver/sixDoFSolverNew.C
  sixDoFSolvers/symplectic/symplectic.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  sixDoFRigidBodyMotion/constraints/axis/sixDoFRigidBodyMotionAxisConstraint.H
  sixDoFRigidBodyMotion/constraints/line/sixDoFRigidBodyMotionLineConstraint.H
  sixDoFRigidBodyMotion/constraints/orientation/sixDoFRigidBodyMotionOrientationConstraint.H
  sixDoFRigidBodyMotion/constraints/plane/sixDoFRigidBodyMotionPlaneConstraint.H
  sixDoFRigidBodyMotion/constraints/point/sixDoFRigidBodyMotionPointConstraint.H
  sixDoFRigidBodyMotion/constraints/sixDoFRigidBodyMotionConstraint/sixDoFRigidBodyMotionConstraint.H
  sixDoFRigidBodyMotion/restraints/axialAngularSpring/axialAngularSpring.H
  sixDoFRigidBodyMotion/restraints/linearAxialAngularSpring/linearAxialAngularSpring.H
  sixDoFRigidBodyMotion/restraints/linearDamper/linearDamper.H
  sixDoFRigidBodyMotion/restraints/linearSpring/linearSpring.H
  sixDoFRigidBodyMotion/restraints/sixDoFRigidBodyMotionRestraint/sixDoFRigidBodyMotionRestraint.H
  sixDoFRigidBodyMotion/restraints/sphericalAngularDamper/sphericalAngularDamper.H
  sixDoFRigidBodyMotion/restraints/sphericalAngularSpring/sphericalAngularSpring.H
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotion.H
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotionI.H
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotionState.H
  sixDoFRigidBodyMotion/sixDoFRigidBodyMotionStateI.H
  sixDoFRigidBodyMotionSolver/sixDoFRigidBodyMotionSolver.H
  sixDoFSolvers/CrankNicolson/CrankNicolson.H
  sixDoFSolvers/Newmark/Newmark.H
  sixDoFSolvers/sixDoFSolver/sixDoFSolver.H
  sixDoFSolvers/sixDoFSolver/sixDoFSolverI.H
  sixDoFSolvers/symplectic/symplectic.H
)
install( TARGETS sixDoFRigidBodyMotion )
