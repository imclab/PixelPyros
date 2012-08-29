
#pragma once

#include "Scene.h"
#include "TriggerTest.h"

#include "TriggerRocket.h"

class SceneTest : public Scene {
	
	public : 
	
	SceneTest(ParticleSystemManager& psm, ofRectangle* triggerarea) : Scene(psm, triggerarea){		
		RocketBasic rocketSettings(100,10, 120);
		
		TriggerRocket trigger(psm);
		
		trigger.addRocketSettings(rocketSettings); 
		//addTriggers(trigger, 50, 0, ofGetHeight()*0.85, ofGetWidth());
		
		TriggerTest trigger2(psm);
		
		TriggerPattern pattern;
		
		//pattern.addTrigger(trigger);
		pattern.addTrigger(trigger2);
		
		addArrangement(pattern); 
		
		
	}
	
	
	
};