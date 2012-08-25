//
//  Physics.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once
#include "ofMain.h"
#include "LifeCycle.h"
//class PhysicsObjectRenderer;

class PhysicsObject { 

	public : 
	
	PhysicsObject() { 
		reset(); 
		
		dragApplyFrequency = 30; 
		pos.set(0,0,0); 
		lastPos.set(0,0,0); 
		vel.set(0,0,0); 
		drag = 1; 
		gravity.set(0,0,0);
		
	}; 
	
	virtual void reset() { 
		dragApplyCount = 0; 
		elapsedTime = 0; 
		enabled = true;
		life.reset();
		
		//renderer = NULL;
	};
	
	virtual bool update(float deltaTime) {
		
		life.update(deltaTime);
		
		lastPos = pos; 
		vel+=gravity*deltaTime; 
		pos+=vel*deltaTime; 
		elapsedTime+=deltaTime; 
		
		while((elapsedTime * dragApplyFrequency) > dragApplyCount) { 
			vel*=drag; 
			dragApplyCount++; 
		}
		
		if(life.isFinished()) enabled = false;
		
		return enabled; 
	};
	
	ofVec3f pos; 
	ofVec3f lastPos; 
	ofVec3f vel; 
	float drag; 
	ofVec3f	gravity; 
	
	LifeCycle life;
	
	
	int dragApplyCount;
	float dragApplyFrequency; 
	float elapsedTime;
	bool enabled;
	
	//PhysicsObjectRenderer* renderer;
	
};