add_executable( surfaceMeshConvert )
target_link_libraries( surfaceMeshConvert
  PRIVATE
  OpenFOAM
  meshTools
  surfMesh
)
target_include_directories( surfaceMeshConvert
  PUBLIC
  .
)
target_sources( surfaceMeshConvert
  PRIVATE
  surfaceMeshConvert.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceMeshConvert )
