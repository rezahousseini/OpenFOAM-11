add_library( fvMeshMovers )
target_link_libraries( fvMeshMovers
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
)
target_include_directories( fvMeshMovers
  PUBLIC
  .
)
target_sources( fvMeshMovers
  PRIVATE
  engine/engine/fvMeshMoversEngine.C
  engine/enginePiston/enginePiston.C
  engine/engineValve/engineValve.C
  engine/layered/fvMeshMoversLayeredEngine.C
  inkJet/fvMeshMoversInkJet.C
  interpolator/fvMeshMoversInterpolator.C
  motionSolver/fvMeshMoversMotionSolver.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  engine/engine/fvMeshMoversEngine.H
  engine/enginePiston/enginePiston.H
  engine/engineValve/engineValve.H
  engine/layered/fvMeshMoversLayeredEngine.H
  inkJet/fvMeshMoversInkJet.H
  interpolator/fvMeshMoversInterpolator.H
  motionSolver/fvMeshMoversMotionSolver.H
)
install( TARGETS fvMeshMovers )
