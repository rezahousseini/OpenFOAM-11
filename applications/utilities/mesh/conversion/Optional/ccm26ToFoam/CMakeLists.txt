add_executable( ccm26ToFoam )
target_link_libraries( ccm26ToFoam
  PRIVATE
  OpenFOAM
  ccmio
  finiteVolume
  meshTools
  ${ccmio_LIBRARY}
)
target_include_directories( ccm26ToFoam
  PUBLIC
  .
)
target_sources( ccm26ToFoam
  PRIVATE
  ccm26ToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS ccm26ToFoam )
