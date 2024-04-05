add_executable( Test-PtrListDictionary )
target_link_libraries( Test-PtrListDictionary
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-PtrListDictionary
  PUBLIC
  .
)
target_sources( Test-PtrListDictionary
  PRIVATE
  Test-PtrListDictionary.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PtrListDictionary COMMAND Test-PtrListDictionary
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)