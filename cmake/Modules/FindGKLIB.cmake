# - Try to find GKlib
# Once done this will define
#  GKLIB_FOUND - System has GKlib
#  GKLIB_INCLUDE_DIRS - The GKlib include directories
#  GKLIB_LIBRARIES - The libraries needed to use GKlib
#  GKLIB_DEFINITIONS - Compiler switches required for using GKlib

find_package(PkgConfig)
pkg_check_modules(GKLIB QUIET GKlib)
set(GKLIB_DEFINITIONS ${GKLIB_CFLAGS_OTHER})

find_path(GKLIB_INCLUDE_DIR GKlib.h)

find_library(GKLIB_LIBRARY 
             NAMES GKlib
	     HINTS ${GKLIB_LIBDIR} ${GKLIB_LIB_DIR} 
	     )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set GKLIB_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(GKLIB  DEFAULT_MSG
                                  GKLIB_LIBRARY GKLIB_INCLUDE_DIR)

mark_as_advanced(GKLIB_INCLUDE_DIR GKLIB_LIBRARY)

set(GKLIB_LIBRARIES ${GKLIB_LIBRARY} )
set(GKLIB_INCLUDE_DIRS ${GKLIB_INCLUDE_DIR} )

