add_executable( nullObject )
target_link_libraries( nullObject
  PRIVATE
  OpenFOAM
)
target_include_directories( nullObject
  PUBLIC
  .
)
target_sources( nullObject
  PRIVATE
  Test-nullObject.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME nullObject COMMAND nullObject
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)