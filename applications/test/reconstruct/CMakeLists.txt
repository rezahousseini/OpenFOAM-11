add_executable( Test-reconstruct )
target_link_libraries( Test-reconstruct
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
)
target_include_directories( Test-reconstruct
  PUBLIC
  .
)
target_sources( Test-reconstruct
  PRIVATE
  Test-reconstruct.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-reconstruct COMMAND Test-reconstruct
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)