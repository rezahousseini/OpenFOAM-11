add_executable( shallowWaterFoam )
target_link_libraries( shallowWaterFoam
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( shallowWaterFoam
  PUBLIC
  .
)
target_sources( shallowWaterFoam
  PRIVATE
  shallowWaterFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  CourantNo.H
  createFields.H
  createPhi.H
  readGravitationalAcceleration.H
)
install( TARGETS shallowWaterFoam )
