add_library( incompressibleMomentumTransportModels )
target_link_libraries( incompressibleMomentumTransportModels
  PRIVATE
  OpenFOAM

  PUBLIC
  momentumTransportModels
)
target_include_directories( incompressibleMomentumTransportModels
  PUBLIC
  .
)
target_sources( incompressibleMomentumTransportModels
  PRIVATE
  RAS/LamBremhorstKE/LamBremhorstKE.C
  RAS/LienCubicKE/LienCubicKE.C
  RAS/LienLeschziner/LienLeschziner.C
  RAS/ShihQuadraticKE/ShihQuadraticKE.C
  RAS/kkLOmega/kkLOmega.C
  RAS/qZeta/qZeta.C
  incompressibleMomentumTransportModel.C
  incompressibleMomentumTransportModels.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  RAS/LamBremhorstKE/LamBremhorstKE.H
  RAS/LienCubicKE/LienCubicKE.H
  RAS/LienLeschziner/LienLeschziner.H
  RAS/ShihQuadraticKE/ShihQuadraticKE.H
  RAS/kkLOmega/kkLOmega.H
  RAS/qZeta/qZeta.H
  incompressibleMomentumTransportModel.H
  incompressibleMomentumTransportModels.H
  makeIncompressibleMomentumTransportModel.H
)
install( TARGETS incompressibleMomentumTransportModels )
