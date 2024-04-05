add_executable( surfaceToPatch )
target_link_libraries( surfaceToPatch
  PRIVATE
  OpenFOAM
  dynamicMesh
  meshTools
  triSurface
)
target_include_directories( surfaceToPatch
  PUBLIC
  .
)
target_sources( surfaceToPatch
  PRIVATE
  surfaceToPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceToPatch )
