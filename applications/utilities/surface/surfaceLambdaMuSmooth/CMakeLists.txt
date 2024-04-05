add_executable( surfaceLambdaMuSmooth )
target_link_libraries( surfaceLambdaMuSmooth
  PRIVATE
  OpenFOAM
  meshTools
  surfMesh
)
target_include_directories( surfaceLambdaMuSmooth
  PUBLIC
  .
)
target_sources( surfaceLambdaMuSmooth
  PRIVATE
  surfaceLambdaMuSmooth.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceLambdaMuSmooth )
