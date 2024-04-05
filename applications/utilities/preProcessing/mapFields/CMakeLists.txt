add_executable( mapFields )
target_link_libraries( mapFields
  PRIVATE
  OpenFOAM
  decompositionMethods
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
)
target_include_directories( mapFields
  PUBLIC
  .
)
target_sources( mapFields
  PRIVATE
  mapFields.C
  mapLagrangian.C
  mapMeshes.C
  meshToMesh0.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  MapConsistentVolFields.H
  MapLagrangianFields.H
  MapVolFields.H
  UnMapped.H
  createTimes.H
  mapLagrangian.H
  mapMeshes.H
  meshToMesh0.H
  setTimeIndex.H
)
install( TARGETS mapFields )
