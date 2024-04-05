add_executable( Test-polygonTriangulate )
target_link_libraries( Test-polygonTriangulate
  PRIVATE
  OpenFOAM
  fileFormats
)
target_include_directories( Test-polygonTriangulate
  PUBLIC
  .
)
target_sources( Test-polygonTriangulate
  PRIVATE
  Test-polygonTriangulate.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-polygonTriangulate COMMAND Test-polygonTriangulate
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)