add_executable( setWaves )
target_link_libraries( setWaves
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
  waves
)
target_include_directories( setWaves
  PUBLIC
  .
)
target_sources( setWaves
  PRIVATE
  setWaves.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS setWaves )
