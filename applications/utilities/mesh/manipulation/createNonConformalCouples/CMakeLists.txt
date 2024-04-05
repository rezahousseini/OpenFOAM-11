add_executable( createNonConformalCouples )
target_link_libraries( createNonConformalCouples
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( createNonConformalCouples
  PUBLIC
  .
)
target_sources( createNonConformalCouples
  PRIVATE
  createNonConformalCouples.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS createNonConformalCouples )
