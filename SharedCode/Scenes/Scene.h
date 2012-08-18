//
//  Scene.h
//  SceneTest
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once 

#include "TriggerBase.h"
#include "ParticleSystemManager.h"
#include "MotionManager.h"
#include "ofxCV.h"



class Scene { 


	public : 
	
	Scene(ParticleSystemManager& psm); 
	
	void start(); 
	void stop();
	
	bool update(float deltaTime); 
	void draw(); 
	
	void updateMotion(MotionManager& motionManager, cv::Mat homography);
	
	template <typename T>  
	void addTriggers(T trigger, int numTriggers, float x, float y, float width){
		
		float spacing = width/(numTriggers -1);
		
		
		for(int i = 0; i<numTriggers; i++) { 
			
			T * newtrigger = new T(trigger);
			triggers.push_back(newtrigger); 
			
			// TODO make this height adjustable somehow 
			newtrigger->pos.set(x, y); 
			x+=spacing; 
			
			
		}
		
		
	}; 
	
	bool active; 
	bool stopping; 
	
	vector <TriggerBase*> triggers; 
	
	ParticleSystemManager& particleSystemManager; 
	

};