add_executable( netgenNeutralToFoam )
target_link_libraries( netgenNeutralToFoam
  PRIVATE
  OpenFOAM
)
target_include_directories( netgenNeutralToFoam
  PUBLIC
  .
)
target_sources( netgenNeutralToFoam
  PRIVATE
  netgenNeutralToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS netgenNeutralToFoam )
