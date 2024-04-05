add_executable( surfaceHookUp )
target_link_libraries( surfaceHookUp
  PRIVATE
  OpenFOAM
  fileFormats
  meshTools
  triSurface
)
target_include_directories( surfaceHookUp
  PUBLIC
  .
)
target_sources( surfaceHookUp
  PRIVATE
  surfaceHookUp.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS surfaceHookUp )
