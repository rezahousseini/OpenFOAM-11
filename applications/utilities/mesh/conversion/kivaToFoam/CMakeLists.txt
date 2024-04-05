add_executable( kivaToFoam )
target_link_libraries( kivaToFoam
  PRIVATE
  OpenFOAM
  conversion
  dynamicMesh
  genericPatches
)
target_include_directories( kivaToFoam
  PUBLIC
  .
)
target_sources( kivaToFoam
  PRIVATE
  kivaToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  checkPatch.H
  readKivaGrid.H
)
install( TARGETS kivaToFoam )
