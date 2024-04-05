add_executable( ideasUnvToFoam )
target_link_libraries( ideasUnvToFoam
  PRIVATE
  OpenFOAM
  genericPatches
  meshTools
  surfMesh
)
target_include_directories( ideasUnvToFoam
  PUBLIC
  .
)
target_sources( ideasUnvToFoam
  PRIVATE
  ideasUnvToFoam.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS ideasUnvToFoam )
