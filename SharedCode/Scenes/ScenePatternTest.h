//
//  ScenePatternTest.h
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 20/08/2012.
//
//

#pragma once

#include "Scene.h"
#include "BasicRocket.h"
#include "Arrangement.h"

#include "TriggerPattern.h"


class ScenePatternTest : public Scene {

	
	public :

	ScenePatternTest(ParticleSystemManager& psm) : Scene(psm){
	
		BasicRocket rocketSettings(100,10, 120);
		
		TriggerBase trigger(particleSystemManager);
		
		trigger.addRocket(rocketSettings);
		// makes one shot type
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger.triggerLevel = 1;
		trigger.restoreSpeed = 0.5;
		trigger.rocketPower = 0.99;
		
		trigger.chargeAmount = 2;
		
		TriggerPattern pattern;
		trigger.radius = 20;
		pattern.addTrigger(trigger,0.5);
		trigger.radius = 10; 
		pattern.addTrigger(trigger,0.5);
		pattern.addTrigger(trigger,0.5);
		pattern.addTrigger(trigger,0.5);
	
		arrangements.push_back(new Arrangement(psm));
		arrangements.back()->setPattern(pattern);
	
	}

};