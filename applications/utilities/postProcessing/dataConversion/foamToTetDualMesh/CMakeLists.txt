add_executable( foamToTetDualMesh )
target_link_libraries( foamToTetDualMesh
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( foamToTetDualMesh
  PUBLIC
  .
)
target_sources( foamToTetDualMesh
  PRIVATE
  foamToTetDualMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS foamToTetDualMesh )
