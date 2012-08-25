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
#include "RocketFountain.h"
#include "TriggerRotator.h"

class SceneTron : public Scene {
	
	public : 
	
	SceneTron (ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
		
		
		RocketTron rocketTron;
		
		rocketTron.addParticleSystems();
		
		
		TriggerSimple trigger(particleSystemManager);
		
		trigger.addRocket(rocketTron);
		// makes one shot type
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger.triggerLevel = 1;
		trigger.restoreSpeed = 0.5;
		trigger.rocketPower = 0.99;
		
		trigger.chargeAmount = 2; 
	
		//addTriggers(trigger, 50, 100,ofGetHeight()*0.85, ofGetWidth()-160);
		TriggerPattern pattern;
		
		
		RocketFountain rocketFountain(120);
		rocketFountain.startSpeedMin = 800;
		rocketFountain.startSpeedMax = 1200;
		
		
		TriggerSimple trigger2(particleSystemManager);
		trigger2.addRocket(RocketTronFountain(130,10));
		//trigger2.addRocket(rocketFountain);
		trigger2.restoreSpeed = 2;
		
		TriggerSimple trigger3(particleSystemManager);
		trigger3.addRocket(RocketTronFountain(0,0));
		trigger3.restoreSpeed = 2;
		
		
		
		pattern.addTrigger(trigger);
		pattern.addTrigger(trigger2);
		pattern.addTrigger(trigger);
		pattern.addTrigger(trigger2);
		pattern.addTrigger(trigger);
		
		pattern.addTrigger(trigger3);
		
		
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