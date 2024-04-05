add_executable( smapToFoam )
target_link_libraries( smapToFoam
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( smapToFoam
  PUBLIC
  .
)
target_sources( smapToFoam
  PRIVATE
  smapToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS smapToFoam )
