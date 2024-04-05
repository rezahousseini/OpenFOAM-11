add_executable( changeDictionary )
target_link_libraries( changeDictionary
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  meshTools
)
target_include_directories( changeDictionary
  PUBLIC
  .
)
target_sources( changeDictionary
  PRIVATE
  changeDictionary.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS changeDictionary )
