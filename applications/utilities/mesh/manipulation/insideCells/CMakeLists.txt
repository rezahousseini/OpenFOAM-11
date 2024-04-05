add_executable( insideCells )
target_link_libraries( insideCells
  PRIVATE
  OpenFOAM
  genericPatches
  meshTools
  triSurface
)
target_include_directories( insideCells
  PUBLIC
  .
)
target_sources( insideCells
  PRIVATE
  insideCells.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS insideCells )
