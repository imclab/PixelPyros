//
//  ParticleSystemManager.h
//  SceneTest
//
//  Created by Seb Lee-Delisle on 03/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#pragma once; 

#include "ParticleSystem.h"


class ParticleSystemManager { 

public:
	
	
	void update(float deltaTime) { 
		
	
		
		for(int i = 0; i<physicsObjects.size(); i++) { 
			
			PhysicsObject* po = physicsObjects[i]; 
			if(!po->enabled) continue; 
			
			po->update(deltaTime); 
			
			if(!po->enabled) { 
				sparePhysicsObjects.push_back(po); 
			}
			
			
		}

		
		
		for(int i = 0; i<particleSystems.size(); i++) { 
			
			ParticleSystem* ps = particleSystems[i]; 
			if(ps->finished) continue; 
			
			ps->update(deltaTime); 
			
			if(ps->finished) { 
				spareParticleSystems.push_back(ps); 
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
	
	
	
	ParticleSystem * getParticleSystem() { 
		
		ParticleSystem * ps; 
		if(spareParticleSystems.size()>0) {
			ps = spareParticleSystems.back(); 
			spareParticleSystems.pop_back(); 
		} else { 
			
			ps = new ParticleSystem(); 
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




};