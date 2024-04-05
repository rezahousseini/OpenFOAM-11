add_executable( decomposePar )
target_link_libraries( decomposePar
  PRIVATE
  OpenFOAM
  decompositionMethods
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
  parallel
)
target_include_directories( decomposePar
  PUBLIC
  .
)
target_sources( decomposePar
  PRIVATE
  decomposePar.C
  dimFieldDecomposer.C
  fvFieldDecomposer.C
  lagrangianFieldDecomposer.C
  pointFieldDecomposer.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  dimFieldDecomposer.H
  fvFieldDecomposer.H
  lagrangianFieldDecomposer.H
  pointFieldDecomposer.H
  readFields.H
)
install( TARGETS decomposePar )
