add_library( SloanRenumber )
target_link_libraries( SloanRenumber
  PRIVATE
  OpenFOAM
  decompositionMethods
  renumberMethods
)
target_include_directories( SloanRenumber
  PUBLIC
  .
)
target_sources( SloanRenumber
  PRIVATE
  SloanRenumber.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  SloanRenumber.H
)
install( TARGETS SloanRenumber )
