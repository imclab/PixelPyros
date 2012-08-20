//
//  Arrangement.h
//  ParticlePlay5
//
//  Created by Seb Lee-Delisle on 20/08/2012.
//
//


#pragma once

#include "TriggerBase.h"
#include "TriggerPattern.h"

#include "ParticleSystemManager.h"
#include "MotionManager.h"
#include "ofxCV.h"

class Arrangement {
	
	public :
	
	Arrangement(ParticleSystemManager& psm);
	
	virtual void start();
	virtual void stop();
	
	virtual bool update(float deltaTime);
	virtual void draw();
	
	virtual void updateMotion(MotionManager& motionManager, cv::Mat homography);
	
	virtual void setPattern(TriggerPattern tp);
	
	template <typename T>
	T* addTrigger(T trigger);
	
	
	bool active;
	bool stopping;
	
	vector <TriggerBase*> triggers;
	
	ParticleSystemManager& particleSystemManager;

	
};