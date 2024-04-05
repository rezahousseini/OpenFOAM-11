add_executable( setsToZones )
target_link_libraries( setsToZones
  PRIVATE
  OpenFOAM
  meshTools
  sampling
)
target_include_directories( setsToZones
  PUBLIC
  .
)
target_sources( setsToZones
  PRIVATE
  setsToZones.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS setsToZones )
