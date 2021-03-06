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

#ifndef ITIOTBRGBAQGLWIDGETSCROLLABLE_H
#define ITIOTBRGBAQGLWIDGETSCROLLABLE_H

#include <QGLWidget>
#include <QPen>
#include <QWheelEvent>

#include "../itiviewerobserver.h"

#include "../../rgba_globaldefs.h"

//using namespace otb;
using namespace voreen;

namespace itiviewer{

/** \class QOtbImageWidget
*   \brief This class renders an RGB bytes image buffer to the screen.
*   Rendered data can be loaded using the ReadBuffer() method.
*   The SetIsotropicZoom() method allows to tune the zooming (zooming
*   is centered).
*
*   It is also able to display a rectangle on the displayed image.
*
*   This class uses the overpainting on a QGLWidget paradeigm from the Qt examples
*
*  \ingroup Visualization
 */

class ItiOtbRgbaQGLWidgetScrollable : public QGLWidget, public ItiViewerObserver
{
    Q_OBJECT
public:
    explicit ItiOtbRgbaQGLWidgetScrollable(QWidget *parent = 0);

    virtual ~ItiOtbRgbaQGLWidgetScrollable();

    /** Reads the OpenGl buffer from an image pointer
     *  \param image The image pointer,
     *  \param region The region to read.
     *  Potential exception thrown if region is outside of the buffered
     *  region.
     * This method fills the m_OpenGl buffer according to the region
     *  size. Buffer in flipped over X axis if OTB_USE_GL_ACCEL is OFF.
     */
    virtual void ReadBuffer(const RasterImageType * image, const RasterRegionType& region);

    /** Clear the OpenGl buffer */
    void ClearBuffer();

    //! setter getter, self explanatory
    double isotropicZoom() const { return m_IsotropicZoom; }
    void setIsotropicZoom(double z) { m_IsotropicZoom = z; }

    //! setter getter, self explanatory
    unsigned int subSamplingRate() const { return m_SubsamplingRate; }
    void setSubSamplingRate(unsigned int ss) { m_SubsamplingRate = ss; }

    //! setter getter, self explanatory
    unsigned char * openGLBuffer() { return m_OpenGlBuffer;}

    //! setter getter, self explanatory
    RasterRegionType openGLBufferedRegion() { return m_OpenGlBufferedRegion; }
    void setOpenGLBufferedRegion(RasterRegionType r) { m_OpenGlBufferedRegion = r; }

    //! setter getter for the focus region area
    QRect focusRegion() const { return m_focusRegion; }
    void setFocusRegion(const QRect &rect) { m_focusRegion  = rect; }

    //! setter getter, self explanatory
    RasterRegionType extent() { return m_Extent; }

    /*!
     * \brief update , implementation from parent class
     * \param region, the region
     */
    void updateObserver(ItiViewerObservable *observable);

    /*!
     * \brief draw
     */
    void draw();

signals:
    /*!
     * \brief visibleAreaChanged , this signal is emitted uppon the view resizing
     * \param rect
     */
    void visibleAreaChanged(const QRect &rect);

    /*!
     * \brief focusRegionTranslated, this signal is emitted on mouse press events
     * \param dx
     * \param dy
     */
    void focusRegionTranslated(int dx, int dy);

    /*!
     * \brief zoomIn , this signal is emitterd uppon wheel events
     */
    void zoomIn();

    /*!
     * \brief zoomIn , this signal is emitterd uppon wheel events
     */
    void zoomOut();

    /*!
     * \brief currentIndexChanged
     * \param text
     */
    void currentIndexChanged(const QString &text);

protected:

    /*!
     * \brief mousePressEvent
     */
    void wheelEvent(QWheelEvent *);

    /*!
     * \brief initializeGL
     *  reimplemented method declared in the QGLWidget class
     */
    void initializeGL();

    /*!
     * \brief resizeGL , reimplemented method declared in the QGLWidget class
     * \param w , the width parameter
     * \param h , the height parameter
     */
    void resizeGL(int w, int h);

    /*!
     * \brief paintEvent
     * \param event
     */
    void paintEvent(QPaintEvent *event);

    /*!
     * \brief mousePressEvent
     * \param event
     */
    void mousePressEvent(QMouseEvent *event);

    /*!
     * \brief mouseMoveEvent
     * \param event
     */
    void mouseMoveEvent(QMouseEvent *event);

private:
    /*!
     * \brief setupViewport
     * \param width
     * \param height
     */
    void setupViewport(int w, int h);

    /** OpenGl zoom factor */
    double m_IsotropicZoom;

    /** The interpolation method */
    GLint m_InterpolationMethod;

    //! helper values
    GLint m_W, m_H;

    /** OpenGl buffer      */
    unsigned char * m_OpenGlBuffer;

    /** OpenGl buffered region */
    RasterRegionType m_OpenGlBufferedRegion;

    /** The display extent */
    RasterRegionType m_Extent;

    /** If the image is subsampled with respect to the original image,
     * this indicates the subsampling rate */
    unsigned int m_SubsamplingRate;

    /*!
     * \brief m_pen
     */
    QPen m_pen;

    /*!
     * \brief m_focusRegion, this rectangle is synchronized with the windows of the zoom view
     *  This rectangle is a helper variable in order to full setup the observer mechanism between
     *  An observalble region and the observer classes which in this case are the views(scrollable,zoombable,full view)
     */
    QRect m_focusRegion;

};

} // end of itiviewer

#endif // ITIOTBRGBAQGLWIDGETSCROLLABLE_H
