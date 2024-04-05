add_executable( particleTracks )
target_link_libraries( particleTracks
  PRIVATE
  OpenFOAM
  fileFormats
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
  sampling
)
target_include_directories( particleTracks
  PUBLIC
  .
)
target_sources( particleTracks
  PRIVATE
  particleTracks.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS particleTracks )
