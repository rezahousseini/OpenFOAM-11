add_library( VoFSolidificationMeltingSource )
target_link_libraries( VoFSolidificationMeltingSource
  PRIVATE

)
target_include_directories( VoFSolidificationMeltingSource
  PUBLIC
  .
)
target_sources( VoFSolidificationMeltingSource
  PRIVATE
  VoFSolidificationMeltingSource.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFSolidificationMeltingSource.H
)
install( TARGETS VoFSolidificationMeltingSource )