################################################################################
# Project file for the Voreen-Qt library
################################################################################
PROJECT(voreen_qt)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.0 FATAL_ERROR)
INCLUDE(../../cmake/commonconf.cmake)

MESSAGE(STATUS "Configuring voreen_qt Library")

# please insert new files in alphabetical order!
SET(VRN_QT_SOURCES 
    aboutbox.cpp 
    helpbrowser.cpp 
    progressdialog.cpp
    versionqt.cpp 
    voreenapplicationqt.cpp
    voreenmoduleqt.cpp
    
    widgets/choicelistcombobox.cpp
    widgets/clickablelabel.cpp
    widgets/codeedit.cpp
    widgets/consoleplugin.cpp
    widgets/customlabel.cpp
    widgets/enterexitpushbutton.cpp
    widgets/eventpropertywidget.cpp
    widgets/expandableheaderbutton.cpp
    widgets/glslhighlighter.cpp
    widgets/inputmappingdialog.cpp
    widgets/keydetectorwidget.cpp
    widgets/lightwidget.cpp
    widgets/lineeditresetwidget.cpp
    widgets/processorlistwidget.cpp
    widgets/propertylistwidget.cpp
    widgets/propertyselectiondialog.cpp
    widgets/rawvolumewidget.cpp
    widgets/rendertargetviewer.cpp
    widgets/shaderplugin.cpp
    widgets/sliderspinboxwidget.cpp
    widgets/screenshotplugin.cpp
    widgets/stringselectiondialog.cpp
    widgets/syntaxhighlighter.cpp
    widgets/volumeiohelper.cpp
    widgets/volumelistingdialog.cpp
    widgets/volumereaderselectiondialog.cpp
    widgets/volumeviewer.cpp
    widgets/volumeviewhelper.cpp
    widgets/voreensettingsdialog.cpp
    widgets/voreentoolwindow.cpp
    
    widgets/animation/animationeditor.cpp
    widgets/animation/animationexportwidget.cpp
    widgets/animation/currentframegraphicsitem.cpp
    widgets/animation/keyframegraphicsitem.cpp
    widgets/animation/nodechainwidget.cpp
    widgets/animation/overviewwidget.cpp
    widgets/animation/processortimelinewidget.cpp
    widgets/animation/propertytimelineview.cpp
    widgets/animation/propertytimelinewidget.cpp
    widgets/animation/templatepropertytimelinewidget.cpp
    widgets/animation/timelinewidget.cpp
    
    widgets/processor/qprocessorwidget.cpp
    
    widgets/property/boolpropertywidget.cpp
    widgets/property/buttonpropertywidget.cpp
    widgets/property/camerapropertywidget.cpp
    widgets/property/camerawidget.cpp
    widgets/property/colorpropertywidget.cpp
    widgets/property/corepropertywidgetfactory.cpp
    widgets/property/filedialogpropertywidget.cpp
    widgets/property/floatmat2propertywidget.cpp
    widgets/property/floatmat3propertywidget.cpp
    widgets/property/floatmat4propertywidget.cpp
    widgets/property/floatpropertywidget.cpp
    widgets/property/floatvec2propertywidget.cpp
    widgets/property/floatvec3propertywidget.cpp
    widgets/property/floatvec4propertywidget.cpp
    widgets/property/fontpropertywidget.cpp
    widgets/property/intpropertywidget.cpp
    widgets/property/intvec2propertywidget.cpp
    widgets/property/intvec3propertywidget.cpp
    widgets/property/intvec4propertywidget.cpp
    widgets/property/lightpropertywidget.cpp
    widgets/property/matrixpropertywidget.cpp
    widgets/property/optionpropertywidget.cpp
    widgets/property/processorpropertieswidget.cpp
    widgets/property/propertyownerwidget.cpp
    widgets/property/propertyvectorwidget.cpp
    widgets/property/qpropertywidget.cpp
    widgets/property/qpropertywidgetwitheditorwindow.cpp
    widgets/property/shaderpropertywidget.cpp
    widgets/property/stringexpressionpropertywidget.cpp
    widgets/property/stringpropertywidget.cpp
    widgets/property/grouppropertywidget.cpp
    widgets/property/transfuncpropertywidget.cpp
    widgets/property/vecpropertywidget.cpp
    widgets/property/voxeltypepropertywidget.cpp
    widgets/property/volumeurlpropertywidget.cpp
    widgets/property/volumeurllistpropertywidget.cpp
    
    widgets/transfunc/colorluminancepicker.cpp
    widgets/transfunc/colorpicker.cpp
    widgets/transfunc/doubleslider.cpp
    widgets/transfunc/histogrampainter.cpp
    widgets/transfunc/transfunceditor.cpp
    widgets/transfunc/transfunc1dkeyseditor.cpp
	widgets/transfunc/transfunc1dkeyspainter.cpp
    widgets/transfunc/transfunc1drampeditor.cpp
	widgets/transfunc/transfunc2dprimitiveseditor.cpp
	widgets/transfunc/transfunc2dprimitivespainter.cpp
    widgets/transfunc/transfuncmappingcanvas.cpp
    widgets/transfunc/transfuncmappingcanvasramp.cpp
    widgets/transfunc/transfuncplugin.cpp
    
    ../../ext/tgt/qt/qtcanvas.cpp
    ../../ext/tgt/qt/qttimer.cpp
)

# headers
SET(VRN_QT_HEADERS
    ../../include/voreen/qt/aboutbox.h
    ../../include/voreen/qt/helpbrowser.h
    
    ../../include/voreen/qt/widgets/clickablelabel.h
    ../../include/voreen/qt/widgets/codeedit.h
    ../../include/voreen/qt/widgets/consoleplugin.h
    ../../include/voreen/qt/widgets/customlabel.h
    ../../include/voreen/qt/widgets/enterexitpushbutton.h
    ../../include/voreen/qt/widgets/eventpropertywidget.h
    ../../include/voreen/qt/widgets/expandableheaderbutton.h
    ../../include/voreen/qt/widgets/inputmappingdialog.h
    ../../include/voreen/qt/widgets/keydetectorwidget.h
    ../../include/voreen/qt/widgets/lightwidget.h
    ../../include/voreen/qt/widgets/lineeditresetwidget.h
    ../../include/voreen/qt/widgets/processorlistwidget.h
    ../../include/voreen/qt/widgets/propertylistwidget.h
    ../../include/voreen/qt/widgets/propertyselectiondialog.h
    ../../include/voreen/qt/widgets/rawvolumewidget.h
    ../../include/voreen/qt/widgets/rendertargetviewer.h
    ../../include/voreen/qt/widgets/shaderplugin.h
    ../../include/voreen/qt/widgets/sliderspinboxwidget.h
    ../../include/voreen/qt/widgets/screenshotplugin.h
    ../../include/voreen/qt/widgets/stringselectiondialog.h
    ../../include/voreen/qt/widgets/volumeiohelper.h
    ../../include/voreen/qt/widgets/volumelistingdialog.h
    ../../include/voreen/qt/widgets/volumereaderselectiondialog.h
    ../../include/voreen/qt/widgets/volumeviewer.h
    ../../include/voreen/qt/widgets/voreensettingsdialog.h
    ../../include/voreen/qt/widgets/voreentoolwindow.h
    
    ../../include/voreen/qt/widgets/animation/animationeditor.h
    ../../include/voreen/qt/widgets/animation/animationexportwidget.h
    ../../include/voreen/qt/widgets/animation/keyframegraphicsitem.h
    ../../include/voreen/qt/widgets/animation/nodechainwidget.h
    ../../include/voreen/qt/widgets/animation/overviewwidget.h
    ../../include/voreen/qt/widgets/animation/processortimelinewidget.h
    ../../include/voreen/qt/widgets/animation/propertytimelineview.h
    ../../include/voreen/qt/widgets/animation/propertytimelinewidget.h
    ../../include/voreen/qt/widgets/animation/timelinewidget.h
    
    ../../include/voreen/qt/widgets/processor/qprocessorwidget.h
    
    ../../include/voreen/qt/widgets/property/boolpropertywidget.h
    ../../include/voreen/qt/widgets/property/buttonpropertywidget.h
    ../../include/voreen/qt/widgets/property/camerapropertywidget.h
    ../../include/voreen/qt/widgets/property/camerawidget.h
    ../../include/voreen/qt/widgets/property/colorpropertywidget.h
    ../../include/voreen/qt/widgets/property/filedialogpropertywidget.h
    ../../include/voreen/qt/widgets/property/floatmat2propertywidget.h
    ../../include/voreen/qt/widgets/property/floatmat3propertywidget.h
    ../../include/voreen/qt/widgets/property/floatmat4propertywidget.h
    ../../include/voreen/qt/widgets/property/floatpropertywidget.h
    ../../include/voreen/qt/widgets/property/floatvec2propertywidget.h
    ../../include/voreen/qt/widgets/property/floatvec3propertywidget.h
    ../../include/voreen/qt/widgets/property/floatvec4propertywidget.h
    ../../include/voreen/qt/widgets/property/fontpropertywidget.h
    ../../include/voreen/qt/widgets/property/intpropertywidget.h
    ../../include/voreen/qt/widgets/property/intvec2propertywidget.h
    ../../include/voreen/qt/widgets/property/intvec3propertywidget.h
    ../../include/voreen/qt/widgets/property/intvec4propertywidget.h
    ../../include/voreen/qt/widgets/property/lightpropertywidget.h
    ../../include/voreen/qt/widgets/property/matrixpropertywidget.h
    ../../include/voreen/qt/widgets/property/optionpropertywidget.h
    ../../include/voreen/qt/widgets/property/processorpropertieswidget.h
    ../../include/voreen/qt/widgets/property/propertyownerwidget.h
    ../../include/voreen/qt/widgets/property/propertyvectorwidget.h
    ../../include/voreen/qt/widgets/property/qpropertywidget.h
    ../../include/voreen/qt/widgets/property/shaderpropertywidget.h
    ../../include/voreen/qt/widgets/property/stringexpressionpropertywidget.h
    ../../include/voreen/qt/widgets/property/stringpropertywidget.h
    ../../include/voreen/qt/widgets/property/grouppropertywidget.h
    ../../include/voreen/qt/widgets/property/transfuncpropertywidget.h
    ../../include/voreen/qt/widgets/property/voxeltypepropertywidget.h
    ../../include/voreen/qt/widgets/property/volumeurllistpropertywidget.h
    ../../include/voreen/qt/widgets/property/volumeurlpropertywidget.h
    
    ../../include/voreen/qt/widgets/transfunc/colorluminancepicker.h
    ../../include/voreen/qt/widgets/transfunc/colorpicker.h
    ../../include/voreen/qt/widgets/transfunc/doubleslider.h
    ../../include/voreen/qt/widgets/transfunc/histogrampainter.h
    ../../include/voreen/qt/widgets/transfunc/transfunceditor.h
    ../../include/voreen/qt/widgets/transfunc/transfunc1dkeyseditor.h
    ../../include/voreen/qt/widgets/transfunc/transfunc1drampeditor.h
    ../../include/voreen/qt/widgets/transfunc/transfunc2dprimitiveseditor.h
    ../../include/voreen/qt/widgets/transfunc/transfunc2dprimitivespainter.h
    ../../include/voreen/qt/widgets/transfunc/transfuncmappingcanvas.h
    ../../include/voreen/qt/widgets/transfunc/transfuncmappingcanvasramp.h
    ../../include/voreen/qt/widgets/transfunc/transfuncplugin.h
)

# headers that do not need to run through moc
SET(VRN_QT_HEADERS_NONMOC
    ../../include/voreen/qt/voreenqtapi.h
    ../../include/voreen/qt/voreenmoduleqt.h
    ../../include/voreen/qt/voreenapplicationqt.h
    ../../include/voreen/qt/progressdialog.h
    ../../include/voreen/qt/versionqt.h
    
    ../../include/voreen/qt/widgets/choicelistcombobox.h
    ../../include/voreen/qt/widgets/glslhighlighter.h
    ../../include/voreen/qt/widgets/syntaxhighlighter.h
    ../../include/voreen/qt/widgets/volumeviewhelper.h    

    ../../include/voreen/qt/widgets/animation/currentframegraphicsitem.h
    ../../include/voreen/qt/widgets/animation/templatepropertytimelinewidget.h
    
    ../../include/voreen/qt/widgets/property/corepropertywidgetfactory.h
    ../../include/voreen/qt/widgets/property/qpropertywidgetwitheditorwindow.h
    ../../include/voreen/qt/widgets/property/vecpropertywidget.h
    
    ../../include/voreen/qt/widgets/transfunc/transfunc1dkeyspainter.h
    
    ../../ext/tgt/qt/qtcanvas.h
    ../../ext/tgt/qt/qttimer.h
)

# add module sources and headers
LIST(APPEND VRN_QT_SOURCES ${VRN_MODULE_QT_SOURCES})
LIST(APPEND VRN_QT_HEADERS ${VRN_MODULE_QT_HEADERS})
LIST(APPEND VRN_QT_HEADERS_NONMOC ${VRN_MODULE_QT_HEADERS_NONMOC})

# find Qt library
FIND_PACKAGE(Qt4 ${VRN_REQUIRED_QT_VERSION} REQUIRED QtCore QtGui QtOpenGL QtXml QtNetwork QtSvg)
IF(WIN32)
    FIND_PACKAGE(Qt4DLLsVRN COMPONENTS QtCore QtGui QtOpenGL QtXml QtNetwork QtSvg)
    IF(QT_DLLS_FOUND)
        SET(VRN_EXTERNAL_DEBUG_DLLS   ${VRN_EXTERNAL_DEBUG_DLLS}   ${QT_DEBUG_DLLS}   PARENT_SCOPE)
        SET(VRN_EXTERNAL_RELEASE_DLLS ${VRN_EXTERNAL_RELEASE_DLLS} ${QT_RELEASE_DLLS} PARENT_SCOPE)
    ELSE()
        MESSAGE(WARNING "Qt DLLs not found")
    ENDIF()
ENDIF()


################################################################################
# generate module registration header
################################################################################
SET(REGISTRATION_FILE "${CMAKE_BINARY_DIR}/gen_moduleregistration_qt.h" )
MESSAGE(STATUS "* Generating module registration header ${REGISTRATION_FILE}")

SET(REGISTRATION_SOURCE "// WARNING: This file is generated and will be overwritten on next cmake run!\n" )
LIST(APPEND REGISTRATION_SOURCE "#include \"voreen/qt/voreenapplicationqt.h\"\n\n" )
LIST(APPEND REGISTRATION_SOURCE "// include qt module class headers\n" )
FOREACH(inc ${VRN_MODULE_QT_MODULECLASSES_INCLUDES})
    LIST(APPEND REGISTRATION_SOURCE "#include \"${inc}\"\n" )
ENDFOREACH()
LIST(APPEND REGISTRATION_SOURCE "\nnamespace voreen {\n" )
LIST(APPEND REGISTRATION_SOURCE "\n// instantiate qt module classes\n" )
LIST(APPEND REGISTRATION_SOURCE "void registerAllQtModules(VoreenApplicationQt* vappQt) {\n" )
IF(VRN_MODULE_QT_MODULECLASSES)
    LIST(APPEND REGISTRATION_SOURCE "    VoreenModuleQt* module\;\n\n")
    LIST(LENGTH VRN_MODULE_QT_MODULECLASSES num_modules)
    MATH(EXPR max_index "${num_modules} - 1")
    FOREACH(i RANGE ${max_index})
        LIST(GET VRN_MODULE_QT_MODULECLASSES ${i} class)
        LIST(GET VRN_MODULE_QT_MODULECLASSES_INCLUDES ${i} inc)
        FILE(RELATIVE_PATH inc_rel ${VRN_HOME} ${inc})
        GET_FILENAME_COMPONENT(mod_path_rel ${inc_rel} PATH)
        LIST(APPEND REGISTRATION_SOURCE "    module = new ${class}(\"${mod_path_rel}\")\;\n")
        LIST(APPEND REGISTRATION_SOURCE "    vappQt->registerQtModule(module)\;\n\n")
    ENDFOREACH()
ENDIF()
LIST(APPEND REGISTRATION_SOURCE "}\n\n" )
LIST(APPEND REGISTRATION_SOURCE "} // namespace\n" )

FILE(WRITE ${REGISTRATION_FILE} ${REGISTRATION_SOURCE})
LIST(APPEND VRN_QT_HEADERS_NONMOC ${REGISTRATION_FILE})


################################################################################
# define library target
################################################################################

# Qt moc
QT4_WRAP_CPP(VRN_QT_MOC_SOURCES ${VRN_QT_HEADERS})
LIST(APPEND VRN_QT_SOURCES ${VRN_QT_MOC_SOURCES})

# Qt ui and resources
QT4_WRAP_UI(VRN_QT_FORMS_HEADERS aboutbox.ui)
QT4_ADD_RESOURCES(VRN_QT_RESOURCES_RCC vrn_qt.qrc)

# add msvc pch
IF (VRN_PRECOMPILED_HEADER AND MSVC)
    ADD_MSVC_PRECOMPILED_HEADER(pch_qt.h pch_qt.cpp VRN_QT_SOURCES)
ENDIF()

# define target
ADD_LIBRARY(voreen_qt 
    ${VRN_QT_SOURCES} ${VRN_QT_HEADERS} ${VRN_QT_HEADERS_NONMOC} 
    ${VRN_QT_RESOURCES_RCC} 
    ${VRN_QT_FORMS_HEADERS}) 
ADD_DEFINITIONS(${VRN_DEFINITIONS} ${VRN_MODULE_DEFINITIONS})
IF(VRN_SHARED_LIBS AND MSVC)
    ADD_DEFINITIONS("-DVRN_QT_BUILD_DLL")
ENDIF()
INCLUDE_DIRECTORIES(${VRN_INCLUDE_DIRECTORIES} ${VRN_MODULE_INCLUDE_DIRECTORIES})
TARGET_LINK_LIBRARIES(voreen_qt tgt voreen_core ${VRN_EXTERNAL_LIBRARIES})

# add Qt dependency
INCLUDE(${QT_USE_FILE})
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_BINARY_DIR}) #< location of generated ui headers in out-of-source builds
ADD_DEFINITIONS(${QT_DEFINITIONS})
TARGET_LINK_LIBRARIES(voreen_qt ${QT_LIBRARIES})

# add gcc pch
IF (VRN_PRECOMPILED_HEADER AND CMAKE_COMPILER_IS_GNUCXX)
    ADD_GCC_PRECOMPILED_HEADER(voreen_qt pch_qt.h)
ENDIF()

################################################################################
# deployment
################################################################################
IF(VRN_ADD_INSTALL_TARGET)
    INSTALL(TARGETS voreen_qt
        RUNTIME DESTINATION .
    )
ENDIF()
