//
//  Trigger.cpp
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "TriggerRocket.h"


TriggerRocket :: TriggerRocket (ParticleSystemManager& psm) : TriggerSimple(psm){
	
	typeLabel = "TriggerRocket"; 
	
	currentRocketIndex = 0;
	useAllPower = false;
	
	
}
void TriggerRocket::draw() {
	
	if(!active) return;

	ofPushStyle(); 
	ofPushMatrix();
    
	ofTranslate(pos); 
	ofScale(scale, scale); 
	ofEnableSmoothing();
	ofDisableBlendMode();
        
    ofSetColor(ofColor::white);
    
	if((unitPower>=triggerPower) || (fmodf(elapsedTime,0.16) < 0.08) || (restoreSpeed==0) || (type == TRIGGER_TYPE_FIRE_ON_CHARGE)) {
		
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

bool TriggerRocket::doTrigger() { 
	
	if(rocketSettings.size()==0) return false;
	
	RocketSettings & rs = rocketSettings[currentRocketIndex];
	currentRocketIndex++;
	if(currentRocketIndex==rocketSettings.size()) currentRocketIndex = 0; 
	
	PhysicsObject *rocket = particleSystemManager.getPhysicsObject(); 
	
	float power = ofRandom(1); 
	rocket->vel.set(ofMap(power, 0, 1, rs.startSpeedMin, rs.startSpeedMax),0,0);
	rocket->vel.rotate(0,0,ofRandom(rs.direction - rs.directionVar, rs.direction+rs.directionVar)); 
	rocket->gravity = rs.gravity; 
	rocket->drag = rs.drag; 
	rocket->pos.set(pos);
	rocket->lastPos.set(pos);
	rocket->life.lifeTime = rs.lifeTime;
	
	for(int i = 0; i<rs.particleSystemSettings.size(); i++) { 
		ParticleSystemSettings pss = rs.particleSystemSettings[i]; 
		
		ParticleSystem* ps = particleSystemManager.getParticleSystem(); 
		
		//pss.hueStartMin = pss.hueStartMax = ofRandom(255); 
		ps->init(pss);
		ps->attachedPhysicsObject = rocket; 
		ps->power = power;
	}
	

	return true; 
}

void TriggerRocket:: addRocketSettings(RocketSettings rocket) {
	
	rocketSettings.push_back(rocket);
	
	
}
