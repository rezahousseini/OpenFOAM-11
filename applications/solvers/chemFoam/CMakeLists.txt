add_executable( chemFoam )
target_link_libraries( chemFoam
  PRIVATE
  OpenFOAM
  chemistryModel
  finiteVolume
  meshTools
)
target_include_directories( chemFoam
  PUBLIC
  .
)
target_sources( chemFoam
  PRIVATE
  chemFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  YEqn.H
  createBaseFields.H
  createControls.H
  createFieldRefs.H
  createFields.H
  createZeroDimensionalFvMesh.H
  hEqn.H
  output.H
  pEqn.H
  readControls.H
  readInitialConditions.H
  setDeltaT.H
  solveChemistry.H
  thermoTypeFunctions.H
)
install( TARGETS chemFoam )
