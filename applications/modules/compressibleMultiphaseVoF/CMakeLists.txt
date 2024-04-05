add_library( compressibleMultiphaseVoF )
target_link_libraries( compressibleMultiphaseVoF
  PRIVATE
  OpenFOAM
  VoFSolver
  compressibleMomentumTransportModels
  finiteVolume
  fluidSolver
  fluidThermophysicalModels
  multiphaseVoFSolver
)
target_include_directories( compressibleMultiphaseVoF
  PUBLIC
  .
)
target_sources( compressibleMultiphaseVoF
  PRIVATE
  alphaPredictor.C
  compressibleMultiphaseVoF.C
  compressibleMultiphaseVoFMixture/compressibleMultiphaseVoFMixture.C
  compressibleMultiphaseVoFMixture/compressibleMultiphaseVoFMixtureThermo/compressibleMultiphaseVoFMixtureThermo.C
  compressibleMultiphaseVoFMixture/compressibleVoFphase/compressibleVoFphase.C
  momentumPredictor.C
  pressureCorrector.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  compressibleMultiphaseVoF.H
  compressibleMultiphaseVoFMixture/compressibleMultiphaseVoFMixture.H
  compressibleMultiphaseVoFMixture/compressibleMultiphaseVoFMixtureThermo/compressibleMultiphaseVoFMixtureThermo.H
  compressibleMultiphaseVoFMixture/compressibleVoFphase/compressibleVoFphase.H
)
install( TARGETS compressibleMultiphaseVoF )
