add_executable( surfaceFeatures )
target_link_libraries( surfaceFeatures
  PRIVATE
  OpenFOAM
  fileFormats
  meshTools
  sampling
  triSurface
)
target_include_directories( surfaceFeatures
  PUBLIC
  .
)
target_sources( surfaceFeatures
  PRIVATE
  surfaceFeatures.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceFeatures )
