//
//  Rocket.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 31/07/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once

#include "ParticleSystem.h"
#include "Physics.h"

class Rocket { 

	public: 
		
		Rocket() { 
		
			trail = new ParticleSystem(); 
			explode = new ParticleSystem(); 
			
			trail->life.lifeTime = 1.5; 
			explode->life.delay = 1.5; 
			explode->life.lifeTime = 0.1; 
			trail->newParticleCountPerFrame = 20; 
			explode->newParticleCountPerFrame = 500; 
			
			
			particleSystems.push_back(trail);
			particleSystems.push_back(explode); 
			
			reset(); 
			
		};
		
		void reset(float x=0, float y=0, float z=0) {
			pos.set(x,y,z); 
			elapsedTime = 0; 
			physics.reset(); 
			
			for(int i = 0; i<particleSystems.size(); i++) { 
				particleSystems[i]->reset();
			}
			
		};
		
		bool update(float deltaTime) { 
			physics.update(pos, deltaTime); 
			
			for(int i = 0; i<particleSystems.size(); i++) { 
				particleSystems[i]->pos = pos;
				particleSystems[i]->update(deltaTime);
				
				
			}
		};
			  
		bool draw() { 
			
			ofRect(pos.x,pos.y, 10, 10);
			for(int i = 0; i<particleSystems.size(); i++) { 
				particleSystems[i]->draw(); 
				
			}
			  
		};
	
	ofVec3f pos; 
	Physics physics; 
	vector <ParticleSystem*> particleSystems; 
	float elapsedTime; 

	ParticleSystem * trail;
	ParticleSystem * explode;


};