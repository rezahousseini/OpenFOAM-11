add_executable( createBaffles )
target_link_libraries( createBaffles
  PRIVATE
  OpenFOAM
  dynamicMesh
  finiteVolume
  genericPatchFields
  meshTools
)
target_include_directories( createBaffles
  PUBLIC
  .
)
target_sources( createBaffles
  PRIVATE
  createBaffles.C
  faceSelection/faceSelection.C
  faceSelection/faceZoneSelection.C
  faceSelection/searchableSurfaceSelection.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  faceSelection/faceSelection.H
  faceSelection/faceZoneSelection.H
  faceSelection/searchableSurfaceSelection.H
)
install( TARGETS createBaffles )
