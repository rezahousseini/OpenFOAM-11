add_executable( tetgenToFoam )
target_link_libraries( tetgenToFoam
  PRIVATE
  OpenFOAM
)
target_include_directories( tetgenToFoam
  PUBLIC
  .
)
target_sources( tetgenToFoam
  PRIVATE
  tetgenToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS tetgenToFoam )
