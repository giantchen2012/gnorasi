/***********************************************************************************
 *                                                                                 *
 * Voreen - The Volume Rendering Engine                                            *
 *                                                                                 *
 * Copyright (C) 2005-2012 University of Muenster, Germany.                        *
 * Visualization and Computer Graphics Group <http://viscg.uni-muenster.de>        *
 * For a list of authors please refer to the file "CREDITS.txt".                   *
 *                                                                                 *
 * This file is part of the Voreen software package. Voreen is free software:      *
 * you can redistribute it and/or modify it under the terms of the GNU General     *
 * Public License version 2 as published by the Free Software Foundation.          *
 *                                                                                 *
 * Voreen is distributed in the hope that it will be useful, but WITHOUT ANY       *
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR   *
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.      *
 *                                                                                 *
 * You should have received a copy of the GNU General Public License in the file   *
 * "LICENSE.txt" along with this file. If not, see <http://www.gnu.org/licenses/>. *
 *                                                                                 *
 * For non-commercial academic use see the license exception specified in the file *
 * "LICENSE-academic.txt". To get information about commercial licensing please    *
 * contact the authors.                                                            *
 *                                                                                 *
 ***********************************************************************************/

#ifndef VRN_LINKEVALUATORID_H
#define VRN_LINKEVALUATORID_H

#include "voreen/core/properties/link/linkevaluatoridgeneric.h"

#include "voreen/core/properties/shaderproperty.h"
#include "voreen/core/properties/cameraproperty.h"
#include "voreen/core/properties/volumeurlproperty.h"

namespace voreen {

///just a dummy class to enable auto conversion:
class LinkEvaluatorId : public LinkEvaluatorBase {
public:
    virtual void eval(Property*, Property*) throw (VoreenException) {}

    virtual std::string name() const { return "id"; }
    virtual std::string getClassName() const { return "LinkEvaluatorId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorId(); }
    virtual bool arePropertiesLinkable(const Property*, const Property*) const { return true; }
};

///just a dummy class to enable auto conversion:
class LinkEvaluatorIdNormalized : public LinkEvaluatorBase {
public:
    virtual void eval(Property*, Property*) throw (VoreenException) {}

    virtual std::string name() const { return "id normalized"; }
    virtual std::string getClassName() const { return "LinkEvaluatorIdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIdNormalized(); }
    virtual bool arePropertiesLinkable(const Property*, const Property*) const { return true; }
};

//-------------------------------------------------------------------------------------------------------
//Bool, Int, Float, Double:

class LinkEvaluatorBoolId : public LinkEvaluatorIdGeneric<bool> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorBoolId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorBoolId(); }
};

class LinkEvaluatorIntId : public LinkEvaluatorIdGeneric<int> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIntId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIntId(); }
};

class LinkEvaluatorFloatId : public LinkEvaluatorIdGeneric<float> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorFloatId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorFloatId(); }
};

class LinkEvaluatorDoubleId : public LinkEvaluatorIdGeneric<double> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDoubleId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDoubleId(); }
};

// id conversion
class LinkEvaluatorDoubleFloatId : public LinkEvaluatorIdGenericConversion<double, float> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDoubleFloatId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDoubleFloatId(); }
};

class LinkEvaluatorDoubleIntId : public LinkEvaluatorIdGenericConversion<double, int> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDoubleIntId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDoubleIntId(); }
};

class LinkEvaluatorDoubleBoolId : public LinkEvaluatorIdGenericConversion<double, bool> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDoubleBoolId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDoubleBoolId(); }
};

class LinkEvaluatorFloatIntId : public LinkEvaluatorIdGenericConversion<float, int> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorFloatIntId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorFloatIntId(); }
};

class LinkEvaluatorFloatBoolId : public LinkEvaluatorIdGenericConversion<float, bool> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorFloatBoolId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorFloatBoolId(); }
};

class LinkEvaluatorIntBoolId : public LinkEvaluatorIdGenericConversion<int, bool> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIntBoolId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIntBoolId(); }
};

// id normalized
class LinkEvaluatorIntIdNormalized : public LinkEvaluatorIdNormalizedGeneric<int> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIntIdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIntIdNormalized(); }
};

class LinkEvaluatorFloatIdNormalized : public LinkEvaluatorIdNormalizedGeneric<float> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorFloatIdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorFloatIdNormalized(); }
};

class LinkEvaluatorDoubleIdNormalized : public LinkEvaluatorIdNormalizedGeneric<double> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDoubleIdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDoubleIdNormalized(); }
};

// id normalized conversion
class LinkEvaluatorDoubleFloatIdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<double, float> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDoubleFloatIdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDoubleFloatIdNormalized(); }
};

class LinkEvaluatorDoubleIntIdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<double, int> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDoubleIntIdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDoubleIntIdNormalized(); }
};

class LinkEvaluatorFloatIntIdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<float, int> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorFloatIntIdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorFloatIntIdNormalized(); }
};

//-------------------------------------------------------------------------------------------------------
// Vector properties:

// id
class LinkEvaluatorIVec2Id : public LinkEvaluatorIdGeneric<tgt::ivec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIVec2Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIVec2Id(); }
};

class LinkEvaluatorIVec3Id : public LinkEvaluatorIdGeneric<tgt::ivec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIVec3Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIVec3Id(); }
};

class LinkEvaluatorIVec4Id : public LinkEvaluatorIdGeneric<tgt::ivec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIVec4Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIVec4Id(); }
};

class LinkEvaluatorVec2Id : public LinkEvaluatorIdGeneric<tgt::vec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec2Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec2Id(); }
};

class LinkEvaluatorVec3Id : public LinkEvaluatorIdGeneric<tgt::vec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec3Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec3Id(); }
};

class LinkEvaluatorVec4Id : public LinkEvaluatorIdGeneric<tgt::vec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec4Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec4Id(); }
};

class LinkEvaluatorDVec2Id : public LinkEvaluatorIdGeneric<tgt::dvec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec2Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec2Id(); }
};

class LinkEvaluatorDVec3Id : public LinkEvaluatorIdGeneric<tgt::dvec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec3Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec3Id(); }
};

class LinkEvaluatorDVec4Id : public LinkEvaluatorIdGeneric<tgt::dvec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec4Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec4Id(); }
};

// id conversion
class LinkEvaluatorDVec2Vec2Id : public LinkEvaluatorIdGenericConversion<tgt::dvec2, tgt::vec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec2Vec2Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec2Vec2Id(); }
};

class LinkEvaluatorDVec3Vec3Id : public LinkEvaluatorIdGenericConversion<tgt::dvec3, tgt::vec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec3Vec3Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec3Vec3Id(); }
};

class LinkEvaluatorDVec4Vec4Id : public LinkEvaluatorIdGenericConversion<tgt::dvec4, tgt::vec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec4Vec4Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec4Vec4Id(); }
};

class LinkEvaluatorDVec2IVec2Id : public LinkEvaluatorIdGenericConversion<tgt::dvec2, tgt::ivec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec2IVec2Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec2IVec2Id(); }
};

class LinkEvaluatorDVec3IVec3Id : public LinkEvaluatorIdGenericConversion<tgt::dvec3, tgt::ivec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec3IVec3Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec3IVec3Id(); }
};

class LinkEvaluatorDVec4IVec4Id : public LinkEvaluatorIdGenericConversion<tgt::dvec4, tgt::ivec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec4IVec4Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec4IVec4Id(); }
};

class LinkEvaluatorVec2IVec2Id : public LinkEvaluatorIdGenericConversion<tgt::vec2, tgt::ivec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec2IVec2Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec2IVec2Id(); }
};

class LinkEvaluatorVec3IVec3Id : public LinkEvaluatorIdGenericConversion<tgt::vec3, tgt::ivec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec3IVec3Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec3IVec3Id(); }
};

class LinkEvaluatorVec4IVec4Id : public LinkEvaluatorIdGenericConversion<tgt::vec4, tgt::ivec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec4IVec4Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec4IVec4Id(); }
};

// id normalized
class LinkEvaluatorIVec2IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::ivec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIVec2IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIVec2IdNormalized(); }
};

class LinkEvaluatorIVec3IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::ivec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIVec3IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIVec3IdNormalized(); }
};

class LinkEvaluatorIVec4IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::ivec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorIVec4IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorIVec4IdNormalized(); }
};

class LinkEvaluatorVec2IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::vec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec2IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec2IdNormalized(); }
};

class LinkEvaluatorVec3IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::vec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec3IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec3IdNormalized(); }
};

class LinkEvaluatorVec4IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::vec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec4IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec4IdNormalized(); }
};

class LinkEvaluatorDVec2IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::dvec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec2IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec2IdNormalized(); }
};

class LinkEvaluatorDVec3IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::dvec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec3IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec3IdNormalized(); }
};

class LinkEvaluatorDVec4IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::dvec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec4IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec4IdNormalized(); }
};

// id normalized conversion
class LinkEvaluatorDVec2Vec2IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::dvec2, tgt::vec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec2Vec2IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec2Vec2IdNormalized(); }
};

class LinkEvaluatorDVec3Vec3IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::dvec3, tgt::vec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec3Vec3IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec3Vec3IdNormalized(); }
};

class LinkEvaluatorDVec4Vec4IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::dvec4, tgt::vec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec4Vec4IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec4Vec4IdNormalized(); }
};

class LinkEvaluatorDVec2IVec2IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::dvec2, tgt::ivec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec2IVec2IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec2IVec2IdNormalized(); }
};

class LinkEvaluatorDVec3IVec3IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::dvec3, tgt::ivec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec3IVec3IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec3IVec3IdNormalized(); }
};

class LinkEvaluatorDVec4IVec4IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::dvec4, tgt::ivec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorDVec4IVec4IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorDVec4IVec4IdNormalized(); }
};

class LinkEvaluatorVec2IVec2IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::vec2, tgt::ivec2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec2IVec2IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec2IVec2IdNormalized(); }
};

class LinkEvaluatorVec3IVec3IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::vec3, tgt::ivec3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec3IVec3IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec3IVec3IdNormalized(); }
};

class LinkEvaluatorVec4IVec4IdNormalized : public LinkEvaluatorIdNormalizedGenericConversion<tgt::vec4, tgt::ivec4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVec4IVec4IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVec4IVec4IdNormalized(); }
};


//-------------------------------------------------------------------------------------------------------
//Matrix properties:

class LinkEvaluatorMat2Id : public LinkEvaluatorIdGeneric<tgt::mat2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorMat2Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorMat2Id(); }
};

class LinkEvaluatorMat3Id : public LinkEvaluatorIdGeneric<tgt::mat3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorMat3Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorMat3Id(); }
};

class LinkEvaluatorMat4Id : public LinkEvaluatorIdGeneric<tgt::mat4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorMat4Id"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorMat4Id(); }
};

// id normalized
class LinkEvaluatorMat2IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::mat2> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorMat2IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorMat2IdNormalized(); }
};

class LinkEvaluatorMat3IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::mat3> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorMat3IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorMat3IdNormalized(); }
};

class LinkEvaluatorMat4IdNormalized : public LinkEvaluatorIdNormalizedGeneric<tgt::mat4> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorMat4IdNormalized"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorMat4IdNormalized(); }
};

//-------------------------------------------------------------------------------------------------------
//String (+FileDialog)

class LinkEvaluatorStringId : public LinkEvaluatorIdGeneric<std::string> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorStringId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorStringId(); }
};

//-------------------------------------------------------------------------------------------------------

class LinkEvaluatorShaderId : public LinkEvaluatorIdGeneric<ShaderSource> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorShaderId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorShaderId(); }
};

//-------------------------------------------------------------------------------------------------------

// TODO remove
/*class LinkEvaluatorVolumeHandleId : public LinkEvaluatorIdGeneric<Volume*> {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorVolumeHandleId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorVolumeHandleId(); }
}; */

//-------------------------------------------------------------------------------------------------------

class LinkEvaluatorCameraId : public LinkEvaluatorBase {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorCameraId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorCameraId(); }
    virtual std::string name() const { return "id"; }

    ///Special implementation to only link position focus and up vector
    virtual void eval(Property* src, Property* dst) throw (VoreenException);

    bool arePropertiesLinkable(const Property* p1, const Property* p2) const;
};

//------------------------------------------------------------------------------------------------------
//
class LinkEvaluatorCameraPosId : public LinkEvaluatorBase {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorCameraPosId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorCameraPosId(); }
    virtual std::string name() const { return "id"; }

    ///Special implementation to only link position with FloatVec3Property
    virtual void eval(Property* src, Property* dst) throw (VoreenException);

    bool arePropertiesLinkable(const Property* p1, const Property* p2) const;
};

//------------------------------------------------------------------------------------------------------
//
class LinkEvaluatorCameraLookId : public LinkEvaluatorBase {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorCameraLookId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorCameraLookId(); }
    virtual std::string name() const { return "id"; }

    ///Special implementation to only link look vector with FloatVec3Property
    virtual void eval(Property* src, Property* dst) throw (VoreenException);

    bool arePropertiesLinkable(const Property* p1, const Property* p2) const;
};

//-------------------------------------------------------------------------------------------------------

class LinkEvaluatorTransFuncId : public LinkEvaluatorBase {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorTransFuncId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorTransFuncId(); }
    virtual std::string name() const { return "id"; }

    virtual void eval(Property* src, Property* dst) throw (VoreenException);

    bool arePropertiesLinkable(const Property* p1, const Property* p2) const;
};

//-------------------------------------------------------------------------------------------------------

class LinkEvaluatorButtonId : public LinkEvaluatorBase {
public:
    virtual std::string getClassName() const { return "LinkEvaluatorButtonId"; }
    virtual LinkEvaluatorBase* create() const { return new LinkEvaluatorButtonId(); }
    virtual std::string name() const { return "id"; }

    ///Special implementation to only link position focus and up vector
    virtual void eval(Property* src, Property* dst) throw (VoreenException);

    bool arePropertiesLinkable(const Property* p1, const Property* p2) const;
};

} // namespace

#endif // VRN_LINKEVALUATORID_H
