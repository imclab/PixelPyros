//
//  Scene1.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 14/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once

#include "Scene.h"
#include "BasicRocket.h"
#include "TriggerSimple.h"
#include "StretchyNet.h"

class Scene2 : public Scene {
	
	public : 
	
	Scene2(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
		
		BasicRocket rocketSettings(100,10, 120);
		
		TriggerSimple trigger(particleSystemManager);
		
		trigger.addRocket(rocketSettings);
		// makes one shot type
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger.triggerLevel = 1;
		trigger.restoreSpeed = 0.5;
		trigger.rocketPower = 0.99;
		
		trigger.chargeAmount = 2; 
	
		//addTriggers(trigger, 50, 100,ofGetHeight()*0.85, ofGetWidth()-160);
		TriggerPattern pattern;
		pattern.addTrigger(trigger);
		addArrangement(pattern);
		
		stretchyNet.init(ofRectangle(0,0,APP_WIDTH, APP_HEIGHT));
						

		
	}
	
	
	bool update(float deltaTime) {
		if(!Scene::update(deltaTime)) return false;
		
		stretchyNet.update(deltaTime, particleSystemManager);
		
		
	}
	
	bool draw() {
		if(!Scene::draw()) return false;
		   
		ofPushStyle();
		//ofEnableSmoothing();
		ofEnableBlendMode(OF_BLENDMODE_ADD);
		stretchyNet.draw();
		ofPopStyle(); 
		
	}
	
	StretchyNet stretchyNet; 
	
	
};