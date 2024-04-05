# - Try to find gzstream
# Once done this will define
#  GZSTREAM_FOUND - System has GZSTREAM
#  GZSTREAM_INCLUDE_DIRS - The GZSTREAM include directories
#  GZSTREAM_LIBRARIES - The libraries needed to use GZSTREAM
#  GZSTREAM_DEFINITIONS - Compiler switches required for using GZSTREAM

find_path(GZSTREAM_INCLUDE_DIR gzstream.h)

find_library(GZSTREAM_LIBRARY 
             NAMES gzstream
	     HINTS ${GZSTREAM_LIBDIR} ${GZSTREAM_LIB_DIR} 
	     )

include(FindPackageHandleStandardArgs)
# handle the QUIETLY and REQUIRED arguments and set GZSTREAM_FOUND to TRUE
# if all listed variables are TRUE
find_package_handle_standard_args(Gzstream  DEFAULT_MSG
                                  GZSTREAM_LIBRARY GZSTREAM_INCLUDE_DIR)

mark_as_advanced(GZSTREAM_INCLUDE_DIR GZSTREAM_LIBRARY)

set(GZSTREAM_LIBRARIES ${GZSTREAM_LIBRARY} )
set(GZSTREAM_INCLUDE_DIRS ${GZSTREAM_INCLUDE_DIR} )

