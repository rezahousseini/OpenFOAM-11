add_executable( setFields )
target_link_libraries( setFields
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( setFields
  PUBLIC
  .
)
target_sources( setFields
  PRIVATE
  setFields.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS setFields )
