add_executable( engineSwirl )
target_link_libraries( engineSwirl
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( engineSwirl
  PUBLIC
  .
)
target_sources( engineSwirl
  PRIVATE
  engineSwirl.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS engineSwirl )
