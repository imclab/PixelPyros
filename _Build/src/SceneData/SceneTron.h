//
//  SceneSpace.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 14/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once

#include "Scene.h"
#include "RocketTron.h"

#include "RocketTronFountain.h"
#include "TriggerRocket.h"
#include "StretchyNet.h"
#include "ParticleRendererSquare.h"
#include "RocketFountain.h"
#include "TriggerRotator.h"

class SceneTron : public Scene {
	
	public : 
	
	SceneTron (ParticleSystemManager& psm, ofRectangle* triggerarea) : Scene(psm, triggerarea){
		
		bloomLevel = 2;
		
		RocketTron rocketTron;
		
		rocketTron.addParticleSystems();
		
		TriggerRocket trigger(particleSystemManager);
		
		trigger.addRocketSettings(rocketTron);
		// makes one shot type
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger.triggerLevel = 1;
		trigger.restoreSpeed = 0.5;
		trigger.triggerPower = 0.99;
		
		trigger.motionSensitivity = 2; 
		
		RocketTronFountain rocketFountainBlue(130,10);
		rocketFountainBlue.startSpeedMin = 500;
		rocketFountainBlue.startSpeedMax = 800;
		RocketTronFountain rocketFountainPink(-20,0);
		rocketFountainPink.startSpeedMin = 500;
		rocketFountainPink.startSpeedMax = 800;
		
		TriggerRotator glitchTrigger(particleSystemManager,20,1,true);
		
		glitchTrigger.restoreSpeed = 2;
		TriggerRotator glitchTrigger2(glitchTrigger);
		glitchTrigger.addRocketSettings(rocketFountainBlue);
		
		glitchTrigger2.addRocketSettings(rocketFountainPink);
		
		
		TriggerRocket starTrigger(particleSystemManager);
		starTrigger.triggerLevel = 1;
		starTrigger.restoreSpeed = 2;
		starTrigger.triggerPower = 0.99;
		
		trigger.motionSensitivity = 2;
		
		RocketTron glitchRocket;
		glitchRocket.head.renderer = new ParticleRendererGlitchLine(2);
		glitchRocket.head.speedMin = 30;
		glitchRocket.head.speedMax = 100;
		glitchRocket.head.brightnessStartMax = 255;
		glitchRocket.head.brightnessStartMin = 255;
		glitchRocket.head.brightnessEnd = 255;
		
		glitchRocket.head.lifeMin= 0.1;
		glitchRocket.head.lifeMax= 0.15;
		glitchRocket.head.emitInheritVelocity  =0.0;
		//glitchRocket.head.emitSpeedModifier = 0.1;
		
		glitchRocket.explosion.renderer = new ParticleRendererGlitchLine(1.1);
		glitchRocket.explosion.sizeStartMin = glitchRocket.explosion.sizeStartMax =2;
		
		glitchRocket.explosion.brightnessEnd = 0; 
		glitchRocket.explosion.speedMin = 200;
		glitchRocket.explosion.speedMax = 2000;
		glitchRocket.explosion.directionZVar = 0;
		glitchRocket.explosion.lifeMin= 0.1;
		glitchRocket.explosion.lifeMax= 0.4;
		glitchRocket.explosion.hueStartMin = 130;
		glitchRocket.explosion.hueStartMax = 130;
		
		
		glitchRocket.explosion.emitCount = 5000;
		glitchRocket.explosion.emitLifeTime = 0.1;
		glitchRocket.explosion.emitDelay = 2.1;
		
		glitchRocket.explosion.drag = 0.99;
		
		
		
		glitchRocket.startSpeedMin = 700;
		glitchRocket.directionVar = 6;
		
		
		
		
		glitchRocket.addParticleSystems();
		//glitchRocket.addParticleSystemSetting(glitchRocket.trails);
		starTrigger.addRocketSettings(glitchRocket);
		
		TriggerPattern glitchPattern;
		
		glitchPattern.addTrigger(glitchTrigger);
		glitchPattern.addTrigger(glitchTrigger);
		glitchPattern.addTrigger(starTrigger);
		glitchPattern.addTrigger(glitchTrigger);
		glitchPattern.addTrigger(glitchTrigger2);
		glitchPattern.addTrigger(glitchTrigger2);
		glitchPattern.addTrigger(glitchTrigger);
		
		addArrangement(glitchPattern);
		
		
		
		TriggerRocket trigger2(particleSystemManager);
		trigger2.addRocketSettings(rocketFountainBlue);
		//trigger2.addRocketSettings(rocketFountain);
		trigger2.restoreSpeed = 2;
		
		TriggerRocket trigger3(particleSystemManager);
		trigger3.addRocketSettings(rocketFountainPink);
		trigger3.restoreSpeed = 2;
		
		
		
		rocketFountainBlue.startSpeedMax = 1200;
		rocketFountainPink.startSpeedMax = 1200;
		
		TriggerPattern pattern;
		
		pattern.addTrigger(trigger);
		pattern.addTrigger(trigger2);
		//pattern.addTrigger(trigger);
		//pattern.addTrigger(trigger2);
		//pattern.addTrigger(trigger);
		
		//pattern.addTrigger(trigger3);
		
		
		addArrangement(pattern);
		
		
		// Arrangement with only glitch fountains, closer spaced
		
		TriggerPattern crazyPattern;
		TriggerRotator crazyTrigger(particleSystemManager,20,1,false);
		crazyTrigger.triggerPower = 1;
		crazyTrigger.restoreSpeed = 1;
		crazyTrigger.addRocketSettings(rocketFountainBlue);
		crazyTrigger.addRocketSettings(rocketFountainPink);
		crazyPattern.addTrigger(crazyTrigger,0,0,0.3);
		//pattern.addTrigger(trigger2);
		
		addArrangement(crazyPattern);
		
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