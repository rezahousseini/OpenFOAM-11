add_library( DSMC )
target_link_libraries( DSMC
  PRIVATE
  OpenFOAM
  finiteVolume
  lagrangian
)
target_include_directories( DSMC
  PUBLIC
  .
)
target_sources( DSMC
  PRIVATE
  clouds/Templates/DSMCCloud/DSMCCloudName.C
  parcels/derived/dsmcParcel/defineDSMCParcel.C
  parcels/derived/dsmcParcel/dsmcParcel.C
  parcels/derived/dsmcParcel/makeDSMCParcelBinaryCollisionModels.C
  parcels/derived/dsmcParcel/makeDSMCParcelInflowBoundaryModels.C
  parcels/derived/dsmcParcel/makeDSMCParcelWallInteractionModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  clouds/Templates/DSMCCloud/DSMCCloud.H
  clouds/Templates/DSMCCloud/DSMCCloudI.H
  clouds/derived/dsmcCloud/dsmcCloud.H
  parcels/Templates/DSMCParcel/DSMCParcel.H
  parcels/Templates/DSMCParcel/DSMCParcelI.H
  parcels/derived/dsmcParcel/dsmcParcel.H
  submodels/BinaryCollisionModel/BinaryCollisionModel/BinaryCollisionModel.H
  submodels/BinaryCollisionModel/LarsenBorgnakkeVariableHardSphere/LarsenBorgnakkeVariableHardSphere.H
  submodels/BinaryCollisionModel/NoBinaryCollision/NoBinaryCollision.H
  submodels/BinaryCollisionModel/VariableHardSphere/VariableHardSphere.H
  submodels/InflowBoundaryModel/FreeStream/FreeStream.H
  submodels/InflowBoundaryModel/InflowBoundaryModel/InflowBoundaryModel.H
  submodels/InflowBoundaryModel/NoInflow/NoInflow.H
  submodels/WallInteractionModel/MaxwellianThermal/MaxwellianThermal.H
  submodels/WallInteractionModel/MixedDiffuseSpecular/MixedDiffuseSpecular.H
  submodels/WallInteractionModel/SpecularReflection/SpecularReflection.H
  submodels/WallInteractionModel/WallInteractionModel/WallInteractionModel.H
)
install( TARGETS DSMC )
