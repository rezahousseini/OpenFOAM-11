add_executable( faceAgglomerate )
target_link_libraries( faceAgglomerate
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
  pairPatchAgglomeration
  triSurface
)
target_include_directories( faceAgglomerate
  PUBLIC
  .
)
target_sources( faceAgglomerate
  PRIVATE
  faceAgglomerate.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS faceAgglomerate )
