///
/// SamplerState.h
/// Vorb Engine
///
/// Created by Cristian Zaloj on 22 Jan 2015
/// Copyright 2014 Regrowth Studios
/// All Rights Reserved
///
/// Summary:
/// Changes GPU texture sampling state
///

#pragma once

#ifndef SamplerState_h__
#define SamplerState_h__

#include "GLEnums.h"
#include "gtypes.h"

namespace vorb {
	namespace graphics {
        // TODO: Why are these here?
		#ifndef GL_UNSIGNED_SHORT_5_6_5
		#define GL_UNSIGNED_SHORT_5_6_5 0x8363
		#endif
		#ifndef GL_CLAMP_TO_EDGE
		#define GL_CLAMP_TO_EDGE 0x812F
		#endif
		
		class SamplerState {
		public:
		    SamplerState(TextureMinFilter texMinFilter, TextureMagFilter texMagFilter,
		        TextureWrapMode texWrapS, TextureWrapMode texWrapT, TextureWrapMode texWrapR);
		    SamplerState(ui32 texMinFilter, ui32 texMagFilter,
		        ui32 texWrapS, ui32 texWrapT, ui32 texWrapR) :
		        SamplerState(static_cast<TextureMinFilter>(texMinFilter), static_cast<TextureMagFilter>(texMagFilter),
		        static_cast<TextureWrapMode>(texWrapS), static_cast<TextureWrapMode>(texWrapT), static_cast<TextureWrapMode>(texWrapR)) {}
		
		    void initObject();
		    // Initialize All The Sampler Objects When OpenGL Context Is Created
		    static void initPredefined();
		
		    // Target Is Of The Family GL_TEXTURE_2D/3D/etc. For Use On A Texture
		    void set(ui32 textureTarget) const;
		    // Unit Is In The Range [0 - GraphicsDeviceProperties::maxTextureUnits)
		    void setObject(ui32 textureUnit) const;
		
		    static SamplerState POINT_WRAP;
		    static SamplerState POINT_CLAMP;
		    static SamplerState LINEAR_WRAP;
		    static SamplerState LINEAR_CLAMP;
		    static SamplerState POINT_WRAP_MIPMAP;
		    static SamplerState POINT_CLAMP_MIPMAP;
		    static SamplerState LINEAR_WRAP_MIPMAP;
		    static SamplerState LINEAR_CLAMP_MIPMAP;
		private:
		    VGSampler _id;
		
		    TextureMinFilter _minFilter;
		    TextureMagFilter _magFilter;
		    TextureWrapMode _wrapS;
		    TextureWrapMode _wrapT;
		    TextureWrapMode _wrapR;
		};
	}
}
namespace vg = vorb::graphics;

#endif // SamplerState_h__