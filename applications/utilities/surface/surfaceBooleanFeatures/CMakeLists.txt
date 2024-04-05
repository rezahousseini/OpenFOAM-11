add_executable( surfaceBooleanFeatures )
target_link_libraries( surfaceBooleanFeatures
  PRIVATE
  OpenFOAM
  meshTools
  triSurface
)
target_include_directories( surfaceBooleanFeatures
  PUBLIC
  .
)
target_sources( surfaceBooleanFeatures
  PRIVATE
  surfaceBooleanFeatures.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceBooleanFeatures )
