add_library( foamToVTK )
target_link_libraries( foamToVTK
  PRIVATE
  OpenFOAM
  dynamicMesh
  fileFormats
  genericPatchFields
  lagrangian
)
target_include_directories( foamToVTK
  PUBLIC
  .
)
target_sources( foamToVTK
  PRIVATE
  internalWriter.C
  lagrangianWriter.C
  patchWriter.C
  surfaceMeshWriter.C
  vtkMesh.C
  vtkTopo.C
  writeFaceSet.C
  writePointSet.C
  writeSurfFields.C
  writeVTK/writeVTK.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  internalWriter.H
  lagrangianWriter.H
  patchWriter.H
  readFields.H
  surfaceMeshWriter.H
  vtkMesh.H
  vtkTopo.H
  vtkWriteFieldOps.H
  writeFaceSet.H
  writePointSet.H
  writeSurfFields.H
  writeVTK/writeVTK.H
)
install( TARGETS foamToVTK )
