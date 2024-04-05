add_library( conversion )
target_link_libraries( conversion
  PRIVATE
  OpenFOAM
  OSspecific
  dynamicMesh
  finiteVolume
  meshTools
)
target_include_directories( conversion
  PUBLIC
  .
)
target_sources( conversion
  PRIVATE
  ensight/file/ensightFile.C
  ensight/file/ensightGeoFile.C
  ensight/part/ensightPart.C
  ensight/part/ensightPartCells.C
  ensight/part/ensightPartFaces.C
  ensight/part/ensightPartIO.C
  ensight/part/ensightParts.C
  mergedCyclic/mergedCyclicPolyPatch.C
  mergedCyclic/polyMeshUnMergeCyclics.C
  meshReader/calcPointCells.C
  meshReader/createPolyBoundary.C
  meshReader/createPolyCells.C
  meshReader/meshReader.C
  meshReader/meshReaderAux.C
  meshReader/starcd/STARCDMeshReader.C
  meshTables/boundaryRegion.C
  meshTables/cellTable.C
  meshTables/dictionaryIOMap.C
  meshWriter/meshWriter.C
  meshWriter/starcd/STARCDMeshWriter.C
  polyDualMesh/polyDualMesh.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  ensight/file/ensightFile.H
  ensight/file/ensightGeoFile.H
  ensight/part/ensightPart.H
  ensight/part/ensightPartCells.H
  ensight/part/ensightPartFaces.H
  ensight/part/ensightParts.H
  mergedCyclic/mergedCyclicPolyPatch.H
  mergedCyclic/polyMeshUnMergeCyclics.H
  meshReader/meshReader.H
  meshReader/starcd/STARCDMeshReader.H
  meshTables/boundaryRegion.H
  meshTables/cellTable.H
  meshWriter/meshWriter.H
  meshWriter/starcd/STARCDMeshWriter.H
  polyDualMesh/polyDualMesh.H
)
install( TARGETS conversion )
