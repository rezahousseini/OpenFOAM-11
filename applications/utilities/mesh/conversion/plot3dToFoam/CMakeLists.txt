add_executable( plot3dToFoam )
target_link_libraries( plot3dToFoam
  PRIVATE
  OpenFOAM
  genericPatches
  meshTools
)
target_include_directories( plot3dToFoam
  PUBLIC
  .
)
target_sources( plot3dToFoam
  PRIVATE
  hexBlock.C
  plot3dToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  hexBlock.H
)
install( TARGETS plot3dToFoam )
