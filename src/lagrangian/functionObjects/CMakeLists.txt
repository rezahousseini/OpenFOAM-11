add_library( lagrangianFunctionObjects )
target_link_libraries( lagrangianFunctionObjects
  PRIVATE
  DSMC
  OpenFOAM
  lagrangian
  lagrangianParcel
  meshTools
  physicalProperties
  utilityFunctionObjects
)
target_include_directories( lagrangianFunctionObjects
  PUBLIC
  .
)
target_sources( lagrangianFunctionObjects
  PRIVATE
  cloudInfo/cloudInfo.C
  dsmcFields/dsmcFields.C
  particles/particles.C
  stopAtEmptyClouds/stopAtEmptyClouds.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  cloudInfo/cloudInfo.H
  dsmcFields/dsmcFields.H
  particles/particles.H
  stopAtEmptyClouds/stopAtEmptyClouds.H
)
install( TARGETS lagrangianFunctionObjects )
