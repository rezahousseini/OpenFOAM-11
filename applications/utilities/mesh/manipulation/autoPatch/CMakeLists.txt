add_executable( autoPatch )
target_link_libraries( autoPatch
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( autoPatch
  PUBLIC
  .
)
target_sources( autoPatch
  PRIVATE
  autoPatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS autoPatch )
