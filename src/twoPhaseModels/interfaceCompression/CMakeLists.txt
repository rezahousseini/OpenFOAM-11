add_library( interfaceCompression )
target_link_libraries( interfaceCompression
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( interfaceCompression
  PUBLIC
  .
)
target_sources( interfaceCompression
  PRIVATE
  MPLIC/MPLIC.C
  MPLIC/MPLICU.C
  MPLIC/MPLICcell.C
  MPLIC/MPLICcellStorage.C
  MPLIC/MPLICface.C
  PLIC/PLIC.C
  PLIC/PLICU.C
  interfaceCompression/interfaceCompression.C
  noInterfaceCompression/noInterfaceCompression.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  MPLIC/MPLIC.H
  MPLIC/MPLICU.H
  MPLIC/MPLICcell.H
  MPLIC/MPLICcellI.H
  MPLIC/MPLICcellStorage.H
  MPLIC/MPLICcellStorageI.H
  MPLIC/MPLICface.H
  MPLIC/MPLICfaceI.H
  PLIC/PLIC.H
  PLIC/PLICU.H
  interfaceCompression/interfaceCompression.H
  noInterfaceCompression/noInterfaceCompression.H
)
install( TARGETS interfaceCompression )
