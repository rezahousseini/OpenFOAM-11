# - Try to find ccmio
# Once done this will define
#  CCMIO_FOUND - System has ccmio
#  CCMIO_INCLUDE_DIRS - The ccmio include directories
#  CCMIO_LIBRARIES - The libraries needed to use ccmio
#  CCMIO_DEFINITIONS - Compiler switches required for using ccmio

find_package(PkgConfig)
pkg_check_modules(CCMIO QUIET ccmio)
set(CCMIO_DEFINITIONS ${CCMIO_CFLAGS_OTHER})

find_path(CCMIO_INCLUDE_DIR ccmio.h)

find_library(CCMIO_LIBRARY 
             NAMES ccmio
	     HINTS ${CCMIO_LIBDIR} ${CCMIO_LIB_DIR} 
	     )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set CCMIO_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(CCMIO  DEFAULT_MSG
                                  CCMIO_LIBRARY CCMIO_INCLUDE_DIR)

mark_as_advanced(CCMIO_INCLUDE_DIR CCMIO_LIBRARY)

set(CCMIO_LIBRARIES ${CCMIO_LIBRARY} )
set(CCMIO_INCLUDE_DIRS ${CCMIO_INCLUDE_DIR} )

