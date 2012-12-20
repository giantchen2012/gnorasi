/********************************************************************************
 *                                                                              *
 * GNORASI - The Knowlegde-Based Remote Sensing Engine                          *
 *                                                                              *
 * Language:  C++                                                               *
 *                                                                              *
 * Copyright (c) Ioannis Tsampoulatidis <itsam@iti.gr>. All rights reserved. 	*
 * Copyright (c) Informatics and Telematics Institute                           *
 *	  Centre for Research and Technology Hellas. All rights reserved.           *
 * Copyright (c) National Technical University of Athens. All rights reserved.	*
 *                                                                              *
 *                                                                              *
 * This file is part of the GNORASI software package. GNORASI is free           *
 * software: you can redistribute it and/or modify it under the terms           *
 * of the GNU General Public License version 2 as published by the              *
 * Free Software Foundation.                                                    *
 *                                                                              *
 * GNORASI is distributed in the hope that it will be useful,                   *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of               *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                 *
 * GNU General Public License for more details.                                 *
 *                                                                              *
 * You should have received a copy of the GNU General Public License            *
 * in the file "LICENSE.txt" along with this program.                           *
 * If not, see <http://www.gnu.org/licenses/>.                                  *
 *                                                                              *
 ********************************************************************************/

#ifndef ITIOTBRGBAIMAGEVIEWER_H
#define ITIOTBRGBAIMAGEVIEWER_H

#include <QtCore>
#include <QtGui>
#include <QtOpenGL>
#include <QVBoxLayout>
#include <QSplitter>

#include "itiotbimageviewer.h"

#include "../rgba_globaldefs.h"


namespace itiviewer{

class ItiOtbRgbaQGLWidgetScrollable;
class ItiOtbRgbaQGLWidgetFullView;
class ItiOtbRgbaQGLWidgetZoomable;
class ItiOtbRgbaFocusRegion;
class ItiViewerObservableRegion;
class ItiViewerPixelInfoWidget;

/** \class ITIOTBImageViewer
 *   \brief This class implements a standard visualization tool to be
 *   plugged at the end of a pipeline.
 *  This viewer handles RGBA images coming from ImagePorts which are specialized data IO classes handling OTB Images.
 *
 *  \ingroup Visualization
 *
 */
class ItiOtbRgbaImageViewer : public ItiOtbImageViewer
{
    Q_OBJECT
public:
    explicit ItiOtbRgbaImageViewer(QWidget *parent = 0);

    /*!
     * \brief disassembleWidgets , implementation
     */
    void disassembleWidgets();

    /*!
     * \brief assembleWidgets
     *  implementation
     */
    void assembleWidgets();

    /*!
     * \brief draw
     *  implementation
     */
    void draw();

    /*!
     * \brief applyGreyScaleColorMode , implementation
     * \param band , the grey  scale channel
     */
    void applyGreyScaleColorMode(int band);

    /*!
     * \brief applyRGBColorMode , implementation
     * \param red , red channel
     * \param green , green channel
     * \param blue, blue channel
     */
    void applyRGBColorMode(int red, int green, int blue);

    /*!
     * \brief applyContrastEnhancementMethod , red channel
     * \param ce
     * \param aval
     * \param bval
     */
    void applyContrastEnhancementMethod(CC ce, double aval, double bval);

    /*!
     * \brief costructTextFromImageIndex
     * \param index , the index of the image
     * \return
     */
    static QString constructTextFromImageIndex(RasterIndexType index, RasterImageType* image);


private slots:
    /*!
     * \brief onScrollableWidgetSizeChanged
     * \param size
     */
    void onScrollableWidgetSizeChanged(const QRect &size);

    /*!
     * \brief onZoomableWidgetSizeChanged
     * \param size
     */
    void onZoomableWidgetSizeChanged(const QRect &size);

    /*!
     * \brief onFocusRegionTranslated
     * \param rect
     */
    void onFocusRegionTranslated(const QRect &rect);


private:

    /*!
     * \brief setupConnections , setup the signal and slot mechanims
     */
    void setupConnections();

    /*!
     * \brief setupObserverMechanism
     */
    void setupObserverMechanism();

    /*!
     * \brief setupLayout
     */
    void setupLayout();

    /*!
     * \brief m_pItiOtbRgbaImageWidgetScroll
     *  The scrollable widgets accepts scroll events and has a helper rectangle which sets the focus region
     */
    ItiOtbRgbaQGLWidgetScrollable *m_pItiOtbRgbaImageWidgetScroll;

    /*!
     * \brief m_pItiOtbRgbaImageWidgetFull , The full widget always shows the whole image extents
     */
    ItiOtbRgbaQGLWidgetFullView* m_pItiOtbRgbaImageWidgetFullView;

    /*!
     * \brief m_pItiOtbRgbaImageWidgetZoom
     *  The zoombable widget shows the image in various scales depending on the image zoom properties
     */
    ItiOtbRgbaQGLWidgetZoomable *m_pItiOtbRgbaImageWidgetZoomable;

    /*!
     * \brief m_pvBoxLayoutLeft
     *  The left vertical layout, needed for assembiling and disassembliing purposes
     *  The left layout contain two view widgets the zoomable and the full widget
     *  and the metadata widget.
     */
    QVBoxLayout *m_pvBoxLayoutLeft;

    /*!
     * \brief m_pVboxLayoutRight
     *  The right vertical layout, needed for assembiling and disassembliing purposes
     */
    QVBoxLayout *m_pVboxLayoutRight;

    /*!
     * \brief m_pMainLayout
     *  The main layout, needed for assembiling and disassembliing purposes
     */
    QVBoxLayout *m_pMainLayout;

    /*!
     * \brief m_pSplitter
     *  The horizontal splitter , the view is splitted horizontally..
     */
    QSplitter *m_pSplitter;

    //! the following labels were taken from the monteverdi viewer
    //! a label showing a title for the scrollable resolution view
    QLabel *m_pLabelScrollableResolution;

    /*!
     * \brief m_pLabelNavigationView
     *  a label showing a title for the navigation view
     */
    QLabel *m_pLabelFullView;

    /*!
     * \brief m_pLabelZoomView
     *  a label showing a title for the zoomable view
     */
    QLabel *m_pLabelZoomView;

    /*!
     * \brief m_pMetadataWidget
     *  For the moment , a Container widget
     */
    ItiViewerPixelInfoWidget *m_pItiViewerPixelInfoWidget;

    /*!
     * \brief m_focusRegion
     *  The m_focusRegion region extents equal to the zoomable widget extents, so the zoomable widget
     *  visualizes the content defined by the focus region.
     *  This instance is an observable item
     */
    ItiViewerObservableRegion *m_pFocusRegion;

    /*!
     * \brief m_pVisibleRegion
     *  The visible region extents equal to the visible part of the image shown on the scrollable widget view
     *  This instance is an observable item
     */
    ItiViewerObservableRegion *m_pVisibleRegion;

    /*!
     * \brief m_labelCss
     */
    QString m_labelCss;
    
};

} // end of namespace itiviewer

#endif // ITIOTBRGBAIMAGEVIEWER_H
