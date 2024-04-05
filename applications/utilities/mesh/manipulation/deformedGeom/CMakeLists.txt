add_executable( deformedGeom )
target_link_libraries( deformedGeom
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatches
  meshTools
)
target_include_directories( deformedGeom
  PUBLIC
  .
)
target_sources( deformedGeom
  PRIVATE
  deformedGeom.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS deformedGeom )
