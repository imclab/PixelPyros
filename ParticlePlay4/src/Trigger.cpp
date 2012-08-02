//
//  Trigger.cpp
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Trigger.h"


bool Trigger::update(float deltaTime) { 

	for(int i = 0; i<physicsObjects.size(); i++) { 
		PhysicsObject * rocket = physicsObjects[i]; 
		if(!rocket->enabled) continue; 
		rocket->update(deltaTime); 
		
		if(rocket->pos.y>ofGetHeight()) { 
			sparePhysicsObjects.push_back(rocket); 
			rocket->enabled = false; 
		}
		
	}
	for(int i = 0; i<particleSystems.size(); i++) { 
		
		ParticleSystem * ps = particleSystems[i];
		if(ps->finished) continue; 
		ps->update(deltaTime); 
		if(ps->finished) { 
			spareParticleSystems.push_back(ps); 
		}
		
	}
}

void Trigger::draw() { 

	for(int i = 0; i<particleSystems.size(); i++) { 
		particleSystems[i]->draw(); 
	}
	
	
	for(int i = 0; i<physicsObjects.size(); i++) { 
		//ofCircle(physicsObjects[i]->pos, 2); 
		
		//update(deltaTime); 
	}



}


void Trigger::makeRocket() { 
	
	RocketSettings & rs = rocketSettings; 
	
	
	PhysicsObject *rocket; 
	
	if(sparePhysicsObjects.size()>0) {
		rocket = sparePhysicsObjects.back();
		sparePhysicsObjects.pop_back();
		rocket->reset();
	} else {
		rocket = new PhysicsObject();
		physicsObjects.push_back(rocket); 
		
	}
	
	rocket->vel.set(ofRandom(rs.startSpeedMin, rs.startSpeedMax),0,0); 
	rocket->vel.rotate(0,0,ofRandom(rs.direction - rs.directionVar, rs.direction+rs.directionVar)); 
	rocket->gravity = rs.gravity; 
	rocket->drag = rs.drag; 
	rocket->pos.set((ofGetWidth()/2), ofGetHeight() *0.9); 
	
	
	
	for(int i = 0; i<rs.particleSystemSettings.size(); i++) { 
		ParticleSystemSettings pss = rs.particleSystemSettings[i]; 
		
		ParticleSystem* ps; 
		if(spareParticleSystems.size()>0) { 
			ps = spareParticleSystems.back(); 
			spareParticleSystems.pop_back(); 
			ps->reset();
		} else {
			ps = new ParticleSystem(); 
			particleSystems.push_back(ps); 
			
		}
		
		
		
		//pss.hueStartMin = pss.hueStartMax = ofRandom(255); 
		ps->init(pss);
		ps->attachedPhysicsObject = rocket; 
	}
	
	
	
}