add_executable( foamToTecplot360 )
target_link_libraries( foamToTecplot360
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatchFields
  lagrangian
  ${TECIO_LIBRARY}
)
target_include_directories( foamToTecplot360
  PUBLIC
  .
)
target_sources( foamToTecplot360
  PRIVATE
  foamToTecplot360.C
  tecplotWriter.C
  vtkMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  readFields.H
  tecplotWriter.H
  vtkMesh.H
)
install( TARGETS foamToTecplot360 )
