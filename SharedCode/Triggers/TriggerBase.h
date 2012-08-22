//
//  TriggerBase.h
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

class TriggerBase {
	
	public :
	
	TriggerBase(ParticleSystemManager & psm) : particleSystemManager(psm){
		typeLabel = "TriggerBase";
	};
	
	
	virtual TriggerBase* clone() const=0;
	
	
	virtual bool update(float deltaTime) =0;
	virtual void draw() = 0;
	
	virtual void start() = 0;
	virtual void stop() = 0;
	
	virtual void registerMotion(float unitValue) = 0;
	virtual void addRocket(RocketSettings rocket) = 0;
	
	//virtual TriggerBase* clone() const = 0;
	virtual bool makeRocket() = 0;
	
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
	float radius;
	float targetScale;
	
	
	ofVec3f pos;
	
	vector <RocketSettings> rocketSettings;
	
	ParticleSystemManager & particleSystemManager;
	
	float unitPower;
	float rocketPower;
	
	float elapsedTime;
	
	
	string typeLabel;
	
};