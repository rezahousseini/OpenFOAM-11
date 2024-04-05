add_library( chemistryModel )
target_link_libraries( chemistryModel
  PRIVATE
  ODE
  OpenFOAM

  PUBLIC
  multicomponentThermophysicalModels
)
target_include_directories( chemistryModel
  PUBLIC
  .
)
target_sources( chemistryModel
  PRIVATE
  basicChemistryModel/basicChemistryModel.C
  basicChemistryModel/basicChemistryModelNew.C
  chemistryModel/reduction/DAC/DACChemistryReductionMethods.C
  chemistryModel/reduction/DRG/DRGChemistryReductionMethods.C
  chemistryModel/reduction/DRGEP/DRGEPChemistryReductionMethods.C
  chemistryModel/reduction/EFA/EFAChemistryReductionMethods.C
  chemistryModel/reduction/PFA/PFAChemistryReductionMethods.C
  chemistryModel/reduction/chemistryReductionMethod/chemistryReductionMethods.C
  chemistryModel/reduction/noChemistryReduction/noChemistryReductionMethods.C
  chemistryModel/tabulation/ISAT/ISAT.C
  chemistryModel/tabulation/ISAT/binaryNode/binaryNode.C
  chemistryModel/tabulation/ISAT/binaryTree/binaryTree.C
  chemistryModel/tabulation/ISAT/chemPointISAT/chemPointISAT.C
  chemistryModel/tabulation/chemistryTabulationMethod/chemistryTabulationMethod.C
  chemistryModel/tabulation/chemistryTabulationMethod/chemistryTabulationMethodNew.C
  chemistryModel/tabulation/noChemistryTabulation/noChemistryTabulation.C
  chemistrySolver/EulerImplicit/EulerImplicitChemistrySolvers.C
  chemistrySolver/chemistrySolver/chemistrySolvers.C
  chemistrySolver/noChemistrySolver/noChemistrySolvers.C
  chemistrySolver/ode/odeChemistrySolvers.C
  functionObjects/adjustTimeStepToChemistry/adjustTimeStepToChemistry.C
  functionObjects/specieReactionRates/specieReactionRates.C
  odeChemistryModel/odeChemistryModel.C
  reaction/makeReactions.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  basicChemistryModel/basicChemistryModel.H
  basicChemistryModel/basicChemistryModelI.H
  chemistryModel/chemistryModel.H
  chemistryModel/chemistryModelI.H
  chemistryModel/reduction/DAC/DAC.H
  chemistryModel/reduction/DRG/DRG.H
  chemistryModel/reduction/DRGEP/DRGEP.H
  chemistryModel/reduction/DRGEP/SortableListDRGEP.H
  chemistryModel/reduction/EFA/EFA.H
  chemistryModel/reduction/EFA/SortableListEFA.H
  chemistryModel/reduction/PFA/PFA.H
  chemistryModel/reduction/chemistryReductionMethod/chemistryReductionMethod.H
  chemistryModel/reduction/chemistryReductionMethod/chemistryReductionMethodI.H
  chemistryModel/reduction/makeChemistryReductionMethod.H
  chemistryModel/reduction/noChemistryReduction/noChemistryReduction.H
  chemistryModel/tabulation/ISAT/ISAT.H
  chemistryModel/tabulation/ISAT/binaryNode/binaryNode.H
  chemistryModel/tabulation/ISAT/binaryNode/binaryNodeI.H
  chemistryModel/tabulation/ISAT/binaryTree/binaryTree.H
  chemistryModel/tabulation/ISAT/binaryTree/binaryTreeI.H
  chemistryModel/tabulation/ISAT/chemPointISAT/chemPointISAT.H
  chemistryModel/tabulation/ISAT/chemPointISAT/chemPointISATI.H
  chemistryModel/tabulation/chemistryTabulationMethod/chemistryTabulationMethod.H
  chemistryModel/tabulation/noChemistryTabulation/noChemistryTabulation.H
  chemistrySolver/EulerImplicit/EulerImplicit.H
  chemistrySolver/chemistrySolver/chemistrySolver.H
  chemistrySolver/makeChemistrySolver.H
  chemistrySolver/noChemistrySolver/noChemistrySolver.H
  chemistrySolver/ode/ode.H
  functionObjects/adjustTimeStepToChemistry/adjustTimeStepToChemistry.H
  functionObjects/specieReactionRates/specieReactionRates.H
  odeChemistryModel/odeChemistryModel.H
  odeChemistryModel/odeChemistryModelI.H
  reaction/makeReaction.H
)
install( TARGETS chemistryModel )
