FLEX_TARGET( gambitToFoam
  gambitToFoam.L
  ${CMAKE_CURRENT_BINARY_DIR}/gambitToFoam.L.cpp
  COMPILE_FLAGS ${FLEX_FLAGS}
)
add_executable( gambitToFoam )
target_link_libraries( gambitToFoam
  PRIVATE
  OpenFOAM
)
target_include_directories( gambitToFoam
  PUBLIC
  .
)
target_sources( gambitToFoam
  PRIVATE
  ${CMAKE_CURRENT_BINARY_DIR}/gambitToFoam.L.cpp
)
install( TARGETS gambitToFoam )
