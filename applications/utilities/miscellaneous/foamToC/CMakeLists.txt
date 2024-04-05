add_executable( foamToC )
target_link_libraries( foamToC
  PRIVATE
  OpenFOAM
)
target_include_directories( foamToC
  PUBLIC
  .
)
target_sources( foamToC
  PRIVATE
  foamToC.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS foamToC )
