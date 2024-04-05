add_executable( datToFoam )
target_link_libraries( datToFoam
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( datToFoam
  PUBLIC
  .
)
target_sources( datToFoam
  PRIVATE
  datToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS datToFoam )
