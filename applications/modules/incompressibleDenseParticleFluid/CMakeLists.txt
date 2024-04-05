add_library( incompressibleDenseParticleFluid )
target_link_libraries( incompressibleDenseParticleFluid
  PRIVATE
  OpenFOAM
  finiteVolume
  fluidSolver
  lagrangianParcel
  phaseIncompressibleMomentumTransportModels
  physicalProperties
)
target_include_directories( incompressibleDenseParticleFluid
  PUBLIC
  .
)
target_sources( incompressibleDenseParticleFluid
  PRIVATE
  correctPressure.C
  incompressibleDenseParticleFluid.C
  momentumPredictor.C
  moveMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  incompressibleDenseParticleFluid.H
)
install( TARGETS incompressibleDenseParticleFluid )