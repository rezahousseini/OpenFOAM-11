add_executable( Test-momentOfInertia )
target_link_libraries( Test-momentOfInertia
  PRIVATE
  OpenFOAM
  meshTools
)
target_include_directories( Test-momentOfInertia
  PUBLIC
  .
)
target_sources( Test-momentOfInertia
  PRIVATE
  Test-momentOfInertia.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-momentOfInertia COMMAND Test-momentOfInertia
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)