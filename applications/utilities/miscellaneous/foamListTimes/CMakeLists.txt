add_executable( foamListTimes )
target_link_libraries( foamListTimes
  PRIVATE
  OpenFOAM
)
target_include_directories( foamListTimes
  PUBLIC
  .
)
target_sources( foamListTimes
  PRIVATE
  foamListTimes.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS foamListTimes )
