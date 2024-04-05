add_library( filmCloudTransfer )
target_link_libraries( filmCloudTransfer
  PRIVATE
  isothermalFilm
)
target_include_directories( filmCloudTransfer
  PUBLIC
  .
)
target_sources( filmCloudTransfer
  PRIVATE
  cloudFilmTransfer/CloudFilmTransfer/CloudFilmTransferBase.C
  cloudFilmTransfer/makeReactingMultiphaseParcelCloudFilmTransfer.C
  cloudFilmTransfer/makeReactingParcelCloudFilmTransfer.C
  cloudFilmTransfer/makeSprayParcelCloudFilmTransfer.C
  cloudFilmTransfer/makeThermoParcelCloudFilmTransfer.C
  ejectionModels/BrunDripping/BrunDripping.C
  ejectionModels/curvatureSeparation/curvatureSeparation.C
  ejectionModels/dripping/dripping.C
  ejectionModels/ejectionModel/ejectionModel.C
  ejectionModels/ejectionModel/ejectionModelNew.C
  filmCloudTransfer.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  cloudFilmTransfer/CloudFilmTransfer/CloudFilmTransfer.H
  ejectionModels/BrunDripping/BrunDripping.H
  ejectionModels/curvatureSeparation/curvatureSeparation.H
  ejectionModels/dripping/dripping.H
  ejectionModels/ejectionModel/ejectionModel.H
  filmCloudTransfer.H
)
install( TARGETS filmCloudTransfer )