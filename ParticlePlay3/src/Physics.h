//
//  Physics.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 30/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once
#include "ofMain.h"

class Physics { 

	public : 
	
	Physics() { 
		reset(); 
		
		dragApplyFrequency = 30; 
		
		vel.set(0,0,0); 
		drag = 1; 
		gravity.set(0,0,0); 
		
	}; 
	
	void reset() { 

	
		dragApplyCount = 0; 
		elapsedTime = 0; 
		
	};
	
	void update(ofVec3f& pos, float deltaTime) { 
		vel+=gravity*deltaTime; 
		pos+=vel*deltaTime; 
		elapsedTime+=deltaTime; 
		
		while((elapsedTime * dragApplyFrequency) > dragApplyCount) { 
			vel*=drag; 
			dragApplyCount++; 
		}
		
	};
	
	ofVec3f vel; 
	float drag; 
	ofVec3f	gravity; 
	
	
	int dragApplyCount;
	float dragApplyFrequency; 
	float elapsedTime;
	
	
};