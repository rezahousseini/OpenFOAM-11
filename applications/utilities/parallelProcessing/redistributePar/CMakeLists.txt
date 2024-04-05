add_executable( redistributePar )
target_link_libraries( redistributePar
  PRIVATE
  OpenFOAM
  decompositionMethods
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
  ptscotchDecomp
  scotchDecomp
  ${PTSCOTCH_LIBRARY}
  ${PTSCOTCHERREXIT_LIBRARY}
)
target_include_directories( redistributePar
  PUBLIC
  .
)
target_sources( redistributePar
  PRIVATE
  loadOrCreateMesh.C
  redistributePar.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  loadOrCreateMesh.H
)
install( TARGETS redistributePar )
