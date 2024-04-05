add_executable( renumberMesh )
target_link_libraries( renumberMesh
  PRIVATE
  OpenFOAM
  decompositionMethods
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
  metisDecomp
  renumberMethods
  scotchDecomp
  ${PTSCOTCH_LIBRARY}
  ${PTSCOTCHERREXIT_LIBRARY}
  ${METIS_LIBRARY}
  ${GKLIB_LIBRARY}
)
target_include_directories( renumberMesh
  PUBLIC
  .
)
target_sources( renumberMesh
  PRIVATE
  renumberMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS renumberMesh )
