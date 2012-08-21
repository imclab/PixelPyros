//
//  Arrangement.cpp
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 20/08/2012.
//
//

#include "Arrangement.h"

Arrangement :: Arrangement(ParticleSystemManager & psm, ofRectangle triggerarea) : particleSystemManager(psm) {
	active = false;
	stopping = false;
	setTriggerArea(triggerarea);
	triggerPattern = NULL;
	
}


void Arrangement :: start() {
	
	cout << "start arrangement" << endl; 
	for(int i=0; i<triggers.size(); i++) {
		
		//if(ofRandom(100)<2) triggers[i]->makeRocket();
		//cout << "start trigger " << i <<endl;
		
		triggers[i]->start();
		
	}
	
	active = true;
	
}


void Arrangement :: stop() {
	
	for(int i=0; i<triggers.size(); i++) {
		
		//if(ofRandom(100)<2) triggers[i]->makeRocket();
		
		triggers[i]->stop();
		
		
		
	}
	stopping = true;
	
}

bool Arrangement :: update(float deltaTime) {
	
	if(!active) return false;
	int activeTriggers = 0;
	
	for(int i=0; i<triggers.size(); i++) {
		
		if( triggers[i]->update(deltaTime)) activeTriggers++;
		
	}
	if (activeTriggers==0)  {
		active = false;
	}
	
	return active;
	
	
}

void Arrangement:: draw() {
	
	
	for(int i=0; i<triggers.size(); i++) {
		
		triggers[i]->draw();
		
	}
	
	
	
}



void Arrangement :: updateMotion(MotionManager& motionManager, cv::Mat homography){
	
	if(!active) return;
	
	for(int i = 0; i<triggers.size(); i++) {
		
		TriggerSimple * trigger = triggers[i];
		
		if(!trigger->active) continue;
		
		float motion = motionManager.getMotionAtPosition(trigger->pos, trigger->radius*2, homography);
		trigger->registerMotion(motion/255);
		
		//cout << motion << endl;
		
		
	}
	
}

void Arrangement :: initialiseFromPattern(TriggerPattern tp) {
	
	// MAKE A FUNCTION that lays out all the triggers. 
	float minSpacing = 50;
	int numPerPattern = tp.triggers.size();
	int numPatterns = triggerArea.width/ (numPerPattern* minSpacing);
	int spacing = triggerArea.width / (numPatterns*numPerPattern);
	
	float xPos = triggerArea.x;
	
	for(int j = 0; j<numPatterns; j++ ) {
		for(int i =0; i<tp.triggers.size(); i++) {
		
			TriggerSimple* trigger = addTrigger(*tp.triggers[i]);
			trigger->pos.x = xPos;
			trigger->pos.y = triggerArea.y+(triggerArea.height/2);
			xPos+=spacing; 
			
		}
	}
}

void Arrangement:: setTriggerArea(ofRectangle rect) {
	triggerArea = rect;
	for(int i=0; i<triggers.size(); i++) {
		
		triggers[i]->pos.y = triggerArea.y+(triggerArea.width/2);
		
	}
	
	
}

template <typename T>
T* Arrangement :: addTrigger(T trigger) {
	
	T* newtrigger = new T(trigger);
	triggers.push_back(newtrigger);
	return newtrigger;
	
}


