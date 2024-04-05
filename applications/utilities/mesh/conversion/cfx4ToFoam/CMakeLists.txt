add_executable( cfx4ToFoam )
target_link_libraries( cfx4ToFoam
  PRIVATE
  OpenFOAM
)
target_include_directories( cfx4ToFoam
  PUBLIC
  .
)
target_sources( cfx4ToFoam
  PRIVATE
  cfx4ToFoam.C
  hexBlock.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  hexBlock.H
)
install( TARGETS cfx4ToFoam )
