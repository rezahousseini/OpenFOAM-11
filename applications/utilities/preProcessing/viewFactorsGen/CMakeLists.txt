add_executable( viewFactorsGen )
target_link_libraries( viewFactorsGen
  PRIVATE
  OpenFOAM
  distributed
  fileFormats
  finiteVolume
  meshTools
  radiationModels
  triSurface
)
target_include_directories( viewFactorsGen
  PUBLIC
  .
)
target_sources( viewFactorsGen
  PRIVATE
  viewFactorsGen.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  searchingEngine.H
  shootRays.H
)
install( TARGETS viewFactorsGen )
