if( ${ParaView_FOUND} )
add_subdirectory( vtkPVFoam )
add_subdirectory( vtkPVblockMesh )

INCLUDE(GNUInstallDirs)

SET(BUILD_SHARED_LIBS ON)

PARAVIEW_PLUGIN_SCAN(
    PLUGIN_FILES
        "PVblockMeshReader/paraview.plugin"
        "PVFoamReader/paraview.plugin"
    PROVIDES_PLUGINS plugins
    ENABLE_BY_DEFAULT ON
)

PARAVIEW_PLUGIN_BUILD(PLUGINS ${plugins})
endif()
