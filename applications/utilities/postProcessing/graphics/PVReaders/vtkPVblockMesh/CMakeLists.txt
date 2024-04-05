add_library( vtkPVblockMesh )
target_link_libraries( vtkPVblockMesh
  PRIVATE
  OpenFOAM
  blockMesh
  vtkPVFoam
)
target_include_directories( vtkPVblockMesh
  PUBLIC
  .
)
target_sources( vtkPVblockMesh
  PRIVATE
  vtkPVblockMesh.C
  vtkPVblockMeshConvert.C
  vtkPVblockMeshUtils.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  vtkOpenFOAMPoints.H
  vtkPVblockMesh.H
)
install( TARGETS vtkPVblockMesh )