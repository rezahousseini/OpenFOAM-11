add_library( MGridGenGAMGAgglomeration )
target_link_libraries( MGridGenGAMGAgglomeration
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( MGridGenGAMGAgglomeration
  PUBLIC
  .
)
target_sources( MGridGenGAMGAgglomeration
  PRIVATE
  MGridGenGAMGAgglomerate.C
  MGridGenGAMGAgglomeration.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  MGridGenGAMGAgglomeration.H
)
install( TARGETS MGridGenGAMGAgglomeration )
