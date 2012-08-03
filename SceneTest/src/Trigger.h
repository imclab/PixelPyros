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
#include "ParticleSystemManager.h"

typedef enum { 
	TRIGGER_TYPE_ONE_SHOT, 
	TRIGGER_TYPE_CONTINUOUS, 
	TRIGGER_TYPE_POWERED
	
} TriggerType;

class Trigger { 

	public : 
	
	Trigger(ParticleSystemManager & psm); 
	bool update(float deltaTime); 
	void draw(); 
	
	void makeRocket(); 
	
	
	ofVec3f pos; 
	
	RocketSettings rocketSettings; 
		
	ParticleSystemManager & particleSystemManager; 


};