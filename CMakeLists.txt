cmake_minimum_required(VERSION 3.24)

project( "OpenFOAM"
  VERSION 11.0
  DESCRIPTION "OpenFOAM is a free, open source computational fluid dynamics (CFD) software package released by the OpenFOAM Foundation. It has a large user base across most areas of engineering and science, from both commercial and academic organisations. OpenFOAM has an extensive range of features to solve anything from complex fluid flows involving chemical reactions, turbulence and heat transfer, to solid dynamics and electromagnetics."
  LANGUAGES C CXX
)

# C++14
set( CMAKE_CXX_STANDARD 14 )

# get git commit
execute_process(
  COMMAND git log -1 --format=%h
  WORKING_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}
  OUTPUT_VARIABLE GIT_COMMIT
  OUTPUT_STRIP_TRAILING_WHITESPACE
)

include(CMakeDependentOption)

cmake_dependent_option( OF_SINGLE_PRECISION "Single Precision Calculations" ON "NOT OF_LONG_PRECISION AND NOT OF_DOUBLE_PRECISION" OFF )
cmake_dependent_option( OF_DOUBLE_PRECISION "Double Precision Calculations" ON "NOT OF_LONG_PRECISION AND NOT OF_SINGLE_PRECISION" OFF )
cmake_dependent_option( OF_LONG_PRECISION "Long Precision Calculations" ON "NOT OF_DOUBLE_PRECISION AND NOT OF_SINGLE_PRECISION" OFF )
if( OF_SINGLE_PRECISION )
  add_definitions( -DWM_SP )
endif()
if( OF_DOUBLE_PRECISION )
  add_definitions( -DWM_DP )
endif()
if( OF_LONG_PRECISION )
  add_definitions( -DWM_LP )
endif()

option( NO_REPOSITORY "UNKNOWN OPTION. LEAVE ENABLED FOR NOW" ON )
if( NO_REPOSITORY )
  add_definitions( -DNoRepository )
endif()

option( BUILD_SHARED_LIBS "Enable building shared libraries" ON)
set( CMAKE_POSITION_INDEPENDENT_CODE ON )
add_compile_options(
  -Wall
  -Wextra
  -Wold-style-cast
  -Wnon-virtual-dtor
  -Wno-unused-parameter
  -Wno-invalid-offsetof
  -ftemplate-depth-100
)
set( WM_LABEL_SIZE 32 CACHE STRING "Label size")
add_definitions( -DWM_LABEL_SIZE=${WM_LABEL_SIZE} )

set(FOAM_USE_INOTIFY ON)

# Flag for running Flex. Currently just specifying C++ as language
set( FLEX_FLAGS "--c++" )

enable_testing()

# add projects module path
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# mandatory dependencies
find_package( Gzstream REQUIRED )
find_package( FLEX REQUIRED )
find_package( ZLIB REQUIRED )
find_package( Boost REQUIRED COMPONENTS thread system )
find_package( Threads REQUIRED )
find_package( CGAL REQUIRED )

# optional dependencies
find_package( MPI )
find_package( METIS )
find_package( GKLIB ) # needed for METIS
find_package( PTSCOTCH )
find_package( Zoltan )
find_package( MGRIDGEN )
find_package( VTK )
find_package( ParaView ) # FIX does not seem to work

# proprietary optional dependencies
find_package( TECIO )
find_package( CCMIO 2.6.1 )

add_subdirectory(src)
add_subdirectory(applications)
add_subdirectory(bin)

