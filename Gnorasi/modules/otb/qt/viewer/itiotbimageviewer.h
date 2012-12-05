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

#ifndef ITIOTBIMAGEVIEWER_H
#define ITIOTBIMAGEVIEWER_H

#include <QWidget>
#include <QLabel>

#include "itkImage.h"


namespace itiviewer{

/*!
 * \brief The ITIImageViewer class
 *
 * \class The ITIImageViewer class is an abstract product that is used by an application
 * where a visualization of images is needed.
 */
class ItiOtbImageViewer : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief The CC enum stands for the Color Composition mode
     */
    enum CC{
        CC_GREYSCALE                                                                    = 0,
        CC_RGBA                                                                         = 1
    };

    /*!
     * \brief The CE enum stands for the Contrast Enhancement method
     */
    enum CE{
        CELINEAR_0_255                                                                  = 0,
        CE_LINEAR_X_PERC                                                                = 1,
        CE_GAUSSIAN                                                                     = 2,
        CE_SQUARE_ROOT                                                                  = 3
    };

    //!
    //! ctor
    //!
    explicit ItiOtbImageViewer(QWidget *parent = 0);

    /*!
     * \brief disassembleWidgets
     *  This is an abstract function needs to be implemented by every concrete subclass
     *  The implementation should contain the functionality to disassemble all viewer's widgets
     *  each sub widget should be a separate window
     */
    virtual void disassembleWidgets()                                                   = 0;

    /*!
     * \brief assembleWidgets
     *  This is an abstract function needs to be implemented by every concrete subclass
     *  The implementation should contain the functionality to assemble all viewer's widgets
     *  into one single window
     */
    virtual void assembleWidgets()                                                      = 0;

    /*!
     * \brief draw
     *  This is a virtual method required for painting stuff
     */
    virtual void draw()                                                                 = 0;

    /*!
     * \brief zoomIn
     *  This is a virtual method for abstracting the zoomin functionality
     */
    virtual void zoomIn()                                                               = 0;

    /*!
     * \brief zoomOut
     *  This is a virtual method for abstracting the zoom out functionality
     */
    virtual void zoomOut()                                                              = 0;

    /*!
     * \brief setGreyScaleColorMode
     *  This is a virtual method for abstracting the setting the color mode functionality
     * \param band,  sets the band channel will be used to draw the image
     */
    virtual void applyGreyScaleColorMode(int band)                                        = 0;

    /*!
     * \brief setRGBColorMode, This is a virtual method for abstracting the setting the color mode functionality
     * \param red, sets the band channel to be used to visualize the red part
     * \param green, sets the band channel to be used to visualize the green part
     * \param blue, sets the band channel to be used to visualize the blue part
     */
    virtual void applyRGBColorMode(int red, int green, int blue)                          = 0;

    /*!
     * \brief setContrastEnhancementMethod, This is a virtual function for abstracting the contrast enhancement method
     * \param ce, sets the method to be set
     * \param aval, sets the lower quantile value or the standard deviation value if the ce param equals to CE_GAUSSIAN
     * \param bval equals to the upper quantile value
     */
    virtual void applyContrastEnhancementMethod(CC ce, double aval, double bval = 0.0)    = 0;

protected:

};

} // namespace itiviewer

#endif // ITIOTBIMAGEVIEWER_H