add_executable( surfaceMeshImport )
target_link_libraries( surfaceMeshImport
  PRIVATE
  OpenFOAM
  meshTools
  surfMesh
)
target_include_directories( surfaceMeshImport
  PUBLIC
  .
)
target_sources( surfaceMeshImport
  PRIVATE
  surfaceMeshImport.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceMeshImport )
