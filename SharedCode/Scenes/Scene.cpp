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
	
	if (startArrangement(0)) active = true;
	
}


void Scene :: stop() { 
	
	for(int i=0; i<arrangements.size(); i++) {
		
		//if(ofRandom(100)<2) triggers[i]->makeRocket(); 
		
		arrangements[i]->stop();
		
	}
	stopping = true; 
	
}

bool Scene :: update(float deltaTime) {

	if(!active) return false; 
	int activeArrangements = 0;
	
	for(int i=0; i<arrangements.size(); i++) {
	
		if( arrangements[i]->update(deltaTime)) activeArrangements++;
		
	}
	if((stopping) && (activeArrangements==0) ) {
		active = false;
	}

	return active; 
	
	
}

void Scene:: draw() { 

	
	for(int i=0; i<arrangements.size(); i++) {
		
		arrangements[i]->draw();
		
	}
	


}
void Scene :: updateMotion(MotionManager& motionManager, cv::Mat homography){
	
	for(int i = 0; i<arrangements.size(); i++) {
		
		Arrangement * arrangement = arrangements[i];

		arrangement->updateMotion(motionManager, homography);
		
//		float motion = motionManager.getMotionAtPosition(trigger->pos, trigger->radius*2, homography); 
//		trigger->registerMotion(motion/255);
		
		//cout << motion << endl; 
		
		
	}
	
}

bool Scene :: startArrangement(int num) {
	if(num>=arrangements.size()) return false;
	arrangements[num]->start(); 
	return true;
	
	
}

