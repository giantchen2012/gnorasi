# Try to find Osgeo4W library and include path. Once done this will define:
# OSGeo4W_FOUND
# OSGeo4W_DEFINITIONS
# OSGeo4W_INCLUDE_DIRS
# OSGEO4W_LIBRARIES (containing both debug and release libraries on win32)
# win32: OSGeo4W_DEBUG_LIBRARIES, OSGeo4W_RELEASE_LIBRARIES, OSGeo4W_DEBUG_DLLS, OSGeo4W_RELEASE_DLLS

IF (WIN32)
	SET(OSGeo4W_DIR "${VRN_HOME}/ext/osgeo4w" CACHE PATH "If osgeo4w is not found, set this path")
    
    SET(OSGEO4W_DEFINITIONS "-DOSGEO4W_ALL_NO_LIB")

    SET(OSGeo4W_INCLUDE_DIRS "${OSGeo4W_DIR}/include")

    # set debug and release libraries
    IF(VRN_WIN32)
        IF(VRN_MSVC2008)
            SET(OSGeo4W_LIB_DIR "${OSGeo4W_DIR}/lib/vs2008")
        ELSE()
            SET(OSGeo4W_LIB_DIR "${OSGeo4W_DIR}/lib/win32")
        ENDIF()
    ELSEIF(VRN_WIN64)
        SET(OSGeo4W_LIB_DIR "${OSGeo4W_DIR}/lib/win64")
    ELSE(VRN_WIN32)
        MESSAGE(FATAL_ERROR "Neither VRN_WIN32 nor VRN_WIN64 defined!")
    ENDIF(VRN_WIN32)
	
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/adrg.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/comerr32.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/DevIL.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/dted.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/freexl.dll")
        LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/gdal110.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/geos_c.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/geotiff.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/gssapi32.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/hdf5dll.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/hdf_fw.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/iconv.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/ILU.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/ITKCommon-4.1.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/jpeg12_osgeo.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/jpeg62.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/jpeg_osgeo.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/k5sprt32.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/krb5_32.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libcurl.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libeay32.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libexpat.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libiconv-2.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libintl-8.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libmysql.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libpq.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/libtiff.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/mfhdf_fw.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/msvcp60.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/msvcp70.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/msvcp71.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/msvcr71.dll")
        LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/msvcr90.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/msvcrt.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/netcdf.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/ogdi_32b1.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osg.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgAnimation.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgDB.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgFX.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgGA.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgManipulator.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgParticle.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgPresentation.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgQt.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgShadow.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgSim.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgTerrain.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgText.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgUtil.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgViewer.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgVolume.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/osg80-osgWidget.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/ossim.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/ot12-OpenThreads.dll")
        LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/otbossimplugins.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/proj.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/python27.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/remote.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/rpf.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/skeleton.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/spatialite.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/sqlite3.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/ssleay32.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/szlibdll.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/vrf.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/xerces-c_2_7.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/xerces-c_3_1.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/xerces-depdom_2_7.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/zlib_osgeo.dll")
	LIST(APPEND OSGeo4W_DEBUG_DLLS        "${OSGeo4W_LIB_DIR}/zlib1.dll")
	
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/adrg.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/comerr32.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/DevIL.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/dted.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/freexl.dll")
        LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/gdal110.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/geos_c.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/geotiff.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/gssapi32.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/hdf5dll.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/hdf_fw.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/iconv.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/ILU.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/ITKCommon-4.1.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/jpeg12_osgeo.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/jpeg62.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/jpeg_osgeo.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/k5sprt32.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/krb5_32.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libcurl.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libeay32.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libexpat.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libiconv-2.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libintl-8.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libmysql.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libpq.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/libtiff.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/mfhdf_fw.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/msvcp60.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/msvcp70.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/msvcp71.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/msvcr71.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/msvcr90.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/msvcrt.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/netcdf.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/ogdi_32b1.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osg.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgAnimation.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgDB.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgFX.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgGA.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgManipulator.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgParticle.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgPresentation.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgQt.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgShadow.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgSim.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgTerrain.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgText.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgUtil.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgViewer.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgVolume.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/osg80-osgWidget.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/ossim.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/ot12-OpenThreads.dll")
        LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/otbossimplugins.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/proj.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/python27.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/remote.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/rpf.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/skeleton.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/spatialite.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/sqlite3.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/ssleay32.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/szlibdll.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/vrf.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/xerces-c_2_7.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/xerces-c_3_1.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/xerces-depdom_2_7.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/zlib_osgeo.dll")
	LIST(APPEND OSGeo4W_RELEASE_DLLS      "${OSGeo4W_LIB_DIR}/zlib1.dll")
	
   
    IF(OSGeo4W_DEBUG_DLLS AND OSGeo4W_RELEASE_DLLS)
        SET(OSGeo4W_FOUND TRUE)
    ELSE()
        SET(OSGeo4W_FOUND FALSE)
    ENDIF()

ELSE(WIN32)
    
ENDIF(WIN32)

MARK_AS_ADVANCED(OSGeo4W_DIR OSGeo4W_INCLUDE_DIRS)
