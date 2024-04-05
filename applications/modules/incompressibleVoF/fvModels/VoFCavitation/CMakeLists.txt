add_library( VoFCavitation )
target_link_libraries( VoFCavitation
  PRIVATE

)
target_include_directories( VoFCavitation
  PUBLIC
  .
)
target_sources( VoFCavitation
  PRIVATE
  VoFCavitation.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFCavitation.H
)
install( TARGETS VoFCavitation )