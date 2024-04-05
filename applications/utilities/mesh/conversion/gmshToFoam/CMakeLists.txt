add_executable( gmshToFoam )
target_link_libraries( gmshToFoam
  PRIVATE
  OpenFOAM
  dynamicMesh
  genericPatches
  meshTools
)
target_include_directories( gmshToFoam
  PUBLIC
  .
)
target_sources( gmshToFoam
  PRIVATE
  gmshToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS gmshToFoam )
