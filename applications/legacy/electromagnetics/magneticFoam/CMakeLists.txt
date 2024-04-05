add_executable( magneticFoam )
target_link_libraries( magneticFoam
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( magneticFoam
  PUBLIC
  .
)
target_sources( magneticFoam
  PRIVATE
  magneticFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
  magnet.H
)
install( TARGETS magneticFoam )
