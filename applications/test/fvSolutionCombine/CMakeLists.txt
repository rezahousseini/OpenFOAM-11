add_executable( Test-fvSolutionCombine )
target_link_libraries( Test-fvSolutionCombine
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( Test-fvSolutionCombine
  PUBLIC
  .
)
target_sources( Test-fvSolutionCombine
  PRIVATE
  Test-fvSolutionCombine.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-fvSolutionCombine COMMAND Test-fvSolutionCombine
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)