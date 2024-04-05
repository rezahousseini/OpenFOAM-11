add_executable( snappyHexMeshConfig )
target_link_libraries( snappyHexMeshConfig
  PRIVATE
  OpenFOAM
  blockMesh
  fileFormats
  meshTools
  sampling
  triSurface
)
target_include_directories( snappyHexMeshConfig
  PUBLIC
  .
)
target_sources( snappyHexMeshConfig
  PRIVATE
  blockMeshCartesianConfiguration.C
  blockMeshConfigurationBase.C
  blockMeshCylindricalConfiguration.C
  caseFileConfiguration.C
  meshQualityConfiguration.C
  meshingSurface.C
  meshingSurfaceList.C
  snappyHexMeshConfig.C
  snappyHexMeshConfiguration.C
  surfaceFeaturesConfiguration.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Tuple3.H
  blockMeshCartesianConfiguration.H
  blockMeshConfigurationBase.H
  blockMeshCylindricalConfiguration.H
  blockMeshFunctions.H
  caseFileConfiguration.H
  meshQualityConfiguration.H
  meshingSurface.H
  meshingSurfaceList.H
  snappyHexMeshConfiguration.H
  surfaceFeaturesConfiguration.H
)
install( TARGETS snappyHexMeshConfig )
