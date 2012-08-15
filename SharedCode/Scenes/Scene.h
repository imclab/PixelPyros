//
//  Scene.h
//  SceneTest
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "Trigger.h"
#include "ParticleSystemManager.h"
#include "MotionManager.h"

class Scene { 


	public : 
	
	Scene(ParticleSystemManager& psm); 
	
	void start(); 
	void stop();
	
	bool update(float deltaTime); 
	void draw(); 
	
	void updateMotion(MotionManager& motionManager);
	
	void addTriggers(Trigger trigger, int numTriggers, float x, float y, float width); 
	
	bool active; 
	bool stopping; 
	
	vector <Trigger*> triggers; 
	
	ParticleSystemManager& particleSystemManager; 
	

};