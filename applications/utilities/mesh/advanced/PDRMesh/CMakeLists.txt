add_executable( PDRMesh )
target_link_libraries( PDRMesh
  PRIVATE
  OpenFOAM
  compressibleMomentumTransportModels
  dynamicMesh
  finiteVolume
  fluidThermophysicalModels
  fvModels
  genericPatches
  meshTools
  momentumTransportModels
)
target_include_directories( PDRMesh
  PUBLIC
  .
)
target_sources( PDRMesh
  PRIVATE
  PDRMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS PDRMesh )
