add_library( filmVoFTransfer )
target_link_libraries( filmVoFTransfer
  PRIVATE
  compressibleVoF
  isothermalFilm
)
target_include_directories( filmVoFTransfer
  PUBLIC
  .
)
target_sources( filmVoFTransfer
  PRIVATE
  VoFFilmTransfer.C
  filmVoFTransfer.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  VoFFilmTransfer.H
  filmVoFTransfer.H
)
install( TARGETS filmVoFTransfer )