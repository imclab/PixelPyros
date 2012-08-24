//
//  Scene1.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 14/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once

#include "Scene.h"
#include "RocketTron.h"

#include "RocketTronFountain.h"
#include "TriggerSimple.h"
#include "StretchyNet.h"
#include "ParticleRendererSquare.h"

class SceneTron : public Scene {
	
	public : 
	
	SceneTron (ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
		
		RocketTron rocketSettings(100,10, 120 );
		
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
		
		
		TriggerSimple trigger2(particleSystemManager);
		trigger2.addRocket(RocketTronFountain());
		trigger2.restoreSpeed = 2;
		
		pattern.addTrigger(trigger2);
		
		
		
		
		
		
		
		
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
	ParticleRendererSquare renderer;
	
};