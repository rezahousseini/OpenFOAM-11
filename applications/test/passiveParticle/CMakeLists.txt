add_executable( Test-passiveParticle )
target_link_libraries( Test-passiveParticle
  PRIVATE
  OpenFOAM
  finiteVolume
  lagrangian
  meshTools
)
target_include_directories( Test-passiveParticle
  PUBLIC
  .
)
target_sources( Test-passiveParticle
  PRIVATE
  Test-passiveParticle.C

  PRIVATE
  FILE_SET HEADERS
  FILES

)
add_test( NAME Test-passiveParticle COMMAND Test-passiveParticle
  WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/etc
)