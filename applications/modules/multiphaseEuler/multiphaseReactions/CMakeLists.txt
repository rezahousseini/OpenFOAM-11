add_library( multiphaseReactions )
target_link_libraries( multiphaseReactions
  PRIVATE
  OpenFOAM
  chemistryModel
  finiteVolume
  phaseSystem
  specie
)
target_include_directories( multiphaseReactions
  PUBLIC
  .
)
target_sources( multiphaseReactions
  PRIVATE
  phaseSurfaceArrheniusReactionRate/makephaseSurfaceArrheniusReactions.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  phaseSurfaceArrheniusReactionRate/phaseSurfaceArrheniusReactionRate.H
  phaseSurfaceArrheniusReactionRate/phaseSurfaceArrheniusReactionRateI.H
)
install( TARGETS multiphaseReactions )
