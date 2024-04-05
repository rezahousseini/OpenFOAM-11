add_library( XiIgnition )
target_link_libraries( XiIgnition
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( XiIgnition
  PUBLIC
  .
)
target_sources( XiIgnition
  PRIVATE
  ignition.C
  ignitionIO.C
  ignitionSite.C
  ignitionSiteIO.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  ignite.H
  ignition.H
  ignitionSite.H
)
install( TARGETS XiIgnition )
