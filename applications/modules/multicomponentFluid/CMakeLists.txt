add_library( multicomponentFluid )
target_link_libraries( multicomponentFluid
  PRIVATE
  OpenFOAM
  combustionModels
  finiteVolume
  fluidMulticomponentThermophysicalTransportModels
  isothermalFluid
  multicomponentThermophysicalModels
)
target_include_directories( multicomponentFluid
  PUBLIC
  .
)
target_sources( multicomponentFluid
  PRIVATE
  multicomponentFluid.C
  setRDeltaT.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  multicomponentFluid.H
)
install( TARGETS multicomponentFluid )