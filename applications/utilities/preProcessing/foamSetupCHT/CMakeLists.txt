add_executable( foamSetupCHT )
target_link_libraries( foamSetupCHT
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( foamSetupCHT
  PUBLIC
  .
)
target_sources( foamSetupCHT
  PRIVATE
  foamSetupCHT.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS foamSetupCHT )
