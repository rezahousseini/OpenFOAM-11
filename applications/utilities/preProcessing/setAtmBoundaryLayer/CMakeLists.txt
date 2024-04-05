add_executable( setAtmBoundaryLayer )
target_link_libraries( setAtmBoundaryLayer
  PRIVATE
  OpenFOAM
  atmosphericModels
  finiteVolume
  meshTools
)
target_include_directories( setAtmBoundaryLayer
  PUBLIC
  .
)
target_sources( setAtmBoundaryLayer
  PRIVATE
  setAtmBoundaryLayer.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS setAtmBoundaryLayer )
