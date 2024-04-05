add_library( genericPatches )
target_link_libraries( genericPatches
  PRIVATE
  OpenFOAM
  OSspecific
)
target_include_directories( genericPatches
  PUBLIC
  .
)
target_sources( genericPatches
  PRIVATE
  genericPointPatch/genericPointPatch.C
  genericPolyPatch/genericPolyPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  genericPointPatch/genericPointPatch.H
  genericPolyPatch/genericPolyPatch.H
)
install( TARGETS genericPatches )
