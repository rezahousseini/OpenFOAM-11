add_executable( vtkUnstructuredToFoam )
target_link_libraries( vtkUnstructuredToFoam
  PRIVATE
  OpenFOAM
  fileFormats
)
target_include_directories( vtkUnstructuredToFoam
  PUBLIC
  .
)
target_sources( vtkUnstructuredToFoam
  PRIVATE
  vtkUnstructuredToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS vtkUnstructuredToFoam )
