//
//  Scene1.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 14/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once

#include "Scene.h"
#include "BasicRocket.h"
#include "TriggerSimple.h"

class Scene2 : public Scene {
	
	public : 
	
	Scene2(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
		
		BasicRocket rocketSettings(100,10, 120);
		
		TriggerSimple trigger(particleSystemManager);
		
		trigger.addRocket(rocketSettings);
		// makes one shot type
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger.triggerLevel = 1;
		trigger.restoreSpeed = 0.5;
		trigger.rocketPower = 0.99;
		
		trigger.chargeAmount = 2; 
	
		//addTriggers(trigger, 50, 100,ofGetHeight()*0.85, ofGetWidth()-160);
		
		
	}
	
	
	
};