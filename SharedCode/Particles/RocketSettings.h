//
//  RocketSettings.h
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 01/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

class RocketSettings { 

	public:
	
	RocketSettings() { 
		
		startSpeedMin = 100; 
		startSpeedMax = 100; 
		direction = -90; 
		directionVar = 10; 
		gravity.set(0,0,0); 
		drag = 1;
		lifeTime = 2;
	//	renderer = NULL;
		
		
	};

	ParticleSystemSettings * addParticleSystemSetting(const ParticleSystemSettings& pss) {
		
		particleSystemSettings.push_back(ParticleSystemSettings(pss));
		
		if(lifeTime <  pss.emitDelay + pss.emitLifeTime) {
			
			lifeTime = pss.emitDelay + pss.emitLifeTime;
			
		}
		
		return &particleSystemSettings.back(); 
		
	};
	

	float startSpeedMin; 
	float startSpeedMax; 
	float direction; 
	float directionVar;
	float lifeTime; 
	
	ofVec3f gravity; 
	float	drag;
	
	//PhysicsObjectRenderer* renderer;
	
	vector <ParticleSystemSettings> particleSystemSettings;



}; 