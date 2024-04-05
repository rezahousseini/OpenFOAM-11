add_executable( surfaceConvert )
target_link_libraries( surfaceConvert
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceConvert
  PUBLIC
  .
)
target_sources( surfaceConvert
  PRIVATE
  surfaceConvert.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceConvert )
