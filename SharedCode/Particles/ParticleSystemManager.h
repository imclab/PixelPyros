//
//  ParticleSystemManager.h
//  SceneCalibration
//
//  Created by Seb Lee-Delisle on 03/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once; 

#include "ParticleSystem.h"


class ParticleSystemManager { 

public:
	
    ParticleSystemManager(SoundPlayer& sp) : soundPlayer(sp) {
    
        activeParticleCount = 0;
		activePhysicsObjectCount = 0; 
        
    }
	
	void update(float deltaTime) {
		
        activeParticleCount  =0 ; 
		
		
		activePhysicsObjectCount = 0;
		
		if ( killAllParticlesFlag )
		{
			killAllParticles () ;
			killAllParticlesFlag = false ;
		}
		
		for(int i = 0; i<particleSystems.size(); i++) { 
			
			ParticleSystem* ps = particleSystems[i]; 
			if(ps->finished) continue; 
			
			
			// SOMEHOW... the ParticleSystem has to report what sounds to make...
			// maybe just pass in a reference to the soundPLayer into all ParticleSystems? 
			ps->update(deltaTime);
			
			
			
            activeParticleCount+=ps->activeParticleCount;
			
			if(ps->finished) { 
				spareParticleSystems.push_back(ps); 
			}
			
			
		}
		
		for(int i = 0; i<physicsObjects.size(); i++) {
			
			PhysicsObject* po = physicsObjects[i];
			if(!po->enabled) continue;
			activePhysicsObjectCount++;
			
			po->update(deltaTime);
			
			if(!po->enabled) {
				sparePhysicsObjects.push_back(po);
			}
			
			
		}
		
		
		
	}
	
	void draw() { 
		
		
		for(int i = 0; i<particleSystems.size(); i++) { 
			
			ParticleSystem* ps = particleSystems[i]; 
			if(ps->finished) continue; 
		
			ps->draw(); 
		}
		
//		
//		for(int i = 0; i<physicsObjects.size(); i++) { 
//			
//			PhysicsObject* po = physicsObjects[i]; 
//			if(!po->enabled) continue; 
//			
//			po->update(deltaTime); 
//			
//			if(!po->enabled) { 
//				sparePhysicsObjects.push_back(po); 
//			}
//			
//			
//		}

		
		
	}
	
	void killAllParticles ()
	{
		for(int i = 0; i<particleSystems.size(); i++) { 
			
			ParticleSystem* ps = particleSystems[i]; 
			if(ps->finished) continue; 
			
			ps->life.end () ;
		}

	}
	
	ParticleSystem * getParticleSystem() { 
		
		ParticleSystem * ps; 
		if(spareParticleSystems.size()>0) {
			ps = spareParticleSystems.back(); 
			spareParticleSystems.pop_back();
			ps->reset();
		} else { 
			
			ps = new ParticleSystem(soundPlayer); 
			particleSystems.push_back(ps); 
		
		}
		
		return ps; 
		
				
	}
	
	PhysicsObject * getPhysicsObject() { 
		
		PhysicsObject * po; 
		if(sparePhysicsObjects.size()>0) {
			po = sparePhysicsObjects.back(); 
			sparePhysicsObjects.pop_back(); 
			po->reset(); 
		} else { 
			
			po = new PhysicsObject(); 
			physicsObjects.push_back(po); 
			
		} 
		
		return po; 
		
		
	}
	
	
	vector <ParticleSystem *> particleSystems; 
	vector <ParticleSystem *> spareParticleSystems; 

	vector <PhysicsObject *> physicsObjects; 
	vector <PhysicsObject *> sparePhysicsObjects; 

	bool killAllParticlesFlag;
	
    int activeParticleCount;
	int activePhysicsObjectCount;
	
	SoundPlayer& soundPlayer;


};