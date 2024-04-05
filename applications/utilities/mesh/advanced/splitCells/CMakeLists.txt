add_executable( splitCells )
target_link_libraries( splitCells
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( splitCells
  PUBLIC
  .
)
target_sources( splitCells
  PRIVATE
  splitCells.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS splitCells )
