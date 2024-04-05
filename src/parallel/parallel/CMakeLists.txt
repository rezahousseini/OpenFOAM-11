add_library( parallel )
target_link_libraries( parallel
  PRIVATE
  OpenFOAM
  decompositionMethods
  dynamicMesh
)
target_include_directories( parallel
  PUBLIC
  .
)
target_sources( parallel
  PRIVATE
  domainDecomposition.C
  domainDecompositionDecompose.C
  domainDecompositionReconstruct.C
  processorRunTimes.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  domainDecomposition.H
  processorRunTimes.H
)
install( TARGETS parallel )
