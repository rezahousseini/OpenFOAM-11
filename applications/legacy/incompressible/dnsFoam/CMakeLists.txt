add_executable( dnsFoam )
target_link_libraries( dnsFoam
  PRIVATE
  OpenFOAM
  randomProcesses
)
target_include_directories( dnsFoam
  PUBLIC
  .
)
target_sources( dnsFoam
  PRIVATE
  dnsFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
  globalProperties.H
  readPhysicalProperties.H
  readTurbulenceProperties.H
)
install( TARGETS dnsFoam )
