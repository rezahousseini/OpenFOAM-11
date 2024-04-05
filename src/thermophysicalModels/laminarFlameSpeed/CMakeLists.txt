add_library( laminarFlameSpeedModels )
target_link_libraries( laminarFlameSpeedModels
  PRIVATE
  OpenFOAM
  #finiteVolume
  fluidThermophysicalModels
  #fvModels
  #meshTools
  multicomponentThermophysicalModels
  #physicalProperties
  #specie
)
target_include_directories( laminarFlameSpeedModels
  PUBLIC
  .
)
target_sources( laminarFlameSpeedModels
  PRIVATE
  Gulders/Gulders.C
  GuldersEGR/GuldersEGR.C
  RaviPetersen/RaviPetersen.C
  constant/constant.C
  laminarFlameSpeed/laminarFlameSpeed.C
  laminarFlameSpeed/laminarFlameSpeedNew.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Gulders/Gulders.H
  GuldersEGR/GuldersEGR.H
  RaviPetersen/RaviPetersen.H
  constant/constant.H
  laminarFlameSpeed/laminarFlameSpeed.H
)
install( TARGETS laminarFlameSpeedModels )
