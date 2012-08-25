//
//  TriggerRotator.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 25/08/2012.
//
//

#pragma once
#include "TriggerSimple.h"


class TriggerRotator : public TriggerSimple {

	public :
	TriggerRotator(ParticleSystemManager & psm, float extent = 10, float speed = 2,
		bool rotateonfire = false) : TriggerSimple(psm) {
		
		typeLabel = "TriggerSimple";
		
		rotationExtent = extent;
		rotationSpeed = speed;
		rotateOnFire = rotateonfire;
		minTimeBetweenRockets = 0.1;
		
		
	}

	bool update(float deltaTime) {
		
		
		if(!rotateOnFire) {
			angle = (sin(elapsedTime*rotationSpeed)*rotationExtent)-90;
		}
		
		return TriggerSimple::update(deltaTime);
		
	}
	
	void draw() {
		TriggerSimple::draw();
		
		ofPushStyle();
		ofPushMatrix();
		
		ofTranslate(pos);
		ofScale(scale, scale);
		ofRotate(angle);
		ofLine(0,0,20,0); 

		
		ofPopStyle();
		ofPopMatrix();
		
	};
	
	
	bool makeRocket() {
		
		if(unitPower<=rocketPower) return false;
		else if (elapsedTime - lastRocketTime < minTimeBetweenRockets) return false;
		
		if(rocketSettings.size()==0) return false;
		
		
		RocketSettings & rs = rocketSettings[currentRocketIndex];
		currentRocketIndex++;
		if(currentRocketIndex==rocketSettings.size()) currentRocketIndex = 0;
		
		PhysicsObject *rocket = particleSystemManager.getPhysicsObject();
		
		rocket->vel.set(ofRandom(rs.startSpeedMin, rs.startSpeedMax),0,0);
		
		if(rotateOnFire) angle = (sin(rocketCount/2*rotationSpeed)*rotationExtent)-90;
	
	
		rocket->vel.rotate(0,0, +angle );
		
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
		}
		unitPower-=rocketPower;
		lastRocketTime = elapsedTime;
		
		rocketCount++; 
		return true; 
	}

	virtual TriggerRotator* clone() const{
		//cout << "clone TriggerRotator"<< endl;
		return new TriggerRotator( *this );
	}

	
	float rotationExtent;
	float rotationSpeed;
	float rocketCount;
	bool rotateOnFire;
	float angle; 






};