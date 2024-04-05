add_library( multiphaseSystems )
target_link_libraries( multiphaseSystems
  PRIVATE

)
target_include_directories( multiphaseSystems
  PUBLIC
  .
)
target_sources( multiphaseSystems
  PRIVATE
  multiphaseSystems.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
install( TARGETS multiphaseSystems )