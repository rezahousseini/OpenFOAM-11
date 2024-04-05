add_library( snappyHexMesh )
target_link_libraries( snappyHexMesh
  PRIVATE
  OpenFOAM
  decompositionMethods
  dynamicMesh
  fileFormats
  #finiteVolume
  lagrangian
  #meshTools
  #triSurface
)
target_include_directories( snappyHexMesh
  PUBLIC
  .
)
target_sources( snappyHexMesh
  PRIVATE
  externalDisplacementMeshMover/displacementMeshMoverMotionSolver.C
  externalDisplacementMeshMover/externalDisplacementMeshMover.C
  externalDisplacementMeshMover/medialAxisMeshMover.C
  externalDisplacementMeshMover/zeroFixedValue/zeroFixedValuePointPatchFields.C
  meshRefinement/meshRefinement.C
  meshRefinement/meshRefinementBaffles.C
  meshRefinement/meshRefinementMerge.C
  meshRefinement/meshRefinementProblemCells.C
  meshRefinement/meshRefinementRefine.C
  meshRefinement/patchFaceOrientation.C
  refinementFeatures/refinementFeatures.C
  refinementRegions/refinementRegions.C
  refinementSurfaces/refinementSurfaces.C
  refinementSurfaces/surfaceZonesInfo.C
  snappyHexMeshDriver/layerParameters/layerParameters.C
  snappyHexMeshDriver/pointData/pointData.C
  snappyHexMeshDriver/refinementParameters/refinementParameters.C
  snappyHexMeshDriver/snapParameters/snapParameters.C
  snappyHexMeshDriver/snappyLayerDriver.C
  snappyHexMeshDriver/snappyRefineDriver.C
  snappyHexMeshDriver/snappySnapDriver.C
  snappyHexMeshDriver/snappySnapDriverFeature.C
  trackedParticle/trackedParticle.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  externalDisplacementMeshMover/displacementMeshMoverMotionSolver.H
  externalDisplacementMeshMover/externalDisplacementMeshMover.H
  externalDisplacementMeshMover/medialAxisMeshMover.H
  externalDisplacementMeshMover/zeroFixedValue/zeroFixedValuePointPatchField.H
  externalDisplacementMeshMover/zeroFixedValue/zeroFixedValuePointPatchFields.H
  meshRefinement/meshRefinement.H
  meshRefinement/patchFaceOrientation.H
  meshRefinement/patchFaceOrientationI.H
  refinementFeatures/refinementFeatures.H
  refinementRegions/refinementRegions.H
  refinementSurfaces/refinementSurfaces.H
  refinementSurfaces/surfaceZonesInfo.H
  snappyHexMeshDriver/layerParameters/layerParameters.H
  snappyHexMeshDriver/pointData/pointData.H
  snappyHexMeshDriver/pointData/pointDataI.H
  snappyHexMeshDriver/refinementParameters/refinementParameters.H
  snappyHexMeshDriver/snapParameters/snapParameters.H
  snappyHexMeshDriver/snappyLayerDriver.H
  snappyHexMeshDriver/snappyRefineDriver.H
  snappyHexMeshDriver/snappySnapDriver.H
  trackedParticle/trackedParticle.H
)
install( TARGETS snappyHexMesh )
