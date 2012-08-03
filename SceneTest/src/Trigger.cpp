//
//  Trigger.cpp
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Trigger.h"


Trigger :: Trigger (ParticleSystemManager& psm) : particleSystemManager(psm) { 
	
	
}

bool Trigger::update(float deltaTime) { 

}

void Trigger::draw() { 

	ofCircle(pos, 10); 



}


void Trigger::makeRocket() { 
	
	RocketSettings & rs = rocketSettings; 
	
	
	PhysicsObject *rocket = particleSystemManager.getPhysicsObject(); 
	
		
	rocket->vel.set(ofRandom(rs.startSpeedMin, rs.startSpeedMax),0,0); 
	rocket->vel.rotate(0,0,ofRandom(rs.direction - rs.directionVar, rs.direction+rs.directionVar)); 
	rocket->gravity = rs.gravity; 
	rocket->drag = rs.drag; 
	rocket->pos.set(pos); 
	
	
	
	for(int i = 0; i<rs.particleSystemSettings.size(); i++) { 
		ParticleSystemSettings pss = rs.particleSystemSettings[i]; 
		
		ParticleSystem* ps = particleSystemManager.getParticleSystem(); 

		//pss.hueStartMin = pss.hueStartMax = ofRandom(255); 
		ps->init(pss);
		ps->attachedPhysicsObject = rocket; 
	}
	
	
	
}