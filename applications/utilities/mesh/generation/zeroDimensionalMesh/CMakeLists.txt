add_executable( zeroDimensionalMesh )
target_link_libraries( zeroDimensionalMesh
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( zeroDimensionalMesh
  PUBLIC
  .
)
target_sources( zeroDimensionalMesh
  PRIVATE
  zeroDimensionalMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS zeroDimensionalMesh )
