add_executable( mshToFoam )
target_link_libraries( mshToFoam
  PRIVATE
  OpenFOAM
)
target_include_directories( mshToFoam
  PUBLIC
  .
)
target_sources( mshToFoam
  PRIVATE
  mshToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS mshToFoam )
