add_library( pairPatchAgglomeration )
target_link_libraries( pairPatchAgglomeration
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( pairPatchAgglomeration
  PUBLIC
  .
)
target_sources( pairPatchAgglomeration
  PRIVATE
  pairPatchAgglomeration.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  pairPatchAgglomeration.H
)
install( TARGETS pairPatchAgglomeration )
