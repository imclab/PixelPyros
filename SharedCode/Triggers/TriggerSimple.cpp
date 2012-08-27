
#include "TriggerSimple.h"


TriggerSimple :: TriggerSimple (ParticleSystemManager& psm) : TriggerBase(psm){
	
	typeLabel = "TriggerSimple";
	// the power level for the trigger
	unitPower =1;
	// the amount typename = "TriggerRocket"; of power a rocket takes away
	triggerPower = 0.2;
	elapsedTime = 0;
	lastTriggerTime = 0;
	minTriggerInterval = 0.3;
	
	elapsedTime = 0;
	
	type = TRIGGER_TYPE_FIRE_ON_MOTION;
	
	restoreSpeed = 0.2;
	triggerLevel = 0.5;
	stopping = false;
	active = false;
	scale = 0;
	radius = 5;
	motionSensitivity = 0;
	
	motionDecay = 1;
	
}

void TriggerSimple :: start() {
	
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

void TriggerSimple :: stop() {
	
	stopping = true;
	
}

bool TriggerSimple::update(float deltaTime) {

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
		scale+= (1-scale)*0.1;
	}
	
	
	if(type == TRIGGER_TYPE_FIRE_ON_MOTION) {
		unitPower+=restoreSpeed * deltaTime;
		if(unitPower>1) unitPower = 1;
		
		
		// we need to have sensed motion,
		// AND we need to have enough unitPower to trigger
		if( (!stopping) &&
		    (scale>0.99) &&
		    (motionLevel >= triggerLevel) &&
		    (unitPower>=triggerPower) &&
		    (elapsedTime - lastTriggerTime > minTriggerInterval) ) {
			
			if(doTrigger()) {
				motionLevel = 0;
				unitPower-=triggerPower;
				lastTriggerTime = elapsedTime;
				
				if(restoreSpeed==0) {
					// this trigger is a one shot so stop it
					stop();
					
				}
			}
		}
		
		motionLevel -= motionDecay*deltaTime;
		if(motionLevel<0) motionLevel = 0;
		
	}
	
	
	//	else if(type == TRIGGER_TYPE_FIRE_ON_CHARGE) {
	//		unitPower+=(motionLevel*deltaTime*motionSensitivity);
	//		motionLevel = 0;
	//		if(unitPower>=triggerLevel) {
	//			if(doTrigger()) {
	//				unitPower = 0;
	//
	//			}
	//
	//		}
	//
	//
	//	}
	//
	
	return active;
}

void TriggerSimple :: draw() {

	if(!active) return;

	
	ofPushStyle();
	ofPushMatrix();
    
	ofTranslate(pos);
	ofScale(scale, scale);
	ofEnableSmoothing();
	ofDisableBlendMode();
        
    ofSetColor(ofColor::white);
    
	if((unitPower>triggerPower) || (fmodf(elapsedTime,0.16) < 0.08) || (restoreSpeed==0) || (type == TRIGGER_TYPE_FIRE_ON_CHARGE)) {
		
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


void TriggerSimple :: registerMotion(float unitValue) {
	
	if(!active) return;

	motionLevel+=unitValue;
	unitPower += unitValue*motionSensitivity;
	
}

bool TriggerSimple::doTrigger() {
	return true;
}
