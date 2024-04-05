add_executable( surfaceMeshInfo )
target_link_libraries( surfaceMeshInfo
  PRIVATE
  OpenFOAM
  meshTools
  surfMesh
)
target_include_directories( surfaceMeshInfo
  PUBLIC
  .
)
target_sources( surfaceMeshInfo
  PRIVATE
  surfaceMeshInfo.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceMeshInfo )
