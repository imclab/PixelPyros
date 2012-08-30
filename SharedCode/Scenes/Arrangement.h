//
//  Arrangement.h
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 20/08/2012.
//
//


#pragma once

#include "TriggerBase.h"
#include "TriggerRocket.h"
#include "TriggerPattern.h"

#include "ParticleSystemManager.h"
#include "MotionManager.h"
#include "ofxCV.h"

class Arrangement {
	
	public :
	
	Arrangement(ParticleSystemManager& psm, ofRectangle triggerarea);
	
	virtual void start();
	virtual void stop();
	
	virtual bool update(float deltaTime);
	virtual void draw();
	
	virtual void updateMotion(MotionManager& motionManager, cv::Mat homography);
	
	
	virtual void updateDebug(bool debug); 
	virtual void updateLayout(ofRectangle& triggerarea, float minSpacing); 
	virtual void setPattern(TriggerPattern tp, ofRectangle& triggerarea, float minspacing);
	
	//template <typename T>
	//T* addTrigger(T* trigger);
	
	//void setTriggerArea(ofRectangle area);
	
	bool active;
	bool stopping;
	
	vector <TriggerBase*> triggers;
	vector <TriggerBase*> triggersLeft;
	vector <TriggerBase*> triggersRight;
	
	
	ParticleSystemManager& particleSystemManager;
	ofRectangle triggerArea;
	float minimumSpacing; 
		
	TriggerPattern triggerPattern;
	int triggerCount;

	
};