add_executable( surfaceMeshTriangulate )
target_link_libraries( surfaceMeshTriangulate
  PRIVATE
  OpenFOAM
  meshTools
  surfMesh
)
target_include_directories( surfaceMeshTriangulate
  PUBLIC
  .
)
target_sources( surfaceMeshTriangulate
  PRIVATE
  surfaceMeshTriangulate.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceMeshTriangulate )
