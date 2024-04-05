add_library( forces )
target_link_libraries( forces
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  fluidThermophysicalModels
  incompressibleMomentumTransportModels
  phaseCompressibleMomentumTransportModels
  phaseIncompressibleMomentumTransportModels
)
target_include_directories( forces
  PUBLIC
  .
)
target_sources( forces
  PRIVATE
  forceCoeffs/forceCoeffs.C
  forces/forces.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  forceCoeffs/forceCoeffs.H
  forces/forces.H
)
install( TARGETS forces )
