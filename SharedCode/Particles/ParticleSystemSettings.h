//
//  ParticleSystemSettings.h
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once
#include "ofMain.h"

#include "ColourModifier.h"
#include "VelocityModifierSettings.h"
#include "ParticleRendererBase.h"

typedef enum {
	PARTICLE_EMIT_BURST, 
	PARTICLE_EMIT_CONTINUOUS
} ParticleEmitMode;


class ParticleSystemSettings { 

	public : 

	ParticleSystemSettings() { 
		
		// PHYSICS
		speedMin = speedMax = 200; 
		directionZ = 0; 
		directionZVar = 180;
		directionY = directionYVar = 0; 
	
		drag = 1; 
		gravity.set(0,0,0); 
	
		// LIFE 
		lifeMin = lifeMax = 1; 

		// APPEARANCE
		sizeStartMin = sizeStartMax = 1; 
		sizeChangeRatio = 0; 
		
		// COLOUR
		hueStartMin = hueStartMax = hueChange = 0; 
		brightnessStartMin = brightnessStartMax = brightnessEnd = 255; 
		saturationMin = saturationMax = saturationEnd = 0; 
		
		shimmerMin = 1; 
		
		//EMISSION LIFE CYCLE
		emitLifeTime; 
		emitDelay; 
		
		// EMISSION MODE AND PARTICLE COUNT
		emitMode; 
		emitCount; // number of Particles per second
		
		// EMISSION CHANGE OVER TIME 
		// This will change the start size and hue of emitted
		// particles over time. Probably all I need to change. 
		emitStartSizeModifier = 1;  // Multiplier
		emitSpeedModifier = 1;		// Multiplier
		emitHueModifierOffset = 0;	// Offset
		
		//emitAttachedPhysicsObject = NULL; 
		emitInheritVelocity = 0; 
		
		velocityModifierSettings = 0; 
		
	};

	void initVelocity(ofVec3f& vel) { 
		
		vel.set(ofRandom(speedMin, speedMax), 0); 
		vel.rotate(0,0,ofRandom(directionZ-directionZVar, directionZ+directionZVar)); 
		vel.rotate(0,ofRandom(directionY-directionYVar, directionY+directionYVar), 0 ); 
		
	};
	
	void initColourModifier (ColourModifier* c, LifeCycle& life) { 
		c->hueStart = ofRandom(hueStartMin, hueStartMax); 
		if(emitHueModifierOffset!=0) { 
			c->hueStart += (life.unitLifeProgress *emitHueModifierOffset) ; 
		}
		c->hueEnd = c->hueStart + hueChange; 
		
		c->brightnessStart = ofRandom(brightnessStartMin, brightnessStartMax); 
		c->brightnessEnd = brightnessEnd; 
		
		c->saturationStart = ofRandom(saturationMin, saturationMax); 
		c->saturationEnd = saturationEnd; 
		
	}
	
	// PHYSICS
	float speedMin; 
	float speedMax; 
	
	float directionZ; 
	float directionZVar; 
	float directionY; 
	float directionYVar; 

	float drag; 
	ofVec3f gravity; 
	
	// PARTICLE LIFE
	float lifeMin; 
	float lifeMax; 

	// APPEARANCE : 
	float sizeStartMin; 
	float sizeStartMax;
	float sizeChangeRatio; 
	
	float hueStartMin; 
	float hueStartMax;
	float hueChange; 
	
	float brightnessStartMin; 
	float brightnessStartMax; 
	float brightnessEnd;
	
	float saturationMin; 
	float saturationMax; 
	float saturationEnd; 
	
	float shimmerMin; 
	
	// ADD PARTICLE RENDERER - probably should be a property of the
	// ParticleSystem, right? Possibly add vector of renderers in the 
	// future? For multiple renders. All particles in the same system
	// should share the same renderer for future optimisations
	ParticleRendererBase renderer;

	//EMISSION LIFE CYCLE
	float emitLifeTime; 
	float emitDelay; 
	
	// EMISSION MODE AND PARTICLE COUNT
	ParticleEmitMode emitMode; 
	float emitCount; // number of Particles per second
	
	// EMISSION CHANGE OVER TIME 
	// This will change the start size, speed and hue of emitted
	// particles over time. Probably all I need to change. 
	float emitStartSizeModifier; 
	float emitSpeedModifier; 
	float emitHueModifierOffset; 
	//PhysicsObject * emitAttachedPhysicsObject; 
	float emitInheritVelocity;
	
	string startSound;



	VelocityModifierSettings * velocityModifierSettings; 

};





