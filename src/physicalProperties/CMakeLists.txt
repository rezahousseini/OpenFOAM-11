add_library( physicalProperties )
target_link_libraries( physicalProperties
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( physicalProperties
  PUBLIC
  .
)
target_sources( physicalProperties
  PRIVATE
  physicalProperties/physicalProperties.C
  viscosity/viscosity.C
  viscosityModels/constant/constantViscosityModel.C
  viscosityModels/viscosityModel/viscosityModel.C
  viscosityModels/viscosityModel/viscosityModelNew.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  physicalProperties/physicalProperties.H
  viscosity/viscosity.H
  viscosityModels/constant/constantViscosityModel.H
  viscosityModels/viscosityModel/viscosityModel.H
)
install( TARGETS physicalProperties )
