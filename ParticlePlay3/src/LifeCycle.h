//
//  LifeCycle.h
//  ParticlePlay3
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

class LifeCycle { 
	
	public : 
	
	LifeCycle() { 
		
		lifeTime = 1; 
		delay = 0; 

		reset(); 
		
	};
	
	void reset() { 
		
		elapsedTime = 0; 
		active = false; 
		
	};
	
	bool update(float deltaTime) { 
		elapsedTime +=deltaTime; 
		if((elapsedTime>delay) && (elapsedTime<delay+lifeTime)) { 
			active = true; 
		} else { 
			active = false; 
		}
		
		unitLifeProgress = ofMap(elapsedTime, delay, delay+lifeTime, 0,1,true); 
		
		return active; 
	};
	
	bool isFinished() { 
		
		return (elapsedTime>delay+lifeTime); 
			
	}
	
	bool active; 
	float lifeTime; 
	float elapsedTime; 
	float unitLifeProgress; 
	float delay; 
	
}; 

