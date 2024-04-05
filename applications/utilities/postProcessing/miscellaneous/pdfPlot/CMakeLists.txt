add_executable( pdfPlot )
target_link_libraries( pdfPlot
  PRIVATE
  OpenFOAM
  finiteVolume
  meshTools
  sampling
)
target_include_directories( pdfPlot
  PUBLIC
  .
)
target_sources( pdfPlot
  PRIVATE
  pdfPlot.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  createFields.H
)
install( TARGETS pdfPlot )
