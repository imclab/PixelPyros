//
//  SceneFountains.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 14/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once

#include "Scene.h"
#include "RocketFountain.h"
#include "TriggerSimple.h"



class SceneFountains : public Scene {
	
	public :
	
	SceneFountains(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
		
		TriggerSimple trigger(psm);
		
		
		RocketFountain rocket(0,0,0);
		trigger.addRocket(rocket);
		
		trigger.minTimeBetweenRockets = 0.1;
		trigger.restoreSpeed = 1;
		trigger.chargeAmount = 0;
		
		trigger.rocketPower = 0.5;
		
		TriggerPattern pattern;
		pattern.addTrigger(trigger);
		addArrangement(pattern); 
		
		//addTriggers(trigger, 30, 20,ofGetHeight()*0.85, ofGetWidth()-160);
		
	}
	
	
};