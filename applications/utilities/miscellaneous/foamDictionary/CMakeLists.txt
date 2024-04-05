add_executable( foamDictionary )
target_link_libraries( foamDictionary
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( foamDictionary
  PUBLIC
  .
)
target_sources( foamDictionary
  PRIVATE
  foamDictionary.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS foamDictionary )
