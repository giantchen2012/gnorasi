/********************************************************************************
 *                                                                              *
 * GNORASI - The Knowlegde-Based Remote Sensing Engine                          *
 *                                                                              *
 * Language:  C++                                                               *
 *                                                                              *
 * Copyright (c) ALTEC SA - www.altec.gr - All rights reserved.					*
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
 
#ifndef VRN_OTBLINESEGMENTDETECTORPROCESSOR_H
#define VRN_OTBLINESEGMENTDETECTORPROCESSOR_H

#include "voreen/core/properties/intproperty.h"
#include "voreen/core/properties/floatproperty.h"
#include "voreen/core/properties/boolproperty.h"
#include "voreen/core/properties/buttonproperty.h"
#include "../BasicFilters/otbimagefilterprocessor.h"
#include "../../ports/otbimageport.h"
//#include "../../ports/otbvectordataport.h"
#include "otbLineSegmentDetector.h"

namespace voreen {
  
class OTBLineSegmentDetectorProcessor : public OTBImageFilterProcessor {
public:
    OTBLineSegmentDetectorProcessor();
    virtual ~OTBLineSegmentDetectorProcessor();
    
    virtual Processor* create() const;
    
    virtual std::string getCategory() const { return "Feature Extranction"; }
    virtual std::string getClassName() const { return "Fast Line Detector"; }
    virtual CodeState getCodeState() const { return CODE_STATE_TESTING; }//STABLE, TESTING, EXPERIMENTAL
    
    virtual std::string getProcessorInfo() const;

    static const unsigned int                                           Dimension = 2;
    typedef double                                                      PixelType;
    typedef otb::Image<PixelType,Dimension>                             ImageType;

    typedef otb::LineSegmentDetector<ImageType,PixelType>               LSDFilterType;

    LSDFilterType::Pointer                                              filter;
        

protected:
    virtual void setDescriptions() {
	setDescription("processor.");
    }
    void process();

    virtual void initialize() throw (tgt::Exception);
    virtual void deinitialize() throw (tgt::Exception);

    void update();

private:

    OTBImagePort inPort_;
    //OTBVectorDataPort outPort_;

//    FloatProperty                                                       m_thresholdProperty;
//    FloatProperty                                                       m_precisionProperty;
//    FloatProperty                        v                                m_directionAllowedProperty;
//    IntProperty                                                         m_minimumRegionSizeProperty;

    ButtonProperty                                                      m_updateProperty;

    static const std::string loggerCat_; ///< category used in logging
};

} // namespace

#endif // VRN_OTBLINESEGMENTDETECTORPROCESSOR_H
