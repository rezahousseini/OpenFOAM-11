add_library( fileFormats )
target_link_libraries( fileFormats
  PRIVATE
  OpenFOAM
)
target_include_directories( fileFormats
  PUBLIC
  .
)
target_sources( fileFormats
  PRIVATE
  nas/NASCore.C
  obj/OBJstream.C
  starcd/STARCDCore.C
  vtk/vtkUnstructuredReader.C
  vtk/vtkWriteOps.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  nas/NASCore.H
  obj/OBJstream.H
  starcd/STARCDCore.H
  vtk/vtkUnstructuredReader.H
  vtk/vtkWriteOps.H
  vtk/vtkWritePolyData.H
)
install( TARGETS fileFormats )
