add_library( potential )
target_link_libraries( potential
  PRIVATE
  OpenFOAM
)
target_include_directories( potential
  PUBLIC
  .
)
target_sources( potential
  PRIVATE
  electrostaticPotential/electrostaticPotential.C
  energyScalingFunction/basic/energyScalingFunction.C
  energyScalingFunction/basic/energyScalingFunctionNew.C
  energyScalingFunction/derived/doubleSigmoid/doubleSigmoid.C
  energyScalingFunction/derived/noScaling/noScaling.C
  energyScalingFunction/derived/shifted/shifted.C
  energyScalingFunction/derived/shiftedForce/shiftedForce.C
  energyScalingFunction/derived/sigmoid/sigmoid.C
  pairPotential/basic/pairPotential.C
  pairPotential/basic/pairPotentialIO.C
  pairPotential/basic/pairPotentialNew.C
  pairPotential/derived/azizChen/azizChen.C
  pairPotential/derived/coulomb/coulomb.C
  pairPotential/derived/dampedCoulomb/dampedCoulomb.C
  pairPotential/derived/exponentialRepulsion/exponentialRepulsion.C
  pairPotential/derived/lennardJones/lennardJones.C
  pairPotential/derived/maitlandSmith/maitlandSmith.C
  pairPotential/derived/noInteraction/noInteraction.C
  pairPotential/pairPotentialList/pairPotentialList.C
  potential/potential.C
  tetherPotential/basic/tetherPotential.C
  tetherPotential/basic/tetherPotentialNew.C
  tetherPotential/derived/harmonicSpring/harmonicSpring.C
  tetherPotential/derived/pitchForkRing/pitchForkRing.C
  tetherPotential/derived/restrainedHarmonicSpring/restrainedHarmonicSpring.C
  tetherPotential/tetherPotentialList/tetherPotentialList.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  electrostaticPotential/electrostaticPotential.H
  energyScalingFunction/basic/energyScalingFunction.H
  energyScalingFunction/derived/doubleSigmoid/doubleSigmoid.H
  energyScalingFunction/derived/noScaling/noScaling.H
  energyScalingFunction/derived/shifted/shifted.H
  energyScalingFunction/derived/shiftedForce/shiftedForce.H
  energyScalingFunction/derived/sigmoid/sigmoid.H
  pairPotential/basic/pairPotential.H
  pairPotential/basic/pairPotentialI.H
  pairPotential/derived/azizChen/azizChen.H
  pairPotential/derived/coulomb/coulomb.H
  pairPotential/derived/dampedCoulomb/dampedCoulomb.H
  pairPotential/derived/exponentialRepulsion/exponentialRepulsion.H
  pairPotential/derived/lennardJones/lennardJones.H
  pairPotential/derived/maitlandSmith/maitlandSmith.H
  pairPotential/derived/noInteraction/noInteraction.H
  pairPotential/pairPotentialList/pairPotentialList.H
  pairPotential/pairPotentialList/pairPotentialListI.H
  potential/potential.H
  potential/potentialI.H
  tetherPotential/basic/tetherPotential.H
  tetherPotential/derived/harmonicSpring/harmonicSpring.H
  tetherPotential/derived/pitchForkRing/pitchForkRing.H
  tetherPotential/derived/restrainedHarmonicSpring/restrainedHarmonicSpring.H
  tetherPotential/tetherPotentialList/tetherPotentialList.H
  tetherPotential/tetherPotentialList/tetherPotentialListI.H
)
install( TARGETS potential )
