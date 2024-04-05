add_executable( surfaceCheck )
target_link_libraries( surfaceCheck
  PRIVATE
  OpenFOAM
  fileFormats
  meshTools
  sampling
  triSurface
)
target_include_directories( surfaceCheck
  PUBLIC
  .
)
target_sources( surfaceCheck
  PRIVATE
  surfaceCheck.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceCheck )
