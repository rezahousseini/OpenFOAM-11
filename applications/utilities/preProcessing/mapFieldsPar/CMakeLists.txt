add_executable( mapFieldsPar )
target_link_libraries( mapFieldsPar
  PRIVATE
  OpenFOAM
  finiteVolume
  genericPatchFields
  lagrangian
  meshTools
)
target_include_directories( mapFieldsPar
  PUBLIC
  .
)
target_sources( mapFieldsPar
  PRIVATE
  mapClouds.C
  mapFieldsPar.C
  mapGeometricFields.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createTimes.H
  mapClouds.H
  mapGeometricFields.H
  setTimeIndex.H
)
install( TARGETS mapFieldsPar )
