add_executable( surfaceFind )
target_link_libraries( surfaceFind
  PRIVATE
  OpenFOAM
  meshTools
  surfMesh
)
target_include_directories( surfaceFind
  PUBLIC
  .
)
target_sources( surfaceFind
  PRIVATE
  surfaceFind.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceFind )
