add_library( solidDisplacement )
target_link_libraries( solidDisplacement
  PRIVATE
  OpenFOAM
  finiteVolume
  solid
  solidThermo
)
target_include_directories( solidDisplacement
  PUBLIC
  .
)
target_sources( solidDisplacement
  PRIVATE
  derivedFvPatchFields/hydrostaticDisplacement/hydrostaticDisplacementFvPatchVectorField.C
  derivedFvPatchFields/tractionDisplacement/tractionDisplacementFvPatchVectorField.C
  solidDisplacement.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  derivedFvPatchFields/hydrostaticDisplacement/hydrostaticDisplacementFvPatchVectorField.H
  derivedFvPatchFields/tractionDisplacement/tractionDisplacementFvPatchVectorField.H
  solidDisplacement.H
  solidDisplacementThermo/solidDisplacementThermo.H
)
install( TARGETS solidDisplacement )