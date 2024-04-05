add_executable( mixtureAdiabaticFlameT )
target_link_libraries( mixtureAdiabaticFlameT
  PRIVATE
  OpenFOAM
  specie
)
target_include_directories( mixtureAdiabaticFlameT
  PUBLIC
  .
)
target_sources( mixtureAdiabaticFlameT
  PRIVATE
  mixtureAdiabaticFlameT.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  mixture.H
  substance.H
)
install( TARGETS mixtureAdiabaticFlameT )
