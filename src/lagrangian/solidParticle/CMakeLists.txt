add_library( solidParticle )
target_link_libraries( solidParticle
  PRIVATE
  OpenFOAM
  finiteVolume
  lagrangian
)
target_include_directories( solidParticle
  PUBLIC
  .
)
target_sources( solidParticle
  PRIVATE
  solidParticle.C
  solidParticleCloud.C
  solidParticleIO.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  solidParticle.H
  solidParticleCloud.H
  solidParticleCloudI.H
  solidParticleI.H
)
install( TARGETS solidParticle )
