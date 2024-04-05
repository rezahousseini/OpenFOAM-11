add_library( utilityFunctionObjects )
target_link_libraries( utilityFunctionObjects
  PRIVATE
  OpenFOAM
  finiteVolume
)
target_include_directories( utilityFunctionObjects
  PUBLIC
  .
)
target_sources( utilityFunctionObjects
  PRIVATE
  checkMesh/checkMesh.C
  codedFunctionObject/codedFunctionObject.C
  removeRegisteredObject/removeRegisteredObject.C
  residuals/residuals.C
  setTimeStep/setTimeStepFunctionObject.C
  setWriteInterval/setWriteIntervalFunctionObject.C
  stopAt/stopAt.C
  stopAt/stopAtClockTime/stopAtClockTime.C
  stopAt/stopAtFile/stopAtFile.C
  stopAt/stopAtTimeStep/stopAtTimeStep.C
  systemCall/systemCall.C
  time/timeFunctionObject.C
  timeActivatedFileUpdate/timeActivatedFileUpdate.C
  timeStep/timeStepFunctionObject.C
  writeDictionary/writeDictionary.C
  writeObjects/writeObjects.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  checkMesh/checkMesh.H
  codedFunctionObject/codedFunctionObject.H
  removeRegisteredObject/removeRegisteredObject.H
  residuals/residuals.H
  setTimeStep/setTimeStepFunctionObject.H
  setWriteInterval/setWriteIntervalFunctionObject.H
  stopAt/stopAt.H
  stopAt/stopAtClockTime/stopAtClockTime.H
  stopAt/stopAtFile/stopAtFile.H
  stopAt/stopAtTimeStep/stopAtTimeStep.H
  systemCall/systemCall.H
  time/timeFunctionObject.H
  timeActivatedFileUpdate/timeActivatedFileUpdate.H
  timeStep/timeStepFunctionObject.H
  writeDictionary/writeDictionary.H
  writeObjects/writeObjects.H
)
install( TARGETS utilityFunctionObjects )
