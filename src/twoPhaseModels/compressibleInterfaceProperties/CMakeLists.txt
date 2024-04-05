add_library( compressibleInterfaceProperties )
target_link_libraries( compressibleInterfaceProperties
  PRIVATE
  OpenFOAM
  fluidThermophysicalModels
  interfaceProperties
  thermophysicalProperties
)
target_include_directories( compressibleInterfaceProperties
  PUBLIC
  .
)
target_sources( compressibleInterfaceProperties
  PRIVATE
  surfaceTensionModels/liquidProperties/liquidPropertiesSurfaceTension.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  surfaceTensionModels/liquidProperties/liquidPropertiesSurfaceTension.H
)
install( TARGETS compressibleInterfaceProperties )
