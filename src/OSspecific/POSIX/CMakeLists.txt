add_library( OSspecific )
target_link_libraries( OSspecific
  PRIVATE
  ${Inotify_LIBRARIES}
)
target_include_directories( OSspecific
  PUBLIC
  .
  PRIVATE
  $<TARGET_PROPERTY:OpenFOAM,INCLUDE_DIRECTORIES> # break cyclic dependency with target OpenFOAM
)
target_sources( OSspecific
  PRIVATE
  POSIX.C
  clockTime/clockTime.C
  cpuTime/cpuTime.C
  fileMonitor.C
  fileStat.C
  memInfo/memInfo.C
  regExp.C
  signals/sigFpe.C
  signals/sigInt.C
  signals/sigQuit.C
  signals/sigSegv.C
  signals/sigStopAtWriteNow.C
  signals/sigWriteNow.C
  timer.C
  $<IF:$<PLATFORM_ID:SunOS64>,dummyPrintStack.C,printStack.C>

  PRIVATE
  FILE_SET HEADERS
  FILES
  POSIX.H
  clockTime/clockTime.H
  cpuTime/cpuTime.H
  fileMonitor.H
  fileStat.H
  memInfo/memInfo.H
  regExp.H
  signals/sigFpe.H
  signals/sigInt.H
  signals/sigQuit.H
  signals/sigSegv.H
  signals/sigStopAtWriteNow.H
  signals/sigWriteNow.H
  timer.H
)
install( TARGETS OSspecific )
