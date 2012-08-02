//
//  Trigger.h
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "ParticleSystem.h"
#include "PhysicsObject.h"
#include "RocketSettings.h"

class Trigger { 

	public : 
	bool update(float deltaTime); 
	void draw(); 
	
	void makeRocket(); 
	
	RocketSettings rocketSettings; 
	
	vector <ParticleSystem*> particleSystems; 
	vector <ParticleSystem*> spareParticleSystems; 
	vector <PhysicsObject*> physicsObjects; 	
	vector <PhysicsObject*> sparePhysicsObjects; 


};