FLEX_TARGET( ansysToFoam
  ansysToFoam.L
  ${CMAKE_CURRENT_BINARY_DIR}/ansysToFoam.L.cpp
  COMPILE_FLAGS ${FLEX_FLAGS}
)
add_executable( ansysToFoam )
target_link_libraries( ansysToFoam
  PRIVATE
  OpenFOAM
)
target_include_directories( ansysToFoam
  PUBLIC
  .
)
target_sources( ansysToFoam
  PRIVATE
  ansysToFoam.C
  ${CMAKE_CURRENT_BINARY_DIR}/ansysToFoam.L.cpp

)
install( TARGETS ansysToFoam )
