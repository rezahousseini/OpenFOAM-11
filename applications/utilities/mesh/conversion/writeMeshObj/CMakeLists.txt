add_executable( writeMeshObj )
target_link_libraries( writeMeshObj
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( writeMeshObj
  PUBLIC
  .
)
target_sources( writeMeshObj
  PRIVATE
  writeMeshObj.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS writeMeshObj )
