add_executable( foamFormatConvert )
target_link_libraries( foamFormatConvert
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
)
target_include_directories( foamFormatConvert
  PUBLIC
  .
)
target_sources( foamFormatConvert
  PRIVATE
  foamFormatConvert.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  writeMeshObject.H
)
install( TARGETS foamFormatConvert )
