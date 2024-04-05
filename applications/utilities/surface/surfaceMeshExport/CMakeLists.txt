add_executable( surfaceMeshExport )
target_link_libraries( surfaceMeshExport
  PRIVATE
  OpenFOAM
  meshTools
  surfMesh
)
target_include_directories( surfaceMeshExport
  PUBLIC
  .
)
target_sources( surfaceMeshExport
  PRIVATE
  surfaceMeshExport.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceMeshExport )
