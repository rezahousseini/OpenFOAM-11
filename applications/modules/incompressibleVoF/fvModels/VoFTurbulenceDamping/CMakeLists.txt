add_library( VoFTurbulenceDamping )
target_link_libraries( VoFTurbulenceDamping
  PRIVATE
  incompressibleMomentumTransportModels
)
target_include_directories( VoFTurbulenceDamping
  PUBLIC
  .
)
target_sources( VoFTurbulenceDamping
  PRIVATE
  VoFTurbulenceDamping.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFTurbulenceDamping.H
)
install( TARGETS VoFTurbulenceDamping )