//
//  Arrangement.cpp
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 20/08/2012.
//
//

#include "Arrangement.h"

Arrangement :: Arrangement(ParticleSystemManager & psm) : particleSystemManager(psm) {
	active = false;
	stopping = false;
	
}


void Arrangement :: start() {
	
	cout << "start arrangement" << endl; 
	for(int i=0; i<triggers.size(); i++) {
		
		//if(ofRandom(100)<2) triggers[i]->makeRocket();
		cout << "start trigger " << i <<endl;
		
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
	if((stopping) && (activeTriggers==0) ) {
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
	
	for(int i = 0; i<triggers.size(); i++) {
		
		TriggerBase * trigger = triggers[i];
		
		float motion = motionManager.getMotionAtPosition(trigger->pos, trigger->radius*2, homography);
		trigger->registerMotion(motion/255);
		
		//cout << motion << endl;
		
		
	}
	
}

void Arrangement :: setPattern(TriggerPattern tp) {
	
	for(int i =0; i<tp.triggers.size(); i++) {
	
		TriggerBase* trigger = addTrigger(*tp.triggers[i]);
		trigger->pos.x = i*100;
		
	}
	
}

template <typename T>
T* Arrangement :: addTrigger(T trigger) {
	
	T* newtrigger = new T(trigger);
	triggers.push_back(newtrigger);
	return newtrigger;
	
}


