//
//  Trigger.cpp
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "Trigger.h"


Trigger :: Trigger (ParticleSystemManager& psm) : particleSystemManager(psm) { 
	
	unitPower =1; 
	rocketPower = 0.2; 
	elapsedTime = 0; 
	lastRocketTime = 0; 
	minTimeBetweenRockets = 0.1; 
	
	type = TRIGGER_TYPE_FIRE_ON_MOTION; 
	
	restoreSpeed = 0.2; 
	triggerLevel = 0.5; 
	stopping = false; 
	active = false; 
	scale = 0; 
	
	chargeOnMotion = 0;
	chargeAmount = 1; 
	motionDecay = 0.4; 
	
	
}

void Trigger:: start() { 

	stopping = false; 
	scale = 0; 
	
	active = true; 
	motionLevel = 0; 
	
	if(type == TRIGGER_TYPE_FIRE_ON_CHARGE) { 
		unitPower = 0; 
	} else if(type == TRIGGER_TYPE_FIRE_ON_MOTION) { 
		unitPower = 1; 
	}
	
}

void Trigger:: stop() { 
	
	stopping = true; 
	
}

bool Trigger::update(float deltaTime) { 
	
	if(!active) return false; 
	
	
	elapsedTime+=deltaTime;
	
	// scale up / down on start stop
	if(stopping) {
		scale-=deltaTime;
		if(scale<=0) {
			scale = 0;
			active = false;
			return false; 
		}
	} else { 
		scale+= (1-scale)*0.05; 
	}

	
	if(type == TRIGGER_TYPE_FIRE_ON_MOTION) { 
		unitPower+=restoreSpeed * deltaTime; 
		if(unitPower>1) unitPower = 1; 


		if(motionLevel >= triggerLevel) { 
			if(makeRocket()) { 
				motionLevel = 0; 
		
				if(restoreSpeed==0) { 
					// this trigger is a one shot so stop it
					stop(); 
			
				}
			}
		}

		motionLevel -= motionDecay*deltaTime; 
		if(motionLevel<0) motionLevel = 0; 

	} else if(type == TRIGGER_TYPE_FIRE_ON_CHARGE) { 
		unitPower+=(motionLevel*deltaTime*chargeAmount); 
		motionLevel = 0; 
		if(unitPower>=triggerLevel) { 
			if(makeRocket()) { 
				unitPower = 0; 
				
			}
			
		}
		
		
	}
	
	
	return active;
}

void Trigger::draw() { 

	ofPushStyle(); 
	ofPushMatrix(); 
	ofSetColor(255);
	ofTranslate(pos); 
	ofScale(scale, scale); 
	ofEnableSmoothing(); 
	if((unitPower>rocketPower) || (fmodf(elapsedTime,0.16) < 0.08)) {
		
		ofCircle(0, 0, 10*unitPower); 
		ofNoFill(); 
		ofCircle(0, 0, 10*unitPower);

	} else {
		ofNoFill();
		ofSetColor(100); 
	}
	
	ofCircle(0, 0, 10); 
	ofPopStyle(); 
	ofPopMatrix();
}


void Trigger :: registerMotion(float unitValue) { 
	motionLevel+=unitValue;
	unitPower += unitValue*chargeOnMotion; 
	
}

bool Trigger::makeRocket() { 
	
	
	if(unitPower<=rocketPower) return false; 
	else if (elapsedTime - lastRocketTime < minTimeBetweenRockets) return false; 
	
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
	unitPower-=rocketPower; 
	lastRocketTime = elapsedTime; 
	return true; 
}


