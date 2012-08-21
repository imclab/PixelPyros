//
//  Scene.cpp
//  SceneTest
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Scene.h"




Scene::Scene(ParticleSystemManager & psm, ofRectangle triggerarea) : particleSystemManager(psm) {
	active = false; 
	stopping = false;
	setTriggerArea(triggerarea);
	currentArrangementIndex = -1; 
	
}


void Scene :: start() {
	
	if (startArrangement(0)) active = true;
	
}


void Scene :: stop() { 
	
	for(int i=0; i<arrangements.size(); i++) {

		arrangements[i]->stop();
		
	}
	stopping = true; 
	
}

bool Scene :: update(float deltaTime) {

	if(!active) return false; 
	int activeArrangements = 0;
	
	for(int i=0; i<arrangements.size(); i++) {
	
		if( arrangements[i]->update(deltaTime)) activeArrangements++;
		else if (i==currentArrangementIndex) next(); 
		
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

void Scene :: setTriggerArea(ofRectangle rect){
	
	triggerArea = rect;
	for(int i = 0; i<arrangements.size() ; i++) {
		arrangements[i]->setTriggerArea(rect);
	}

}



Arrangement& Scene ::addArrangement(TriggerPattern& pattern) {
	arrangements.push_back(new Arrangement(particleSystemManager, triggerArea));
	arrangements.back()->setTriggerArea(triggerArea);
	arrangements.back()->initialiseFromPattern(pattern);
	
	
}


bool Scene :: startArrangement(int num) {
	
	if(num>=arrangements.size()) return false;
	if(currentArrangementIndex>=0) {
		arrangements[currentArrangementIndex]->stop();
	}
	
	arrangements[num]->start();
	currentArrangementIndex = num; 
	return true;
	
	
}


bool Scene :: next() {
	if(arrangements.size()==0) return false;
	
	int nextArrangement = currentArrangementIndex+1;
	if(nextArrangement>=arrangements.size())
		nextArrangement = 0;
	
	startArrangement(nextArrangement);
	
	
}

bool Scene :: previous() {

	if(arrangements.size()==0) return false;
	
	int prevArrangement = currentArrangementIndex-1;
	if(prevArrangement<0)
		prevArrangement = arrangements.size();
	
	startArrangement(prevArrangement);


}