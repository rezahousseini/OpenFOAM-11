add_executable( mhdFoam )
target_link_libraries( mhdFoam
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( mhdFoam
  PUBLIC
  .
)
target_sources( mhdFoam
  PRIVATE
  mhdFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createControl.H
  createFields.H
  createPhiB.H
  magneticFieldErr.H
  readBPISOControls.H
)
install( TARGETS mhdFoam )
