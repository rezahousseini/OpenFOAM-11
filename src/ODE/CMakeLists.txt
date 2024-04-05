add_library( ODE )
target_link_libraries( ODE
  PRIVATE
  OpenFOAM
)
target_include_directories( ODE
  PUBLIC
  .
)
target_sources( ODE
  PRIVATE
  ODESolvers/Euler/Euler.C
  ODESolvers/EulerSI/EulerSI.C
  ODESolvers/ODESolver/ODESolver.C
  ODESolvers/ODESolver/ODESolverNew.C
  ODESolvers/RKCK45/RKCK45.C
  ODESolvers/RKDP45/RKDP45.C
  ODESolvers/RKF45/RKF45.C
  ODESolvers/Rosenbrock12/Rosenbrock12.C
  ODESolvers/Rosenbrock23/Rosenbrock23.C
  ODESolvers/Rosenbrock34/Rosenbrock34.C
  ODESolvers/SIBS/SIBS.C
  ODESolvers/SIBS/SIMPR.C
  ODESolvers/SIBS/polyExtrapolate.C
  ODESolvers/Trapezoid/Trapezoid.C
  ODESolvers/adaptiveSolver/adaptiveSolver.C
  ODESolvers/rodas23/rodas23.C
  ODESolvers/rodas34/rodas34.C
  ODESolvers/seulex/seulex.C
  ODESystem/ODESystem.C

  PRIVATE
  FILE_SET HEADERS
  FILES
  ODESolvers/Euler/Euler.H
  ODESolvers/EulerSI/EulerSI.H
  ODESolvers/ODESolver/ODESolver.H
  ODESolvers/ODESolver/ODESolverI.H
  ODESolvers/RKCK45/RKCK45.H
  ODESolvers/RKDP45/RKDP45.H
  ODESolvers/RKF45/RKF45.H
  ODESolvers/Rosenbrock12/Rosenbrock12.H
  ODESolvers/Rosenbrock23/Rosenbrock23.H
  ODESolvers/Rosenbrock34/Rosenbrock34.H
  ODESolvers/SIBS/SIBS.H
  ODESolvers/Trapezoid/Trapezoid.H
  ODESolvers/adaptiveSolver/adaptiveSolver.H
  ODESolvers/rodas23/rodas23.H
  ODESolvers/rodas34/rodas34.H
  ODESolvers/seulex/seulex.H
  ODESystem/ODESystem.H
)
install( TARGETS ODE )
