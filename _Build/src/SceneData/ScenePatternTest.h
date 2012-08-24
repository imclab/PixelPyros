//
//  ScenePatternTest.h
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 20/08/2012.
//
//

#pragma once

#include "Scene.h"
#include "TriggerSimple.h"
#include "RocketBasic.h"
#include "Arrangement.h"

#include "TriggerPattern.h"



class ScenePatternTest : public Scene {

	
	public :

	ScenePatternTest(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
	
		RocketBasic rocketSettings(100,10, 120);
		
		TriggerSimple trigger(particleSystemManager);
		
		trigger.addRocket(rocketSettings);
		// makes one shot type
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger.triggerLevel = 1;
		trigger.restoreSpeed = 0.0;
		trigger.rocketPower = 0.99;
		
		trigger.chargeAmount = 2;
		
		TriggerSimple trigger2(particleSystemManager);
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger2.restoreSpeed = 0.0;
		//trigger.triggerLevel = 1;
		
		trigger2.addRocket(RocketFountain()); 
		
		TriggerPattern pattern;
		trigger.radius = 10;
		pattern.addTrigger(trigger,0.5);
		trigger2.radius = 5;
		pattern.addTrigger(trigger2,0.5);
		pattern.addTrigger(trigger2,0.5);
		pattern.addTrigger(trigger2,0.5);
	
		addArrangement(pattern);
		
		TriggerPattern pattern2;
		trigger.radius = 10;
		pattern2.addTrigger(trigger,0.5);
		trigger2.radius = 5;
		pattern2.addTrigger(trigger2,0.5);
		addArrangement(pattern2);
	
	}

};