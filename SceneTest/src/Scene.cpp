//
//  Scene.cpp
//  SceneTest
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Scene.h"


void Scene :: start() { 
	
	
}


void Scene :: stop() { 
	
	
	
}

bool Scene :: update(float deltaTime) {

	for(int i=0; i<triggers.size(); i++) { 
	
		if(ofRandom(100)<1) triggers[i]->makeRocket(); 
		
		triggers[i]->update(deltaTime);
		
		
		
	}
	
	
}

void Scene:: draw() { 

	
	for(int i=0; i<triggers.size(); i++) { 
		
		triggers[i]->draw();
		
	}
	


}

void Scene:: addTriggers(Trigger trigger, int numTriggers) {
	
	float spacing = ofGetWidth()/(numTriggers+1);
	float x = spacing; 
	
	for(int i = 0; i<numTriggers; i++) { 
	
		Trigger * newtrigger = new Trigger(trigger);
		triggers.push_back(newtrigger); 
		
		// TODO make this height adjustable somehow 
		newtrigger->pos.set(x, ofGetHeight()*0.9); 
		x+=spacing; 
		
		
	}
	
	
	
	
}