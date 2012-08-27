//
//  TriggerRotator.h
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 25/08/2012.
//
//

#pragma once
#include "TriggerRocket.h"


class TriggerRotator : public TriggerRocket {

	public :
	TriggerRotator(ParticleSystemManager & psm, float extent = 10, float speed = 2,
		bool rotateonfire = false) : TriggerRocket(psm) {
		
		typeLabel = "TriggerRocket";
		
		rotationExtent = extent;
		rotationSpeed = speed;
		rotateOnFire = rotateonfire;
		minTriggerInterval = 0.1;
		
		rocketCount = 0; 
		
	}
	
	void start() {
		TriggerRocket::start();
		angle = -90;
		displayAngle = -90;

	}
	bool update(float deltaTime) {
		
		
		if(!rotateOnFire) {
			angle = (sin(elapsedTime*rotationSpeed)*rotationExtent)-90;
		}
		
		displayAngle+=((angle-displayAngle)*0.1);
		
		return TriggerRocket::update(deltaTime);
		
	}
	
	void draw() {
		if(!active) return;

		TriggerRocket::draw();
		
		ofPushStyle();
		ofPushMatrix();
		
		ofTranslate(pos);
		ofScale(scale, scale);
		ofRotate(displayAngle);
		ofLine(0,0,20,0); 

		
		ofPopStyle();
		ofPopMatrix();
		
	};
	
	
	bool doTrigger() {
		
//		if(unitPower<=triggerPower) return false;
//		else if (elapsedTime - lastTriggerTime < minTriggerInterval) return false;
//		
		if(rocketSettings.size()==0) return false;
		
		
		RocketSettings & rs = rocketSettings[currentRocketIndex];
		currentRocketIndex++;
		if(currentRocketIndex==rocketSettings.size()) currentRocketIndex = 0;
		
		PhysicsObject *rocket = particleSystemManager.getPhysicsObject();
		
		rocket->vel.set(ofRandom(rs.startSpeedMin, rs.startSpeedMax),0,0);
		
		if(rotateOnFire) {
			angle = (sin(rocketCount/2*rotationSpeed)*rotationExtent)-90;
			//cout << "rotateOnFire " << angle << " " << rocketCount << endl;
		}
	
		rocket->vel.rotate(0,0, +angle );
		
		rocket->gravity = rs.gravity;
		rocket->drag = rs.drag;
		rocket->pos.set(20,0,0);
		rocket->pos.rotate(0,0,displayAngle);
		rocket->pos+=pos;
		rocket->lastPos.set(pos);
		rocket->life.lifeTime = rs.lifeTime;
		
		for(int i = 0; i<rs.particleSystemSettings.size(); i++) {
			ParticleSystemSettings pss = rs.particleSystemSettings[i];
			
			ParticleSystem* ps = particleSystemManager.getParticleSystem();
			
			//pss.hueStartMin = pss.hueStartMax = ofRandom(255);
			ps->init(pss);
			ps->attachedPhysicsObject = rocket;
		}
		//unitPower-=triggerPower;
		
		
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
	float displayAngle; 






};