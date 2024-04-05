add_executable( engineCompRatio )
target_link_libraries( engineCompRatio
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  meshTools
)
target_include_directories( engineCompRatio
  PUBLIC
  .
)
target_sources( engineCompRatio
  PRIVATE
  engineCompRatio.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS engineCompRatio )
