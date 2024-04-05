add_executable( patchSummary )
target_link_libraries( patchSummary
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( patchSummary
  PUBLIC
  .
)
target_sources( patchSummary
  PRIVATE
  patchSummary.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  patchSummaryTemplates.H
)
install( TARGETS patchSummary )
