add_executable( foamPostProcess )
target_link_libraries( foamPostProcess
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
)
target_include_directories( foamPostProcess
  PUBLIC
  .
)
target_sources( foamPostProcess
  PRIVATE
  foamPostProcess.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS foamPostProcess )
