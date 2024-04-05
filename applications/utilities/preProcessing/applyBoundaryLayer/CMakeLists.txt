add_executable( applyBoundaryLayer )
target_link_libraries( applyBoundaryLayer
  PRIVATE
  OpenFOAM
  finiteVolume
  fvModels
  genericPatchFields
  incompressibleMomentumTransportModels
  meshTools
  momentumTransportModels
  physicalProperties
)
target_include_directories( applyBoundaryLayer
  PUBLIC
  .
)
target_sources( applyBoundaryLayer
  PRIVATE
  applyBoundaryLayer.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS applyBoundaryLayer )
