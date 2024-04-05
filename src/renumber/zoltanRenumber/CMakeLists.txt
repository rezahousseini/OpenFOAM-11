add_library( zoltanRenumber )
target_link_libraries( zoltanRenumber
  PRIVATE
  OpenFOAM
  #Pstream
  renumberMethods
)
target_include_directories( zoltanRenumber
  PUBLIC
  .
)
target_sources( zoltanRenumber
  PRIVATE
  zoltanRenumber.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  zoltanRenumber.H
)
install( TARGETS zoltanRenumber )
