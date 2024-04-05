add_executable( Test-ExtendedStencil )
target_link_libraries( Test-ExtendedStencil
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( Test-ExtendedStencil
  PUBLIC
  .
)
target_sources( Test-ExtendedStencil
  PRIVATE
  Test-ExtendedStencil.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-ExtendedStencil COMMAND Test-ExtendedStencil
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)