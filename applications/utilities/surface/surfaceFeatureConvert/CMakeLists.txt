add_executable( surfaceFeatureConvert )
target_link_libraries( surfaceFeatureConvert
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( surfaceFeatureConvert
  PUBLIC
  .
)
target_sources( surfaceFeatureConvert
  PRIVATE
  surfaceFeatureConvert.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceFeatureConvert )
