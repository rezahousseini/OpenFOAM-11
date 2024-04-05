add_executable( Test-GAMGAgglomeration )
target_link_libraries( Test-GAMGAgglomeration
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-GAMGAgglomeration
  PUBLIC
  .
)
target_sources( Test-GAMGAgglomeration
  PRIVATE
  Test-GAMGAgglomeration.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-GAMGAgglomeration COMMAND Test-GAMGAgglomeration
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)