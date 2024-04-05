add_executable( Test-PrimitivePatch )
target_link_libraries( Test-PrimitivePatch
  PRIVATE
  OpenFOAM
)
target_include_directories( Test-PrimitivePatch
  PUBLIC
  .
)
target_sources( Test-PrimitivePatch
  PRIVATE
  Test-PrimitivePatch.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-PrimitivePatch COMMAND Test-PrimitivePatch
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)