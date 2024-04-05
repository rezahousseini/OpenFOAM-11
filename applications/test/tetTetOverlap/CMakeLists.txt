add_executable( Test-tetTetOverlap )
target_link_libraries( Test-tetTetOverlap
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( Test-tetTetOverlap
  PUBLIC
  .
)
target_sources( Test-tetTetOverlap
  PRIVATE
  Test-tetTetOverlap.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-tetTetOverlap COMMAND Test-tetTetOverlap
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)