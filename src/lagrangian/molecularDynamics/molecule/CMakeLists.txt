add_library( molecule )
target_link_libraries( molecule
  PRIVATE
  OpenFOAM
  #finiteVolume
  lagrangian
  meshTools
  molecularMeasurements
  potential
)
target_include_directories( molecule
  PUBLIC
  .
)
target_sources( molecule
  PRIVATE
  molecule/molecule.C
  molecule/moleculeIO.C
  moleculeCloud/moleculeCloud.C
  reducedUnits/reducedUnits.C
  reducedUnits/reducedUnitsIO.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  mdTools/averageMDFields.H
  mdTools/calculateAutoCorrelationFunctions.H
  mdTools/calculateMDFields.H
  mdTools/calculateTransportProperties.H
  mdTools/createAutoCorrelationFunctions.H
  mdTools/createMDFields.H
  mdTools/createRefUnits.H
  mdTools/md.H
  mdTools/meanMomentumEnergyAndNMols.H
  mdTools/resetMDFields.H
  mdTools/temperatureAndPressure.H
  mdTools/temperatureAndPressureVariables.H
  mdTools/temperatureEquilibration.H
  molecule/molecule.H
  molecule/moleculeI.H
  moleculeCloud/moleculeCloud.H
  moleculeCloud/moleculeCloudI.H
  reducedUnits/reducedUnits.H
  reducedUnits/reducedUnitsI.H
)
install( TARGETS molecule )
