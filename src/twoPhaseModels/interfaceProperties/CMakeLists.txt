add_library( interfaceProperties )
target_link_libraries( interfaceProperties
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( interfaceProperties
  PUBLIC
  .
)
target_sources( interfaceProperties
  PRIVATE
  contactAngle/contactAngleFvPatchScalarField.C
  contactAngleModels/constant/constantContactAngle.C
  contactAngleModels/contactAngleModel/contactAngleModel.C
  contactAngleModels/contactAngleModel/contactAngleModelNew.C
  contactAngleModels/dynamic/dynamicContactAngle.C
  contactAngleModels/gravitational/gravitationalContactAngle.C
  contactAngleModels/temperatureDependent/temperatureDependentContactAngle.C
  interfaceProperties.C
  surfaceTensionModels/constant/constantSurfaceTension.C
  surfaceTensionModels/surfaceTensionModel/surfaceTensionModel.C
  surfaceTensionModels/surfaceTensionModel/surfaceTensionModelNew.C
  surfaceTensionModels/temperatureDependent/temperatureDependentSurfaceTension.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  contactAngle/contactAngleFvPatchScalarField.H
  contactAngleModels/constant/constantContactAngle.H
  contactAngleModels/contactAngleModel/contactAngleModel.H
  contactAngleModels/dynamic/dynamicContactAngle.H
  contactAngleModels/gravitational/gravitationalContactAngle.H
  contactAngleModels/temperatureDependent/temperatureDependentContactAngle.H
  interfaceProperties.H
  surfaceTensionModels/constant/constantSurfaceTension.H
  surfaceTensionModels/surfaceTensionModel/surfaceTensionModel.H
  surfaceTensionModels/temperatureDependent/temperatureDependentSurfaceTension.H
)
install( TARGETS interfaceProperties )
