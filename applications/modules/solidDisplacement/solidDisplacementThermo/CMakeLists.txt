add_library( solidDisplacementThermo )
target_link_libraries( solidDisplacementThermo
  PRIVATE

)
target_include_directories( solidDisplacementThermo
  PUBLIC
  .
)
target_sources( solidDisplacementThermo
  PRIVATE
  solidDisplacementThermo.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  solidDisplacementThermo.H
)
install( TARGETS solidDisplacementThermo )