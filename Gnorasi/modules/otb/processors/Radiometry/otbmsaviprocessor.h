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

#ifndef VRN_OTBMSAVIPROCESSOR_H
#define VRN_OTBMSAVIPROCESSOR_H


#include "voreen/core/processors/processor.h"
#include "voreen/core/properties/intproperty.h"
#include "otbImage.h"
#include "otbVectorImage.h"
#include "otbMultiChannelRAndNIRIndexImageFilter.h"
#include "otbVegetationIndicesFunctor.h"
#include "../../ports/otbimageport.h"
#include "../../ports/otbvectorimageport.h"

namespace voreen {
  
class OTBMSAVIProcessor : public Processor {
public:
    OTBMSAVIProcessor();
    virtual ~OTBMSAVIProcessor();
    
    virtual Processor* create() const { return new OTBMSAVIProcessor(); }
    
    virtual std::string getCategory() const { return "Radiometry"; }
    virtual std::string getClassName() const { return "Calculate MSAVI"; }
    virtual CodeState getCodeState() const { return CODE_STATE_TESTING; }//STABLE, TESTING, EXPERIMENTAL
    
    virtual std::string getProcessorInfo() const;
    
    typedef double PixelType;
    typedef otb::Image<PixelType> ImageType;
    typedef otb::VectorImage<PixelType> VectorImageType;
    typedef otb::Functor::MSAVI<PixelType,PixelType,PixelType> MSAVIFunctorType;
    typedef otb::MultiChannelRAndNIRIndexImageFilter<VectorImageType,
      ImageType, MSAVIFunctorType> MSAVIImageFilterType;
    
    MSAVIImageFilterType::Pointer filter;
        

protected:
    void process();
    void setRedBandIndex();
    void setNirBandIndex();
    virtual void initialize() throw (tgt::Exception);
    virtual void deinitialize() throw (tgt::Exception);

private:

    OTBVectorImagePort inPort_;
    OTBImagePort outPort_;
    
    IntProperty redBand_;	     ///< Input RED band selector
    IntProperty nirBand_;	     ///< Input RED band selector

    static const std::string loggerCat_; ///< category used in logging
};

} // namespace

#endif // VRN_OTBMSAVIPROCESSOR_H
