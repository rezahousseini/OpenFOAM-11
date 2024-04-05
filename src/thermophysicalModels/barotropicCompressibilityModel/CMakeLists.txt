add_library( barotropicCompressibilityModel )
target_link_libraries( barotropicCompressibilityModel
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( barotropicCompressibilityModel
  PUBLIC
  .
)
target_sources( barotropicCompressibilityModel
  PRIVATE
  Chung/Chung.C
  Wallis/Wallis.C
  barotropicCompressibilityModel/barotropicCompressibilityModel.C
  barotropicCompressibilityModel/barotropicCompressibilityModelNew.C
  linear/linear.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Chung/Chung.H
  Wallis/Wallis.H
  barotropicCompressibilityModel/barotropicCompressibilityModel.H
  linear/linear.H
)
install( TARGETS barotropicCompressibilityModel )
