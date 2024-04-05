add_executable( foamDataToFluent )
target_link_libraries( foamDataToFluent
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( foamDataToFluent
  PUBLIC
  .
)
target_sources( foamDataToFluent
  PRIVATE
  foamDataToFluent.C
  writeFluentScalarField.C
  writeFluentVectorField.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  writeFluentFields.H
)
install( TARGETS foamDataToFluent )
