add_library( incompressibleDriftFlux )
target_link_libraries( incompressibleDriftFlux
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  finiteVolume
  incompressibleTwoPhases
  momentumTransportModels
  physicalProperties
  twoPhaseSolver
)
target_include_directories( incompressibleDriftFlux
  PUBLIC
  .
)
target_sources( incompressibleDriftFlux
  PRIVATE
  alphaSuSp.C
  incompressibleDriftFlux.C
  incompressibleDriftFluxMixture/incompressibleDriftFluxMixture.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  incompressibleDriftFlux.H
  incompressibleDriftFluxMixture/incompressibleDriftFluxMixture.H
  mixtureViscosityModels/BinghamPlastic/BinghamPlastic.H
  mixtureViscosityModels/Quemada/Quemada.H
  mixtureViscosityModels/mixtureViscosityModel/mixtureViscosityModel.H
  mixtureViscosityModels/plastic/plastic.H
  mixtureViscosityModels/slurry/slurry.H
  relativeVelocityModels/MichaelsBolger/MichaelsBolger.H
  relativeVelocityModels/general/general.H
  relativeVelocityModels/relativeVelocityModel/relativeVelocityModel.H
  relativeVelocityModels/simple/simple.H
)
install( TARGETS incompressibleDriftFlux )