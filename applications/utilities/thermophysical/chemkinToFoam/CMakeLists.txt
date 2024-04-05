FLEX_TARGET( chemkinToFoam
  chemkinReader/chemkinLexer.L
  ${CMAKE_CURRENT_BINARY_DIR}/chemkinLexer.L.cpp
  COMPILE_FLAGS ${FLEX_FLAGS}
)
add_executable( chemkinToFoam )
target_link_libraries( chemkinToFoam
  PRIVATE
  OpenFOAM
  chemistryModel
)
target_include_directories( chemkinToFoam
  PUBLIC
  .
)
target_sources( chemkinToFoam
  PRIVATE
  chemkinReader/chemkinReader.C
  chemkinToFoam.C
  ${CMAKE_CURRENT_BINARY_DIR}/chemkinLexer.L.cpp

  PRIVATE
  FILE_SET HEADERS
  FILES
  chemkinReader/ReactionProxy.H
  chemkinReader/chemkinReader.H
)
install( TARGETS chemkinToFoam )
