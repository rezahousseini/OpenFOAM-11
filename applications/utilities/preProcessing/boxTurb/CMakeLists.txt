add_executable( boxTurb )
target_link_libraries( boxTurb
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
  randomProcesses
)
target_include_directories( boxTurb
  PUBLIC
  .
)
target_sources( boxTurb
  PRIVATE
  boxTurb.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
  readBoxTurbDict.H
)
install( TARGETS boxTurb )
