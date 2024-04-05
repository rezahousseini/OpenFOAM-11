# - Try to find MGridGen
# Once done this will define
#  MGRIDGEN_FOUND - System has MGRIDGEN
#  MGRIDGEN_INCLUDE_DIRS - The MGRIDGEN include directories
#  MGRIDGEN_LIBRARIES - The libraries needed to use MGRDIGEN
#  MGRIDGEN_DEFINITIONS - Compiler switches required for using MGRIDGEN

find_package(PkgConfig)
pkg_check_modules(MGRIDGEN QUIET mgridgen)
set(ZOLTAN_DEFINITIONS ${MGRIDGEN_CFLAGS_OTHER})

find_path(MGRIDGEN_INCLUDE_DIR mgridgen.h
          PATHS /usr/include /usr/local/include
          )

find_library(MGRIDGEN_LIBRARY 
             NAMES mgridgen
	     HINTS ${MGRIDGEN_LIBDIR} ${MGRIDGEN_LIB_DIR} 
	     )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set MGRIDGEN_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(MGridGen DEFAULT_MSG
                                  MGRIDGEN_LIBRARY MGRIDGEN_INCLUDE_DIR)

mark_as_advanced(MGRIDGEN_INCLUDE_DIR MGRIDGEN_LIBRARY )

set(MGRIDGEN_LIBRARIES ${MGRIDGEN_LIBRARY} )
set(MGRIDGEN_INCLUDE_DIRS ${MGRIDGEN_INCLUDE_DIR} )

