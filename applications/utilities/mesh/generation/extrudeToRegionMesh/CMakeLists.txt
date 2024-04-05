add_executable( extrudeToRegionMesh )
target_link_libraries( extrudeToRegionMesh
  PRIVATE
  OpenFOAM
  dynamicMesh
  extrudeModel
  fileFormats
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( extrudeToRegionMesh
  PUBLIC
  .
)
target_sources( extrudeToRegionMesh
  PRIVATE
  extrudeToRegionMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS extrudeToRegionMesh )
