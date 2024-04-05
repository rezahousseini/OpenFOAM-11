add_library( decompositionMethods )
target_link_libraries( decompositionMethods
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
)
target_include_directories( decompositionMethods
  PUBLIC
  .
)
target_sources( decompositionMethods
  PRIVATE
  decompositionConstraints/decompositionConstraint/decompositionConstraint.C
  decompositionConstraints/preserveBaffles/preserveBafflesConstraint.C
  decompositionConstraints/preserveFaceZones/preserveFaceZonesConstraint.C
  decompositionConstraints/preservePatches/preservePatchesConstraint.C
  decompositionConstraints/refinementHistory/refinementHistoryConstraint.C
  decompositionConstraints/singleProcessorFaceSets/singleProcessorFaceSetsConstraint.C
  decompositionMethod/decompositionMethod.C
  geomDecomp/geomDecomp.C
  hierarchGeomDecomp/hierarchGeomDecomp.C
  manualDecomp/manualDecomp.C
  multiLevelDecomp/multiLevelDecomp.C
  noDecomp/noDecomp.C
  randomDecomp/randomDecomp.C
  simpleGeomDecomp/simpleGeomDecomp.C
  structuredDecomp/structuredDecomp.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  decompositionConstraints/decompositionConstraint/decompositionConstraint.H
  decompositionConstraints/preserveBaffles/preserveBafflesConstraint.H
  decompositionConstraints/preserveFaceZones/preserveFaceZonesConstraint.H
  decompositionConstraints/preservePatches/preservePatchesConstraint.H
  decompositionConstraints/refinementHistory/refinementHistoryConstraint.H
  decompositionConstraints/singleProcessorFaceSets/singleProcessorFaceSetsConstraint.H
  decompositionMethod/decompositionMethod.H
  geomDecomp/geomDecomp.H
  hierarchGeomDecomp/hierarchGeomDecomp.H
  manualDecomp/manualDecomp.H
  multiLevelDecomp/multiLevelDecomp.H
  noDecomp/noDecomp.H
  randomDecomp/randomDecomp.H
  simpleGeomDecomp/simpleGeomDecomp.H
  structuredDecomp/structuredDecomp.H
)
install( TARGETS decompositionMethods )
