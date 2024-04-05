add_library( multicomponentThermophysicalModels )
target_link_libraries( multicomponentThermophysicalModels
  PRIVATE
  OpenFOAM

  PUBLIC
  fluidThermophysicalModels
  specie
)
target_include_directories( multicomponentThermophysicalModels
  PUBLIC
  .
)
target_sources( multicomponentThermophysicalModels
  PRIVATE
  derivedFvPatchFields/fixedUnburntEnthalpy/fixedUnburntEnthalpyFvPatchScalarField.C
  derivedFvPatchFields/gradientUnburntEnthalpy/gradientUnburntEnthalpyFvPatchScalarField.C
  derivedFvPatchFields/mixedUnburntEnthalpy/mixedUnburntEnthalpyFvPatchScalarField.C
  fluidMulticomponentThermo/fluidMulticomponentThermo.C
  functionObjects/massFractions/massFractions.C
  functionObjects/moleFractions/moleFractions.C
  mixtures/basicCombustionMixture/basicCombustionMixture.C
  mixtures/basicSpecieMixture/basicSpecieMixture.C
  psiMulticomponentThermo/psiMulticomponentThermo.C
  psiMulticomponentThermo/psiMulticomponentThermos.C
  psiuMulticomponentThermo/psiuMulticomponentThermo.C
  psiuMulticomponentThermo/psiuMulticomponentThermos.C
  rhoMulticomponentThermo/rhoMulticomponentThermo.C
  rhoMulticomponentThermo/rhoMulticomponentThermos.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  derivedFvPatchFields/fixedUnburntEnthalpy/fixedUnburntEnthalpyFvPatchScalarField.H
  derivedFvPatchFields/gradientUnburntEnthalpy/gradientUnburntEnthalpyFvPatchScalarField.H
  derivedFvPatchFields/mixedUnburntEnthalpy/mixedUnburntEnthalpyFvPatchScalarField.H
  fluidMulticomponentThermo/fluidMulticomponentThermo.H
  functionObjects/massFractions/massFractions.H
  functionObjects/moleFractions/moleFractions.H
  makeMulticomponentThermo.H
  mixtures/SpecieMixture/SpecieMixture.H
  mixtures/basicCombustionMixture/basicCombustionMixture.H
  mixtures/basicCombustionMixture/basicCombustionMixtureI.H
  mixtures/basicSpecieMixture/basicSpecieMixture.H
  mixtures/basicSpecieMixture/basicSpecieMixtureI.H
  mixtures/coefficientMulticomponentMixture/coefficientMulticomponentMixture.H
  mixtures/coefficientWilkeMulticomponentMixture/coefficientWilkeMulticomponentMixture.H
  mixtures/egrMixture/egrMixture.H
  mixtures/homogeneousMixture/homogeneousMixture.H
  mixtures/inhomogeneousMixture/inhomogeneousMixture.H
  mixtures/multicomponentMixture/multicomponentMixture.H
  mixtures/singleComponentMixture/singleComponentMixture.H
  mixtures/valueMulticomponentMixture/valueMulticomponentMixture.H
  mixtures/veryInhomogeneousMixture/veryInhomogeneousMixture.H
  psiMulticomponentThermo/psiMulticomponentThermo.H
  psiuMulticomponentThermo/heheuPsiThermo.H
  psiuMulticomponentThermo/psiuMulticomponentThermo.H
  rhoMulticomponentThermo/rhoMulticomponentThermo.H
)
install( TARGETS multicomponentThermophysicalModels )
