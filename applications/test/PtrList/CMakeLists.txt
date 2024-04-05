add_executable( Test-PtrList )
target_link_libraries( Test-PtrList
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-PtrList
  PUBLIC
  .
)
target_sources( Test-PtrList
  PRIVATE
  Test-PtrList.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PtrList COMMAND Test-PtrList
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)