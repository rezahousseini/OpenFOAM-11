add_executable( star4ToFoam )
target_link_libraries( star4ToFoam
  PRIVATE
  OpenFOAM
  conversion
)
target_include_directories( star4ToFoam
  PUBLIC
  .
)
target_sources( star4ToFoam
  PRIVATE
  star4ToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS star4ToFoam )
