FLEX_TARGET( fluentMeshToFoam
  fluentMeshToFoam.L
  ${CMAKE_CURRENT_BINARY_DIR}/fluentMeshToFoam.L.cpp
  COMPILE_FLAGS ${FLEX_FLAGS}
)
add_executable( fluentMeshToFoam )
target_link_libraries( fluentMeshToFoam
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( fluentMeshToFoam
  PUBLIC
  .
)
target_sources( fluentMeshToFoam
  PRIVATE
  create3DCellShape.C
  extrudedQuadCellShape.C
  extrudedTriangleCellShape.C
  ${CMAKE_CURRENT_BINARY_DIR}/fluentMeshToFoam.L.cpp

  PRIVATE
  FILE_SET HEADERS
  FILES
  cellShapeRecognition.H
)
install( TARGETS fluentMeshToFoam )
