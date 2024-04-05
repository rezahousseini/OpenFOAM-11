add_library( film )
target_link_libraries( film
  PRIVATE
  OpenFOAM
  finiteVolume
  fluidThermophysicalModels
  fluidThermophysicalTransportModel
  isothermalFilm
)
target_include_directories( film
  PUBLIC
  .
)
target_sources( film
  PRIVATE
  film.C
  thermophysicalPredictor.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  film.H
  filmThermophysicalTransportModels/filmThermophysicalTransportModel.H
  filmThermophysicalTransportModels/filmThermophysicalTransportModels.H
)
install( TARGETS film )