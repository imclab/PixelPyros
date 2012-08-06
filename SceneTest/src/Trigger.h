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
	TRIGGER_TYPE_FIRE_ON_MOTION, 
	TRIGGER_TYPE_FIRE_ON_CHARGE
	
} TriggerType;

class Trigger { 

	public : 
	
	Trigger(ParticleSystemManager & psm); 
	bool update(float deltaTime); 
	void draw(); 
	
	void start(); 
	void stop(); 
	
	void registerMotion(float unitValue); 
	
	bool makeRocket(); 
	
	TriggerType type; 
	
	bool active; 
	bool stopping; 
	
	
	// to create a trigger that is one shot, set restoreSpeed
	// to 0. If you want a trigger that needs charging up, 
	// set motionDecay to 0, fireOnCharge to true
	
	// activityLevel is the accumulated motion
	float motionLevel; 
	
	//amount per second to take away from the accumulated motion
	float motionDecay; 
	// triggerLevel is the amount of motion needed to make something happen
	float triggerLevel; 
	
	float chargeOnMotion;
	float chargeAmount; 
	
	float minTimeBetweenRockets; 
	float restoreSpeed; 
	float lastRocketTime; 


	float scale; 
	float targetScale; 
	
	
	ofVec3f pos; 
	
	RocketSettings rocketSettings; 
		
	ParticleSystemManager & particleSystemManager; 

	float unitPower;
	float rocketPower; 
	
	float elapsedTime;
	
};