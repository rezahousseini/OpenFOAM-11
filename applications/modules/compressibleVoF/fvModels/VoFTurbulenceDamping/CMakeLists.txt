add_library( compressibleVoFTurbulenceDamping )
target_link_libraries( compressibleVoFTurbulenceDamping
  PRIVATE
  compressibleMomentumTransportModels
)
target_include_directories( compressibleVoFTurbulenceDamping
  PUBLIC
  .
)
target_sources( compressibleVoFTurbulenceDamping
  PRIVATE
  VoFTurbulenceDamping.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFTurbulenceDamping.H
)
install( TARGETS compressibleVoFTurbulenceDamping )