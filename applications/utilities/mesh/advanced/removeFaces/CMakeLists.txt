add_executable( removeFaces )
target_link_libraries( removeFaces
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( removeFaces
  PUBLIC
  .
)
target_sources( removeFaces
  PRIVATE
  removeFaces.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS removeFaces )
