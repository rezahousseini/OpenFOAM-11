add_executable( reconstructPar )
target_link_libraries( reconstructPar
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
  parallel
)
target_include_directories( reconstructPar
  PUBLIC
  .
)
target_sources( reconstructPar
  PRIVATE
  fvFieldReconstructor.C
  pointFieldReconstructor.C
  reconstructLagrangianPositions.C
  reconstructPar.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  fvFieldReconstructor.H
  pointFieldReconstructor.H
  reconstructLagrangian.H
)
install( TARGETS reconstructPar )
