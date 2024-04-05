add_executable( Test-spline )
target_link_libraries( Test-spline
  PRIVATE
  OpenFOAM
  blockMesh
)
target_include_directories( Test-spline
  PUBLIC
  .
)
target_sources( Test-spline
  PRIVATE
  Test-spline.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-spline COMMAND Test-spline
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)