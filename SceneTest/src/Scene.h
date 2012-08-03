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

class Scene { 


	public : 
	
	Scene(ParticleSystemManager& psm); 
	
	void start(); 
	void stop();
	
	bool update(float deltaTime); 
	void draw(); 
	
	void addTriggers(Trigger trigger, int numTriggers); 
	
	bool active; 
	
	vector <Trigger*> triggers; 
	
	ParticleSystemManager& particleSystemManager; 
	

};