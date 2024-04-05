add_library( isothermalFilm )
target_link_libraries( isothermalFilm
  PRIVATE
  OpenFOAM
  compressibleVoF
  finiteVolume
  fluidThermophysicalModels
  interfaceProperties
  lagrangianParcel
  meshTools
  momentumTransportModels

  PUBLIC
  compressibleMomentumTransportModels
)
target_include_directories( isothermalFilm
  PUBLIC
  .
)
target_sources( isothermalFilm
  PRIVATE
  contactForce.C
  continuityPredictor.C
  correctAlpha.C
  derivedFvPatchFields/alphaOne/alphaOneFvPatchScalarField.C
  derivedFvPatchFields/filmContactAngle/filmContactAngleFvPatchScalarField.C
  derivedFvPatchFields/filmSurfaceVelocity/filmSurfaceVelocityFvPatchVectorField.C
  derivedFvPatchFields/mappedFilmPressure/mappedFilmPressureFvPatchScalarField.C
  filmGaussGrad/filmGaussGrads.C
  isothermalFilm.C
  momentumPredictor.C
  patches/filmFvPatch/filmFvPatch.C
  patches/filmSurface/filmSurfaceFvPatch/filmSurfaceFvPatch.C
  patches/filmSurface/filmSurfacePointPatch/filmSurfacePointPatch.C
  patches/filmSurface/filmSurfacePolyPatch/filmSurfacePolyPatch.C
  patches/filmWall/filmWallFvPatch/filmWallFvPatch.C
  patches/filmWall/filmWallPointPatch/filmWallPointPatch.C
  patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.C
  patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.C
  patches/mappedFilmSurface/mappedFilmSurfacePointPatch/mappedFilmSurfacePointPatch.C
  patches/mappedFilmSurface/mappedFilmSurfacePolyPatch/mappedFilmSurfacePolyPatch.C
  patches/mappedFilmWall/mappedFilmWallFvPatch/mappedFilmWallFvPatch.C
  patches/mappedFilmWall/mappedFilmWallPointPatch/mappedFilmWallPointPatch.C
  patches/mappedFilmWall/mappedFilmWallPolyPatch/mappedFilmWallPolyPatch.C
  prePredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  derivedFvPatchFields/alphaOne/alphaOneFvPatchScalarField.H
  derivedFvPatchFields/filmContactAngle/filmContactAngleFvPatchScalarField.H
  derivedFvPatchFields/filmSurfaceVelocity/filmSurfaceVelocityFvPatchVectorField.H
  derivedFvPatchFields/mappedFilmPressure/mappedFilmPressureFvPatchScalarField.H
  filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModel.H
  filmCompressibleMomentumTransportModels/filmCompressibleMomentumTransportModels.H
  filmCompressibleMomentumTransportModels/makeFilmCompressibleMomentumTransportModel.H
  filmGaussGrad/filmGaussGrad.H
  fvModels/filmCloudTransfer/cloudFilmTransfer/CloudFilmTransfer/CloudFilmTransfer.H
  fvModels/filmCloudTransfer/ejectionModels/BrunDripping/BrunDripping.H
  fvModels/filmCloudTransfer/ejectionModels/curvatureSeparation/curvatureSeparation.H
  fvModels/filmCloudTransfer/ejectionModels/dripping/dripping.H
  fvModels/filmCloudTransfer/ejectionModels/ejectionModel/ejectionModel.H
  fvModels/filmCloudTransfer/filmCloudTransfer.H
  fvModels/filmVoFTransfer/VoFFilmTransfer.H
  fvModels/filmVoFTransfer/filmVoFTransfer.H
  isothermalFilm.H
  patches/filmFvPatch/filmFvPatch.H
  patches/filmSurface/filmSurfaceFvPatch/filmSurfaceFvPatch.H
  patches/filmSurface/filmSurfacePointPatch/filmSurfacePointPatch.H
  patches/filmSurface/filmSurfacePolyPatch/filmSurfacePolyPatch.H
  patches/filmWall/filmWallFvPatch/filmWallFvPatch.H
  patches/filmWall/filmWallPointPatch/filmWallPointPatch.H
  patches/filmWall/filmWallPolyPatch/filmWallPolyPatch.H
  patches/mappedFilmSurface/mappedFilmSurfaceFvPatch/mappedFilmSurfaceFvPatch.H
  patches/mappedFilmSurface/mappedFilmSurfacePointPatch/mappedFilmSurfacePointPatch.H
  patches/mappedFilmSurface/mappedFilmSurfacePolyPatch/mappedFilmSurfacePolyPatch.H
  patches/mappedFilmWall/mappedFilmWallFvPatch/mappedFilmWallFvPatch.H
  patches/mappedFilmWall/mappedFilmWallPointPatch/mappedFilmWallPointPatch.H
  patches/mappedFilmWall/mappedFilmWallPolyPatch/mappedFilmWallPolyPatch.H
)
install( TARGETS isothermalFilm )
