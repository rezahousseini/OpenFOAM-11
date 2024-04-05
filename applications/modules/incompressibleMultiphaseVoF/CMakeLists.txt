add_library( incompressibleMultiphaseVoF )
target_link_libraries( incompressibleMultiphaseVoF
  PRIVATE
  OpenFOAM
  finiteVolume
  incompressibleMomentumTransportModels
  multiphaseVoFSolver
  physicalProperties
)
target_include_directories( incompressibleMultiphaseVoF
  PUBLIC
  .
)
target_sources( incompressibleMultiphaseVoF
  PRIVATE
  alphaPredictor.C
  incompressibleMultiphaseVoF.C
  incompressibleMultiphaseVoFMixture/incompressibleMultiphaseVoFMixture.C
  incompressibleMultiphaseVoFMixture/incompressibleVoFphase/incompressibleVoFphase.C
  pressureCorrector.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  incompressibleMultiphaseVoF.H
  incompressibleMultiphaseVoFMixture/incompressibleMultiphaseVoFMixture.H
  incompressibleMultiphaseVoFMixture/incompressibleVoFphase/incompressibleVoFphase.H
)
install( TARGETS incompressibleMultiphaseVoF )