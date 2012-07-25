//
//  Rocket.h
//  ParticlePlay
//
//  Created by Seb Lee-Delisle on 24/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once
#include "ParticleSystem.h"

class Rocket : public Particle { 
	
	public: 

	Rocket(); 
	
	void reset(ofVec3f& newpos); 
	
	void update(float deltaTime); 
	void draw(); 

	vector <ParticleSystem> particleSystems; 
	
	
	
	
	
};

