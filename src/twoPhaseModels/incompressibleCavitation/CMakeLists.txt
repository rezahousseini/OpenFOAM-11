add_library( incompressibleCavitationModels )
target_link_libraries( incompressibleCavitationModels
  PRIVATE
  OpenFOAM
  compressibleCavitationModels
  incompressibleTwoPhases
  twoPhaseMixture
)
target_include_directories( incompressibleCavitationModels
  PUBLIC
  .
)
target_sources( incompressibleCavitationModels
  PRIVATE
  Kunz/Kunz.C
  Merkle/Merkle.C
  SchnerrSauer/SchnerrSauer.C
  cavitationModel/cavitationModel.C
  cavitationModel/cavitationModelNew.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Kunz/Kunz.H
  Merkle/Merkle.H
  SchnerrSauer/SchnerrSauer.H
  cavitationModel/cavitationModel.H
)
install( TARGETS incompressibleCavitationModels )
