add_executable( equilibriumCO )
target_link_libraries( equilibriumCO
  PRIVATE
  OpenFOAM
  specie
)
target_include_directories( equilibriumCO
  PUBLIC
  .
)
target_sources( equilibriumCO
  PRIVATE
  equilibriumCO.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS equilibriumCO )
