//
//  Rocket.h
//  ParticlePlay
//
//  Created by Seb Lee-Delisle on 24/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once
#include "ParticleSystem.h"
//#include "testApp.h"

class Rocket : public Particle { 
	
	public: 

	Rocket() ; 
	
	void reset(ofVec3f& newpos); 
	
	void update(float deltaTime); 
	void draw(); 

	ParticleSystem * makeRocketTrail(ParticleSystem * rocket); 
	ParticleSystem * makeExplosionBurst(ParticleSystem * ps);
	
	vector <ParticleSystem *> particleSystems; 
	
	ParticleSystem * rocketTrail; 
	ParticleSystem * explosionBurst; 
	
	
	
};

