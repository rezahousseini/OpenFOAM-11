add_library( compressibleCavitationModels )
target_link_libraries( compressibleCavitationModels
  PRIVATE
  OpenFOAM
  compressibleTwoPhases
  fluidThermophysicalModels
  saturationModels
  twoPhaseMixture
)
target_include_directories( compressibleCavitationModels
  PUBLIC
  .
)
target_sources( compressibleCavitationModels
  PRIVATE
  Kunz/Kunz.C
  Merkle/Merkle.C
  Saito/Saito.C
  SchnerrSauer/SchnerrSauer.C
  cavitationModel/cavitationModel.C
  cavitationModel/cavitationModelNew.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Kunz/Kunz.H
  Merkle/Merkle.H
  Saito/Saito.H
  SchnerrSauer/SchnerrSauer.H
  cavitationModel/cavitationModel.H
)
install( TARGETS compressibleCavitationModels )
