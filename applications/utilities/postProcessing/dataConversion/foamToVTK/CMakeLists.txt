add_subdirectory( foamToVTK )
add_executable( foamToVTK_exe )
target_link_libraries( foamToVTK_exe
  PRIVATE
  OpenFOAM
  dynamicMesh
  fileFormats
  foamToVTK
  #genericPatchFields
  lagrangian
)
target_include_directories( foamToVTK_exe
  PUBLIC
  .
)
target_sources( foamToVTK_exe
  PRIVATE
  foamToVTK.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  foamToVTK/internalWriter.H
  foamToVTK/lagrangianWriter.H
  foamToVTK/patchWriter.H
  foamToVTK/readFields.H
  foamToVTK/surfaceMeshWriter.H
  foamToVTK/vtkMesh.H
  foamToVTK/vtkTopo.H
  foamToVTK/vtkWriteFieldOps.H
  foamToVTK/writeFaceSet.H
  foamToVTK/writePointSet.H
  foamToVTK/writeSurfFields.H
  foamToVTK/writeVTK/writeVTK.H
)
install( TARGETS foamToVTK_exe )
