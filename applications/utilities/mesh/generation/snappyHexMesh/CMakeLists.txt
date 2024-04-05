add_executable( snappyHexMesh_exe )
target_link_libraries( snappyHexMesh_exe
  PRIVATE
  OpenFOAM
  decompositionMethods
  dynamicMesh
  fileFormats
  finiteVolume
  genericPatchFields
  meshTools
  ptscotchDecomp
  scotchDecomp
  snappyHexMesh
  surfMesh
  ${PTSCOTCH_LIBRARY}
  ${PTSCOTCHERREXIT_LIBRARY}
)
target_include_directories( snappyHexMesh_exe
  PUBLIC
  .
)
target_sources( snappyHexMesh_exe
  PRIVATE
  snappyHexMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS snappyHexMesh_exe )
