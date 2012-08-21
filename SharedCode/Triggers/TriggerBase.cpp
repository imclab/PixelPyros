//
//  Trigger.cpp
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "TriggerBase.h"


TriggerBase :: TriggerBase (ParticleSystemManager& psm) : particleSystemManager(psm){
	
	
	// the power level for the trigger
	unitPower =1;
	// the amount of power a rocket takes away
	rocketPower = 0.2; 
	elapsedTime = 0; 
	lastRocketTime = 0; 
	minTimeBetweenRockets = 0.3; 
	
	elapsedTime = 0; 
	
	type = TRIGGER_TYPE_FIRE_ON_MOTION; 
	
	restoreSpeed = 0.2; 
	triggerLevel = 0.5; 
	stopping = false; 
	active = false; 
	scale = 0; 
	radius = 5; 
	chargeOnMotion = 0;
	chargeAmount = 1; 
	motionDecay = 1;
	
	
}

void TriggerBase:: start() { 

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

void TriggerBase:: stop() { 
	
	stopping = true; 
	
}

bool TriggerBase::update(float deltaTime) { 
	
	if(!active) return false; 
	
	
	elapsedTime+=deltaTime;
	
	// scale up / down on start stop
	if(stopping) {
		scale-=deltaTime*1;
		if(scale<=0.0) {
			scale = 0;
			active = false;
			return false; 
		}
	} else { 
		scale+= (1-scale)*0.01;
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

void TriggerBase::draw() { 

	ofPushStyle(); 
	ofPushMatrix();
    
	ofTranslate(pos); 
	ofScale(scale, scale); 
	ofEnableSmoothing();
    
//    
//	ofSetColor(ofColor::red);
//    ofNoFill();
//    ofBeginShape();
//    ofVertex(0, 0);
//    for(float i=0; i<360*motionLevel; i+=10){
//        
//        ofVertex(cosf(ofDegToRad(i))*(radius+2),sinf(ofDegToRad(i))*(radius+2));
//        
//    }
//    ofEndShape(); 
    
    
    ofSetColor(ofColor::white);
    
	if((unitPower>rocketPower) || (fmodf(elapsedTime,0.16) < 0.08) || (restoreSpeed==0) || (type == TRIGGER_TYPE_FIRE_ON_CHARGE)) {
		
		ofCircle(0, 0, radius*unitPower); 
		ofNoFill(); 
		ofCircle(0, 0, radius*unitPower);

	} else {
		ofNoFill();
		ofSetColor(100); 
	}
	
	ofCircle(0, 0, radius); 
	ofPopStyle(); 
	ofPopMatrix();
}


void TriggerBase :: registerMotion(float unitValue) { 
	motionLevel+=unitValue;
	unitPower += unitValue*chargeOnMotion; 
	
}

bool TriggerBase::makeRocket() { 
	
	
	if(unitPower<=rocketPower) return false; 
	else if (elapsedTime - lastRocketTime < minTimeBetweenRockets) return false; 
	
	if(rocketSettings.size()==0) return false;
	
	
	RocketSettings & rs = rocketSettings[0];
	
	PhysicsObject *rocket = particleSystemManager.getPhysicsObject(); 
	
	rocket->vel.set(ofRandom(rs.startSpeedMin, rs.startSpeedMax),0,0); 
	rocket->vel.rotate(0,0,ofRandom(rs.direction - rs.directionVar, rs.direction+rs.directionVar)); 
	rocket->gravity = rs.gravity; 
	rocket->drag = rs.drag; 
	rocket->pos.set(pos);
	rocket->lastPos.set(pos);
	
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

void TriggerBase:: addRocket(RocketSettings rocket) {
	
	rocketSettings.push_back(rocket);
	
	
}
