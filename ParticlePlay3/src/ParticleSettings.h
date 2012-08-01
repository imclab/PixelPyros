//
//  ParticleSettings.h
//  ParticlePlay3
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once
#include "ofMain.h"

#include "ColourModifier.h"


typedef enum {
	PARTICLE_EMIT_BURST, 
	PARTICLE_EMIT_CONTINUOUS
} ParticleEmitMode;

class ParticleSettings { 

	public : 

	ParticleSettings() { 
		
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
		saturationMin = saturationMax = 0; 
		
		shimmerMin = 1; 
		
	};

	void initVelocity(ofVec3f& vel) { 
		
		vel.set(ofRandom(speedMin, speedMax), 0); 
		vel.rotate(0,0,ofRandom(directionZ-directionZVar, directionZ+directionZVar)); 
		vel.rotate(0,ofRandom(directionY-directionYVar, directionY+directionYVar), 0 ); 
		
	};
	
	void initColourModifier (ColourModifier* c) { 
		c->hueStart = ofRandom(hueStartMin, hueStartMax); 
		c->hueEnd = c->hueStart + hueChange; 
		
		c->brightnessStart = ofRandom(brightnessStartMin, brightnessStartMax); 
		c->brightnessEnd = brightnessEnd; 
		
		c->saturation = ofRandom(saturationMin, saturationMax); 
		
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
	
	// LIFE
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
	
	float shimmerMin; 







};