add_library( incompressibleDriftFluxRelativeVelocityModels )
target_link_libraries( incompressibleDriftFluxRelativeVelocityModels
  PRIVATE

)
target_include_directories( incompressibleDriftFluxRelativeVelocityModels
  PUBLIC
  .
)
target_sources( incompressibleDriftFluxRelativeVelocityModels
  PRIVATE
  MichaelsBolger/MichaelsBolger.C
  general/general.C
  relativeVelocityModel/relativeVelocityModel.C
  simple/simple.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  MichaelsBolger/MichaelsBolger.H
  general/general.H
  relativeVelocityModel/relativeVelocityModel.H
  simple/simple.H
)
install( TARGETS incompressibleDriftFluxRelativeVelocityModels )