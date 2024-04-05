add_executable( temporalInterpolate )
target_link_libraries( temporalInterpolate
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( temporalInterpolate
  PUBLIC
  .
)
target_sources( temporalInterpolate
  PRIVATE
  temporalInterpolate.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS temporalInterpolate )
