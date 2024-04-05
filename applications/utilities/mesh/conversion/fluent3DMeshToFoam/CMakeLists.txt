FLEX_TARGET( fluent3DMeshToFoam
  fluent3DMeshToFoam.L
  ${CMAKE_CURRENT_BINARY_DIR}/fluent3DMeshToFoam.L.cpp
  COMPILE_FLAGS ${FLEX_FLAGS}
)
add_executable( fluent3DMeshToFoam )
target_link_libraries( fluent3DMeshToFoam
  PRIVATE
  OpenFOAM
  conversion
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( fluent3DMeshToFoam
  PUBLIC
  .
)
target_sources( fluent3DMeshToFoam
  PRIVATE
  fluent3DMeshToFoam.C
  ${CMAKE_CURRENT_BINARY_DIR}/fluent3DMeshToFoam.L.cpp
)
install( TARGETS fluent3DMeshToFoam )
