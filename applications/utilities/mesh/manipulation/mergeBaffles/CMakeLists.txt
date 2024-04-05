add_executable( mergeBaffles )
target_link_libraries( mergeBaffles
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( mergeBaffles
  PUBLIC
  .
)
target_sources( mergeBaffles
  PRIVATE
  mergeBaffles.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS mergeBaffles )
