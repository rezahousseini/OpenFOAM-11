# - Try to find tecio
# Once done this will define
#  TECIO_FOUND - System has tecio
#  TECIO_INCLUDE_DIRS - The tecio include directories
#  TECIO_LIBRARIES - The libraries needed to use tecio
#  TECIO_DEFINITIONS - Compiler switches required for using tecio

find_package(PkgConfig)
pkg_check_modules(TECIO QUIET tecio)
set(TECIO_DEFINITIONS ${TECIO_CFLAGS_OTHER})

find_path(TECIO_INCLUDE_DIR TECIO.h)

find_library(TECIO_LIBRARY 
             NAMES tecio
	     HINTS ${TECIO_LIBDIR} ${TECIO_LIB_DIR} 
	     )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set TECIO_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(TECIO  DEFAULT_MSG
                                  TECIO_LIBRARY TECIO_INCLUDE_DIR)

mark_as_advanced(TECIO_INCLUDE_DIR TECIO_LIBRARY)

set(TECIO_LIBRARIES ${TECIO_LIBRARY} )
set(TECIO_INCLUDE_DIRS ${TECIO_INCLUDE_DIR} )

