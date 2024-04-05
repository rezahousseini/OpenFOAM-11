add_executable( foamToGMV )
target_link_libraries( foamToGMV
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
)
target_include_directories( foamToGMV
  PUBLIC
  .
)
target_sources( foamToGMV
  PRIVATE
  foamToGMV.C
  itoa.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  gmvOutput.H
  gmvOutputHeader.H
  gmvOutputLagrangian.H
  gmvOutputSpray.H
  gmvOutputTail.H
  itoa.H
  moveMesh.H
  readConversionProperties.H
)
install( TARGETS foamToGMV )
