/*
 *  ParticleEmitterSettings.h
 *  
 *
 *  Created by Seb Lee-Delisle on 02/04/2011.
 *  Copyright 2011 seb.ly. All rights reserved.
 *
 */

#pragma once
#include "ofMain.h"

#define PARTICLE_SPAWN_CONTINUOUS 0
#define PARTICLE_SPAWN_BURST 1

class ParticleSystemSettings
{
	public : 

	ParticleSystemSettings(); 
	~ParticleSystemSettings(); 
	
	ofImage * image; 
	
	int spawnMode; 
	
	// number of particles per second
	float frequency; 
	
	// starting velocity (speed (pixels per second) and angle)
	float speed; 
	float speedVar; 
	float direction; 
	float directionVar; 
	float directionY; 
	float directionYVar; 
	
	bool pointInDirection; 
	
	float sizeStart; 
	float sizeStartVar; 
	// as proportion of sizeStart
	float sizeChange; 

	// drag applied to particle 30 times a second
	float drag; 
			
	float hue; 
	float hueVar; 
	float saturation; 
	float saturationVar; 
	float brightness; 
	float brightnessVar; 
	float brightnessEnd; 
	float brightnessEndVar; 
	
	// if the particle is shimmering, this is the minimum size
	// it'll be (0 - 1) 
	float shimmerMin; 
	
	// pixels per second change in velocity
	ofVec3f gravity; 
	
	float lifeTime; 
	float lifeTimeVar; 
	
		

};