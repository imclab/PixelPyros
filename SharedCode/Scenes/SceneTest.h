
#pragma once

#include "Scene.h"
#include "TriggerTest.h"
class SceneTest : public Scene {
	
	public : 
	
	SceneTest(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){		
		
		TriggerTest trigger(psm); 
		
		//addTriggers(trigger, 50, 0, ofGetHeight()*0.85, ofGetWidth());
		
			
		
		
		
	}
	
	
	
};