add_executable( transformPoints )
target_link_libraries( transformPoints
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( transformPoints
  PUBLIC
  .
)
target_sources( transformPoints
  PRIVATE
  transformPoints.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createTransforms.H
)
install( TARGETS transformPoints )
