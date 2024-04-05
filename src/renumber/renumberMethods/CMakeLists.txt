add_library( renumberMethods )
target_link_libraries( renumberMethods
  PRIVATE
  OpenFOAM
  decompositionMethods
  dynamicMesh
  #finiteVolume
  #meshTools
)
target_include_directories( renumberMethods
  PUBLIC
  .
)
target_sources( renumberMethods
  PRIVATE
  CuthillMcKeeRenumber/CuthillMcKeeRenumber.C
  manualRenumber/manualRenumber.C
  randomRenumber/randomRenumber.C
  renumberMethod/renumberMethod.C
  springRenumber/springRenumber.C
  structuredRenumber/OppositeFaceCellWaveName.C
  structuredRenumber/structuredRenumber.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  CuthillMcKeeRenumber/CuthillMcKeeRenumber.H
  manualRenumber/manualRenumber.H
  randomRenumber/randomRenumber.H
  renumberMethod/renumberMethod.H
  springRenumber/springRenumber.H
  structuredRenumber/OppositeFaceCellWave.H
  structuredRenumber/structuredRenumber.H
)
install( TARGETS renumberMethods )
