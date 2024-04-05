add_executable( noise )
target_link_libraries( noise
  PRIVATE
  OpenFOAM
  randomProcesses
  sampling
)
target_include_directories( noise
  PUBLIC
  .
)
target_sources( noise
  PRIVATE
  noise.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS noise )
