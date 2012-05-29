/********************************************************************************
 *                                                                    		*
 * GNORASI - The Knowlegde-Based Remote Sensing Engine                		*
 * 								      		*
 * Language:  C++						      		*
 * 										*
 * Copyright (c) Angelos Tzotsos <tzotsos@gmail.com>. All rights reserved. 	*
 * Copyright (c) National Technical University of Athens. All rights reserved.	*
 * Copyright (c) Informatics and Telematics Institute				*
 *	  Centre for Research and Technology Hellas. All rights reserved.	*
 * 										*
 *                                                                    		*
 * This file is part of the GNORASI software package. GNORASI is free  		*
 * software: you can redistribute it and/or modify it under the terms 		*
 * of the GNU General Public License version 2 as published by the    		*
 * Free Software Foundation.                                          		*
 *                                                                    		*
 * GNORASI is distributed in the hope that it will be useful,          		*
 * but WITHOUT ANY WARRANTY; without even the implied warranty of     		*
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the       		*
 * GNU General Public License for more details.                       		*
 *                                                                    		*
 * You should have received a copy of the GNU General Public License  		*
 * in the file "LICENSE.txt" along with this program.                 		*
 * If not, see <http://www.gnu.org/licenses/>.                        		*
 *                                                                    		*
 ********************************************************************************/

#include "otbmodule.h"
//#include "processors/dummysegmentationprocessor.h"
#include "processors/ImageIO/otbimagereaderprocessor.h"
#include "processors/ImageIO/otbimagewriterprocessor.h"
#include "processors/BasicFilters/otbconvolutionimagefilterprocessor.h"
#include "processors/BasicFilters/otbfftconvolutionimagefilterprocessor.h"
#include "processors/BasicFilters/otbcannyedgedetectionimagefilterprocessor.h"
#include "processors/BasicFilters/otbmeanimagefilterprocessor.h"
#include "processors/Visualization/otbsimpleviewerprocessor.h"


namespace voreen {

OTBModule::OTBModule() 
    : VoreenModule()
{
    // module name to be used in the GUI
    setName("Orfeo Toolbox");
    
    // module description file
    setXMLFileName("otb/otbmodule.xml");

    // each module processor needs to be registered
    //addProcessor(new DummySegmentationProcessor());
    addProcessor(new OTBImageReaderProcessor());
    addProcessor(new OTBImageWriterProcessor());
    addProcessor(new OTBConvolutionImageFilterProcessor());
    addProcessor(new OTBCannyEdgeDetectionImageFilterProcessor());
    addProcessor(new OTBSimpleViewerProcessor());
    addProcessor(new OTBMeanImageFilterProcessor());
    //addProcessor(new OTBFFTConvolutionImageFilterProcessor()); TODO: Enable FFTW in OTB
}

} // namespace
