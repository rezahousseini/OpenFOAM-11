FLEX_TARGET(readSTLASCII
  triSurface/interfaces/STL/readSTLASCII.L
  ${CMAKE_CURRENT_BINARY_DIR}/readSTLASCII.L.cpp
  COMPILE_FLAGS ${FLEX_FLAGS}
)
add_library( triSurface )
target_link_libraries( triSurface
  PRIVATE
  OpenFOAM
  surfMesh
)
target_include_directories( triSurface
  PUBLIC
  .
)
target_sources( triSurface
  PRIVATE
  meshTriangulation/meshTriangulation.C
  tools/labelledTri/sortLabelledTri.C
  triSurface/geometricSurfacePatch/geometricSurfacePatch.C
  triSurface/interfaces/AC3D/readAC.C
  triSurface/interfaces/AC3D/writeAC.C
  triSurface/interfaces/GTS/readGTS.C
  triSurface/interfaces/GTS/writeGTS.C
  triSurface/interfaces/NAS/readNAS.C
  triSurface/interfaces/OBJ/readOBJ.C
  triSurface/interfaces/OBJ/writeOBJ.C
  triSurface/interfaces/OFF/readOFF.C
  triSurface/interfaces/OFF/writeOFF.C
  triSurface/interfaces/SMESH/writeSMESH.C
  triSurface/interfaces/STL/readSTL.C
  triSurface/interfaces/STL/readSTLBINARY.C
  triSurface/interfaces/STL/writeSTL.C
  triSurface/interfaces/TRI/readTRI.C
  triSurface/interfaces/TRI/writeTRI.C
  triSurface/interfaces/VTK/readVTK.C
  triSurface/interfaces/VTK/writeVTK.C
  triSurface/stitchTriangles.C
  triSurface/surfacePatch/surfacePatch.C
  triSurface/surfacePatch/surfacePatchIOList.C
  triSurface/triSurface.C
  triSurface/triSurfaceAddressing.C
  triSurfaceFields/triSurfaceFields.C
  ${CMAKE_CURRENT_BINARY_DIR}/readSTLASCII.L.cpp

  PRIVATE
  FILE_SET HEADERS
  FILES
  meshTriangulation/meshTriangulation.H
  tools/hashSignedLabel/hashSignedLabel.H
  tools/labelPair/labelPairLookup.H
  tools/labelledTri/labelledTri.H
  tools/labelledTri/labelledTriI.H
  tools/labelledTri/sortLabelledTri.H
  triSurface/geometricSurfacePatch/geometricSurfacePatch.H
  triSurface/geometricSurfacePatch/geometricSurfacePatchList.H
  triSurface/surfacePatch/surfacePatch.H
  triSurface/surfacePatch/surfacePatchIOList.H
  triSurface/surfacePatch/surfacePatchList.H
  triSurface/triSurface.H
  triSurfaceFields/triSurfaceFields.H
  triSurfaceFields/triSurfaceFieldsFwd.H
  triSurfaceFields/triSurfaceGeoMesh.H
  triSurfaceFields/triSurfacePointGeoMesh.H
)
install( TARGETS triSurface )
