add_library( incompressibleDriftFluxViscosityModel )
target_link_libraries( incompressibleDriftFluxViscosityModel
  PRIVATE

)
target_include_directories( incompressibleDriftFluxViscosityModel
  PUBLIC
  .
)
target_sources( incompressibleDriftFluxViscosityModel
  PRIVATE
  BinghamPlastic/BinghamPlastic.C
  Quemada/Quemada.C
  mixtureViscosityModel/mixtureViscosityModel.C
  mixtureViscosityModel/mixtureViscosityModelNew.C
  plastic/plastic.C
  slurry/slurry.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  BinghamPlastic/BinghamPlastic.H
  Quemada/Quemada.H
  mixtureViscosityModel/mixtureViscosityModel.H
  plastic/plastic.H
  slurry/slurry.H
)
install( TARGETS incompressibleDriftFluxViscosityModel )