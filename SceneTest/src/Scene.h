//
//  Scene.h
//  SceneTest
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "Trigger.h"

class Scene { 


	public : 
	
	void start(); 
	void stop();
	
	bool update(float deltaTime); 
	void draw(); 
	
	void addTriggers(Trigger trigger, int numTriggers); 
	
	bool active; 
	
	vector <Trigger*> triggers; 
	
	


};