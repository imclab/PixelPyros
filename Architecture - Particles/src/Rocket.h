////
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "ParticleSystem.h"

class Rocket : public Particle { 
	
public: 
	
	Rocket() ; 
	
	bool update(float deltaTime); 
	bool draw() { Particle::draw();} ; 
	void reset(); 
	
	ParticleSystem * makeRocketTrail(ParticleSystem * rocket); 
	ParticleSystem * makeExplosionBurst(ParticleSystem * ps);
	
	ParticleSystem * rocketTrail; 
	ParticleSystem * explosionBurst; 





};