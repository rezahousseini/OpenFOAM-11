add_library( randomProcesses )
target_link_libraries( randomProcesses
  PRIVATE
  OpenFOAM
  sampling

  PUBLIC
  finiteVolume
)
target_include_directories( randomProcesses
  PUBLIC
  .
)
target_sources( randomProcesses
  PRIVATE
  Kmesh/Kmesh.C
  fft/fft.C
  fft/fftRenumber.C
  fft/kShellIntegration.C
  fft/writeEk.C
  noise/noiseFFT.C
  processes/UOprocess/UOprocess.C
  turbulence/turbGen.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  Kmesh/Kmesh.H
  fft/fft.H
  fft/fftRenumber.H
  fft/kShellIntegration.H
  fft/writeEk.H
  noise/noiseFFT.H
  processes/UOprocess/UOprocess.H
  turbulence/Ek.H
  turbulence/turbGen.H
)
install( TARGETS randomProcesses )
