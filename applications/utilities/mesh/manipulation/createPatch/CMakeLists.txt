add_executable( createPatch )
target_link_libraries( createPatch
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( createPatch
  PUBLIC
  .
)
target_sources( createPatch
  PRIVATE
  createPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS createPatch )
