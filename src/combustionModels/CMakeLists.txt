add_library( combustionModels )
target_link_libraries( combustionModels
  PRIVATE
  OpenFOAM
  chemistryModel
  compressibleMomentumTransportModels
  fluidThermophysicalModels
  multicomponentThermophysicalModels
  radiationModels
)
target_include_directories( combustionModels
  PUBLIC
  .
)
target_sources( combustionModels
  PRIVATE
  EDC/EDC.C
  FSD/FSD.C
  FSD/reactionRateFlameAreaModels/consumptionSpeed/consumptionSpeed.C
  FSD/reactionRateFlameAreaModels/reactionRateFlameArea/reactionRateFlameArea.C
  FSD/reactionRateFlameAreaModels/reactionRateFlameArea/reactionRateFlameAreaNew.C
  FSD/reactionRateFlameAreaModels/relaxation/relaxation.C
  PaSR/PaSR.C
  combustionModel/combustionModel.C
  combustionModel/combustionModelNew.C
  diffusion/diffusion.C
  functionObjects/Qdot/Qdot.C
  functionObjects/adjustTimeStepToCombustion/adjustTimeStepToCombustion.C
  infinitelyFastChemistry/infinitelyFastChemistry.C
  laminar/laminar.C
  noCombustion/noCombustion.C
  radiationModels/absorptionEmissionModels/greyMeanCombustion/greyMeanCombustion.C
  radiationModels/absorptionEmissionModels/wideBandCombustion/wideBandCombustion.C
  radiationModels/sootModels/mixtureFraction/mixtureFraction.C
  singleStepCombustion/singleStepCombustion.C
  zoneCombustion/zoneCombustion.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  EDC/EDC.H
  FSD/FSD.H
  FSD/reactionRateFlameAreaModels/consumptionSpeed/consumptionSpeed.H
  FSD/reactionRateFlameAreaModels/reactionRateFlameArea/reactionRateFlameArea.H
  FSD/reactionRateFlameAreaModels/relaxation/relaxation.H
  PaSR/PaSR.H
  combustionModel/combustionModel.H
  combustionModel/combustionModelI.H
  diffusion/diffusion.H
  functionObjects/Qdot/Qdot.H
  functionObjects/adjustTimeStepToCombustion/adjustTimeStepToCombustion.H
  infinitelyFastChemistry/infinitelyFastChemistry.H
  laminar/laminar.H
  noCombustion/noCombustion.H
  radiationModels/absorptionEmissionModels/greyMeanCombustion/greyMeanCombustion.H
  radiationModels/absorptionEmissionModels/wideBandCombustion/wideBandCombustion.H
  radiationModels/sootModels/mixtureFraction/mixtureFraction.H
  singleStepCombustion/singleStepCombustion.H
  singleStepCombustion/singleStepCombustionI.H
  zoneCombustion/zoneCombustion.H
)
install( TARGETS combustionModels )
