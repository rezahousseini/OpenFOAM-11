add_executable( orientFaceZone )
target_link_libraries( orientFaceZone
  PRIVATE
  OpenFOAM
  genericPatches
  meshTools
  snappyHexMesh
  triSurface
)
target_include_directories( orientFaceZone
  PUBLIC
  .
)
target_sources( orientFaceZone
  PRIVATE
  orientFaceZone.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS orientFaceZone )
