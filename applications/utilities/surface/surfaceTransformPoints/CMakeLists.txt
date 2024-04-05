add_executable( surfaceTransformPoints )
target_link_libraries( surfaceTransformPoints
  PRIVATE
  OpenFOAM
  surfMesh
)
target_include_directories( surfaceTransformPoints
  PUBLIC
  .
  PRIVATE
  $<TARGET_PROPERTY:transformPoints,INCLUDE_DIRECTORIES> # add include directories from executable
)
target_sources( surfaceTransformPoints
  PRIVATE
  surfaceTransformPoints.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceTransformPoints )
