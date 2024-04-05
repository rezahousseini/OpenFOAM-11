add_library( multiphaseProperties )
target_link_libraries( multiphaseProperties
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( multiphaseProperties
  PUBLIC
  .
)
target_sources( multiphaseProperties
  PRIVATE
  alphaContactAngle/alphaContactAngleFvPatchScalarField.C
  correctContactAngle/correctContactAngle.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  alphaContactAngle/alphaContactAngleFvPatchScalarField.H
  correctContactAngle/correctContactAngle.H
)
install( TARGETS multiphaseProperties )
