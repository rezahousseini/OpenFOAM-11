add_library( genericPatchFields )
target_link_libraries( genericPatchFields
  PRIVATE
  OpenFOAM
  OSspecific
  finiteVolume
  genericPatches
)
target_include_directories( genericPatchFields
  PUBLIC
  .
)
target_sources( genericPatchFields
  PRIVATE
  genericFvPatch/genericFvPatch.C
  genericFvPatchField/genericFvPatchFields.C
  genericPatchField/genericPatchField.C
  genericPointPatchField/genericPointPatchFields.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  genericFvPatch/genericFvPatch.H
  genericFvPatchField/genericFvPatchField.H
  genericFvPatchField/genericFvPatchFields.H
  genericPatchField/genericPatchField.H
  genericPointPatchField/genericPointPatchField.H
  genericPointPatchField/genericPointPatchFields.H
)
install( TARGETS genericPatchFields )
