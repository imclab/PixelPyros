//
//  Trigger.cpp
//  ParticlePlay4
//
//  Created by Seb Lee-Delisle on 02/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//

#include "TriggerRocket.h"


TriggerRocket :: TriggerRocket (ParticleSystemManager& psm, float triggerRadius) : TriggerSimple(psm, triggerRadius){
	
	typeLabel = "TriggerRocket"; 
	
	currentRocketIndex = 0;
	useAllPower = false;
	
	
}
void TriggerRocket::draw() {
	
	if(!active) return;
    
    TriggerSimple::draw() ;
}

bool TriggerRocket::doTrigger() { 
	
	if(!TriggerSimple :: doTrigger()) return false;
	if(rocketSettings.size()==0) return false;
	
	PhysicsObject *rocket = makeNewRocket(); 
	
	return true; 
}

PhysicsObject * TriggerRocket:: makeNewRocket() {
	
	RocketSettings & rs = rocketSettings[currentRocketIndex];
	currentRocketIndex++;
	if(currentRocketIndex==rocketSettings.size()) currentRocketIndex = 0;

	PhysicsObject *rocket = particleSystemManager.getPhysicsObject();
	
	float power = ofRandom(1);
	
	if(rs.mode == ROCKET_MODE_PHYSICS) {
		rocket->vel.set(ofMap(power, 0, 1, rs.startSpeedMin, rs.startSpeedMax),0,0);
		rocket->vel.rotate(0,0,ofRandom(rs.direction - rs.directionVar, rs.direction+rs.directionVar));
		rocket->gravity = rs.gravity;
		rocket->drag = rs.drag;
	} else if(rs.mode == ROCKET_MODE_TARGET) {
		rocket->drag = 1;
		rocket->gravity.set(0,0,0);
		rocket->vel = (rs.targetPos - pos) / rs.targetSpeed;
		//cout << "rocket vel " << rocket->vel.x << " " << rocket->vel.y << endl;
		
		
	}
		
		
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
	

	
	return rocket; 
	
	
}

void TriggerRocket:: addRocketSettings(RocketSettings rocket) {
	
	rocketSettings.push_back(rocket);
	
	
}
