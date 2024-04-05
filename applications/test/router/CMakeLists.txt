add_executable( Test-processorRouter )
target_link_libraries( Test-processorRouter
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( Test-processorRouter
  PUBLIC
  .
)
target_sources( Test-processorRouter
  PRIVATE
  Test-processorRouter.C
  router.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Gather/Gather.H
  Gather/GatherBase.H
  router.H
)
add_test( NAME Test-processorRouter COMMAND Test-processorRouter
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)