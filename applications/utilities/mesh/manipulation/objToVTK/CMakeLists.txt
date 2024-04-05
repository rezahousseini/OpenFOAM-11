add_executable( objToVTK )
target_link_libraries( objToVTK
  PRIVATE
  OpenFOAM
)
target_include_directories( objToVTK
  PUBLIC
  .
)
target_sources( objToVTK
  PRIVATE
  objToVTK.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS objToVTK )
