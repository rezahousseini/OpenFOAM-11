add_executable( equilibriumFlameT )
target_link_libraries( equilibriumFlameT
  PRIVATE
  OpenFOAM
  specie
)
target_include_directories( equilibriumFlameT
  PUBLIC
  .
)
target_sources( equilibriumFlameT
  PRIVATE
  equilibriumFlameT.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS equilibriumFlameT )
