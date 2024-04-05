add_library( solidThermo )
target_link_libraries( solidThermo
  PRIVATE
  OpenFOAM

  PUBLIC
  fluidThermophysicalModels
  specie
)
target_include_directories( solidThermo
  PUBLIC
  .
)
target_sources( solidThermo
  PRIVATE
  constAnisoSolidThermo/constAnisoSolidThermo.C
  constSolidThermo/constSolidThermo.C
  solidThermo/solidThermo.C
  solidThermo/solidThermos.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  constAnisoSolidThermo/constAnisoSolidThermo.H
  constSolidThermo/constSolidThermo.H
  makeSolidThermo.H
  solidSpecie/include/forSolids.H
  solidSpecie/transport/constAniso/constAnisoSolidTransport.H
  solidSpecie/transport/constAniso/constAnisoSolidTransportI.H
  solidSpecie/transport/constIso/constIsoSolidTransport.H
  solidSpecie/transport/constIso/constIsoSolidTransportI.H
  solidSpecie/transport/exponential/exponentialSolidTransport.H
  solidSpecie/transport/exponential/exponentialSolidTransportI.H
  solidSpecie/transport/polynomial/polynomialSolidTransport.H
  solidSpecie/transport/polynomial/polynomialSolidTransportI.H
  solidSpecie/transport/tabulated/tabulatedSolidTransport.H
  solidSpecie/transport/tabulated/tabulatedSolidTransportI.H
  solidThermo/heSolidThermo.H
  solidThermo/solidThermo.H
)
install( TARGETS solidThermo )
