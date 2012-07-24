/*
 *  Particle.h
 *  ParticleTest
 *
 *  Created by Seb Lee-Delisle on 26/03/2011.
 *  Copyright 2011 seb.ly. All rights reserved.
 *
 */
#pragma once

#include "ofVec2f.h"
#include "ofMain.h"

class Particle {
	
	public:
	
		Particle(); 
		void update(float deltaTime); 
		void draw();
		void reset(); 
		
		
		ofVec3f pos; 
		ofVec3f vel; 
		ofVec3f gravity; 
		
		bool	enabled; 
		float	drag; 
		int		dragApplyCount; 
		float	dragFrequency; 
		
		bool	pointInDirection; 
		

		float alpha; 
		float sizeStart;
		float sizeEnd; 
		float fade;
		
		float shimmerMin; 
		
		float lifeTime; 
		float elapsedTime; 
		
		ofColor color;  
		ofImage	* image;
	
		// to make sure that the noise function isn't the same across all particles
		//float noiseOffset; 
	
	
};