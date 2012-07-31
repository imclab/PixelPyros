//
//  ParticleSystemData.h
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//	
//	

#pragma once

#include "ofMain.h"
#include "Physics.h"
#include "Particle.h"
#include "ParticleSettings.h"


class ParticleEmitterSettings{
	
	
	
	public : 
	
	ParticleEmitterSettings() { 
		
		speedMin = speedMax = 0; 
		rotationZ = rotationZVar = 0; 
		rotationY = rotationYVar = 0; 
		drag = 1; 
		gravity.set(0,0,0); 
		
		delayMin = delayMax = 0; 
		lifeTimeMin = lifeTimeMax = 10; 
		
		emitMode = PARTICLE_EMIT_CONTINUOUS; 
		
	};
	
	
	ParticleEmitMode emitMode; 
	float	emitCount;	// num per second for continuous or 
						// total number for burst
	
	
	// physics for the emitter
	
	float speedMin; 
	float speedMax;
	float rotationZ; 
	float rotationZVar; 
	float rotationY; 
	float rotationYVar; 
	
	float delayMin; 
	float delayMax; 
	float lifeTimeMin; 
	float lifeTimeMax; 
	
	float drag; 
	ofVec3f gravity; 
	
		
	//settings for the visuals and movement of the particles
	
	ParticleSettings settings; 
	
	ParticleSettings * startSettings; 
	ParticleSettings * endSettings; 
	
	
	
	
	
	
};