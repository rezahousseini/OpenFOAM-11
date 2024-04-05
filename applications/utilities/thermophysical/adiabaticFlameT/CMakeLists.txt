add_executable( adiabaticFlameT )
target_link_libraries( adiabaticFlameT
  PRIVATE
  OpenFOAM
  specie
)
target_include_directories( adiabaticFlameT
  PUBLIC
  .
)
target_sources( adiabaticFlameT
  PRIVATE
  adiabaticFlameT.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS adiabaticFlameT )
