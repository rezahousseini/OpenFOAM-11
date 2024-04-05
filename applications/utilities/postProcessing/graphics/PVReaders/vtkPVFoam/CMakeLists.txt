add_library( vtkPVFoam )
target_link_libraries( vtkPVFoam
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  lagrangian
  ${VTK_LIBRARIES}
)
target_include_directories( vtkPVFoam
  PUBLIC
  .
)
target_sources( vtkPVFoam
  PRIVATE
  vtkPVFoam.C
  vtkPVFoamFields.C
  vtkPVFoamMesh.C
  vtkPVFoamMeshLagrangian.C
  vtkPVFoamMeshSet.C
  vtkPVFoamMeshVolume.C
  vtkPVFoamMeshZone.C
  vtkPVFoamUpdateInfo.C
  vtkPVFoamUtils.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  vtkOpenFOAMPoints.H
  vtkOpenFOAMTupleRemap.H
  vtkPVFoam.H
  vtkPVFoamAddToSelection.H
  vtkPVFoamLagrangianFields.H
  vtkPVFoamPatchField.H
  vtkPVFoamPointFields.H
  vtkPVFoamSurfaceField.H
  vtkPVFoamVolFields.H
)
install( TARGETS vtkPVFoam )
