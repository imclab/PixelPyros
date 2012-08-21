//
//  Scene.h
//  SceneTest
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "Arrangement.h"
#include "ParticleSystemManager.h"
#include "MotionManager.h"
#include "ofxCV.h"



class Scene { 


	public : 
	
	Scene(ParticleSystemManager& psm, ofRectangle triggerarea);
	
	virtual void start();
	virtual void stop();
	
	virtual bool update(float deltaTime); 
	virtual void draw(); 
	
	virtual void updateMotion(MotionManager& motionManager, cv::Mat homography);
	
	bool startArrangement(int num);
	
	Arrangement& addArrangement(TriggerPattern& pattern);
	
	void setTriggerArea(ofRectangle rect);

	bool next();
	bool previous(); 
	
	bool active; 
	bool stopping; 
	
	vector <Arrangement*> arrangements;
	int currentArrangementIndex; 
	
	ParticleSystemManager& particleSystemManager; 
	
	ofRectangle triggerArea; 

};