
#pragma once

#include "Scene.h"
#include "TriggerTest.h"
class SceneTest : public Scene {
	
	public : 
	
	SceneTest(ParticleSystemManager& psm) : Scene(psm){ 
		
		
		TriggerTest trigger(psm); 
		
		addTriggers(trigger, 50, 0, ofGetHeight()*0.85, ofGetWidth());
		
			
		
		
		
	}
	
	
	
};