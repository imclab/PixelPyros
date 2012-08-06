//
//  Scene.cpp
//  SceneTest
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Scene.h"



Scene::Scene(ParticleSystemManager & psm) : particleSystemManager(psm) { 
	active = false; 
	stopping = false; 
	
}


void Scene :: start() { 
	for(int i=0; i<triggers.size(); i++) { 
		
		//if(ofRandom(100)<2) triggers[i]->makeRocket(); 
		
		triggers[i]->start();
		
		
		
	}
	
	active = true;
	
}


void Scene :: stop() { 
	
	for(int i=0; i<triggers.size(); i++) { 
		
		//if(ofRandom(100)<2) triggers[i]->makeRocket(); 
		
		triggers[i]->stop();
		
		
		
	}
	stopping = true; 
	
}

bool Scene :: update(float deltaTime) {

	if(!active) return false; 
	int activeTriggers = 0; 
	
	for(int i=0; i<triggers.size(); i++) { 
	
		if( triggers[i]->update(deltaTime)) activeTriggers++;
		
	}
	if((stopping) && (activeTriggers==0) ) {
		active = false;
	}

	return active; 
	
	
}

void Scene:: draw() { 

	
	for(int i=0; i<triggers.size(); i++) { 
		
		triggers[i]->draw();
		
	}
	


}

void Scene:: addTriggers(Trigger trigger, int numTriggers, float x, float y, float width) {
	
	float spacing = width/(numTriggers -1);
	 
	
	for(int i = 0; i<numTriggers; i++) { 
	
		Trigger * newtrigger = new Trigger(trigger);
		triggers.push_back(newtrigger); 
		
		// TODO make this height adjustable somehow 
		newtrigger->pos.set(x, y); 
		x+=spacing; 
		
		
	}
	
	
	
	
}