
#pragma once

#include "Scene.h"
#include "TriggerTest.h"

#include "TriggerSimple.h"

class SceneTest : public Scene {
	
	public : 
	
	SceneTest(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){		
		BasicRocket rocketSettings(100,10, 120);
		
		TriggerSimple trigger(psm);
		
		trigger.addRocket(rocketSettings); 
		//addTriggers(trigger, 50, 0, ofGetHeight()*0.85, ofGetWidth());
		
		TriggerTest trigger2(psm);
		
		TriggerPattern pattern;
		
		pattern.addTrigger(trigger);
		pattern.addTrigger(trigger2);
		
		addArrangement(pattern); 
		
		
	}
	
	
	
};