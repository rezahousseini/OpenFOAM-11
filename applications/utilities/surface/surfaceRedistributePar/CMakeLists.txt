add_executable( surfaceRedistributePar )
target_link_libraries( surfaceRedistributePar
  PRIVATE
  OpenFOAM
  distributed
  meshTools
  triSurface
)
target_include_directories( surfaceRedistributePar
  PUBLIC
  .
)
target_sources( surfaceRedistributePar
  PRIVATE
  surfaceRedistributePar.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceRedistributePar )
