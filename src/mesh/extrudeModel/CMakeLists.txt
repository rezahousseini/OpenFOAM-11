add_library( extrudeModel )
target_link_libraries( extrudeModel
  PRIVATE
  OpenFOAM
)
target_include_directories( extrudeModel
  PUBLIC
  .
)
target_sources( extrudeModel
  PRIVATE
  cyclicSector/cyclicSector.C
  extrudeModel/extrudeModel.C
  extrudeModel/extrudeModelNew.C
  linearDirection/linearDirection.C
  linearNormal/linearNormal.C
  linearRadial/linearRadial.C
  planeExtrusion/planeExtrusion.C
  radial/radial.C
  sector/sector.C
  sigmaRadial/sigmaRadial.C
  wedge/wedge.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  cyclicSector/cyclicSector.H
  extrudeModel/extrudeModel.H
  linearDirection/linearDirection.H
  linearNormal/linearNormal.H
  linearRadial/linearRadial.H
  planeExtrusion/planeExtrusion.H
  radial/radial.H
  sector/sector.H
  sigmaRadial/sigmaRadial.H
  wedge/wedge.H
)
install( TARGETS extrudeModel )
