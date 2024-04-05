add_executable( createExternalCoupledPatchGeometry )
target_link_libraries( createExternalCoupledPatchGeometry
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  finiteVolume
  fvModels
  meshTools
  momentumTransportModels
)
target_include_directories( createExternalCoupledPatchGeometry
  PUBLIC
  .
)
target_sources( createExternalCoupledPatchGeometry
  PRIVATE
  createExternalCoupledPatchGeometry.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createExternalCoupledPatchGeometryTemplates.H
)
install( TARGETS createExternalCoupledPatchGeometry )
