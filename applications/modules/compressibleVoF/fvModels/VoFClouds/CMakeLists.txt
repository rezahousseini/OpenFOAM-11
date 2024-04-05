add_library( VoFClouds )
target_link_libraries( VoFClouds
  PRIVATE

)
target_include_directories( VoFClouds
  PUBLIC
  .
)
target_sources( VoFClouds
  PRIVATE
  VoFClouds.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFClouds.H
)
install( TARGETS VoFClouds )