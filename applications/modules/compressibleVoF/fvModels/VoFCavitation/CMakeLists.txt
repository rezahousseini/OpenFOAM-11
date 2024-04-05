add_library( compressibleVoFCavitation )
target_link_libraries( compressibleVoFCavitation
  PRIVATE

)
target_include_directories( compressibleVoFCavitation
  PUBLIC
  .
)
target_sources( compressibleVoFCavitation
  PRIVATE
  VoFCavitation.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFCavitation.H
)
install( TARGETS compressibleVoFCavitation )