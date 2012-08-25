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

#include "TriggerBase.h"

//template <typename Derived>
class TriggerSimple : public TriggerBase {

	public : 
	
	TriggerSimple(ParticleSystemManager & psm);
	virtual bool update(float deltaTime); 
	virtual void draw(); 
	
	virtual void start(); 
	virtual void stop(); 
	
	virtual void registerMotion(float unitValue); 
	virtual void addRocket(RocketSettings rocket);
	
	virtual bool makeRocket();
	
	
	virtual TriggerSimple* clone() const{
		//cout << "clone TriggerSimple"<< endl;
		return new TriggerSimple( *this );
	}
	
	int currentRocketIndex; 
	
	TriggerType type; 
	
	float elapsedTime;
	
};