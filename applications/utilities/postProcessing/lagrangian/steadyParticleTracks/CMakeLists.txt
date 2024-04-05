add_executable( steadyParticleTracks )
target_link_libraries( steadyParticleTracks
  PRIVATE
  OpenFOAM
  finiteVolume
  lagrangian
  meshTools
)
target_include_directories( steadyParticleTracks
  PUBLIC
  .
)
target_sources( steadyParticleTracks
  PRIVATE
  steadyParticleTracks.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
  steadyParticleTracksTemplates.H
)
install( TARGETS steadyParticleTracks )
