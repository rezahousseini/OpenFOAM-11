add_library( multiphaseVoFSolver )
target_link_libraries( multiphaseVoFSolver
  PRIVATE
  OpenFOAM
  finiteVolume
  fluidSolver
  multiphaseProperties

  PUBLIC
  VoFSolver
)
target_include_directories( multiphaseVoFSolver
  PUBLIC
  .
)
target_sources( multiphaseVoFSolver
  PRIVATE
  multiphaseVoFMixture/VoFphase/VoFphase.C
  multiphaseVoFMixture/multiphaseVoFMixture.C
  multiphaseVoFSolver.C
  setInterfaceRDeltaT.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  multiphaseVoFMixture/VoFphase/VoFphase.H
  multiphaseVoFMixture/multiphaseVoFMixture.H
  multiphaseVoFSolver.H
)
install( TARGETS multiphaseVoFSolver )
