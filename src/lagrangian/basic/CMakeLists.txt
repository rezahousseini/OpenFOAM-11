add_library( lagrangian )
target_link_libraries( lagrangian
  PRIVATE
  OpenFOAM

  PUBLIC
  finiteVolume
  meshTools
)
target_include_directories( lagrangian
  PUBLIC
  .
)
target_sources( lagrangian
  PRIVATE
  IOPosition/IOPositionName.C
  InteractionLists/referredWallFace/referredWallFace.C
  cloud/cloud.C
  indexedParticle/indexedParticleCloud.C
  particle/particle.C
  particle/particleIO.C
  passiveParticle/passiveParticleCloud.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Cloud/Cloud.H
  IOPosition/IOPosition.H
  InteractionLists/InteractionLists.H
  InteractionLists/InteractionListsI.H
  InteractionLists/referredWallFace/referredWallFace.H
  InteractionLists/referredWallFace/referredWallFaceI.H
  cloud/cloud.H
  demandDrivenEntry/demandDrivenEntry.H
  demandDrivenEntry/demandDrivenEntryI.H
  indexedParticle/indexedParticle.H
  indexedParticle/indexedParticleCloud.H
  particle/particle.H
  particle/particleI.H
  particle/particleMacros.H
  passiveParticle/passiveParticle.H
  passiveParticle/passiveParticleCloud.H
)
install( TARGETS lagrangian )
