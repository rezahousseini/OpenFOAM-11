add_library( multiphaseEulerFoamFunctionObjects )
target_link_libraries( multiphaseEulerFoamFunctionObjects
  PRIVATE
  OpenFOAM
  eulerianInterfacialModels
  finiteVolume
  multiphaseThermophysicalTransportModels
  phaseSystem
  sampling
)
target_include_directories( multiphaseEulerFoamFunctionObjects
  PUBLIC
  .
)
target_sources( multiphaseEulerFoamFunctionObjects
  PRIVATE
  phaseForces/phaseForces.C
  phaseMap/phaseMap.C
  populationBalanceMoments/populationBalanceMoments.C
  populationBalanceSizeDistribution/populationBalanceSizeDistribution.C
  wallBoilingProperties/wallBoilingProperties.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  phaseForces/phaseForces.H
  phaseMap/phaseMap.H
  populationBalanceMoments/populationBalanceMoments.H
  populationBalanceSizeDistribution/populationBalanceSizeDistribution.H
  wallBoilingProperties/wallBoilingProperties.H
)
install( TARGETS multiphaseEulerFoamFunctionObjects )