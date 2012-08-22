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
#include "Starfield.h"

class Scene1 : public Scene {
	
	public : 
	
	Scene1(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
		
		// ParticleData
		// size range
		// size modifier
		// velocity range
		// life range
		// drag 
		// gravity 
		// colour
		// colour modifier
		// renderer
		
		// EmmisionData
		// Frequency
		// Burst/continuous
		// range of start sizes for particles
		// range of colours for particles
		
		// optional colour modifier
		
		ParticleSystemSettings ps; 
		// PHYSICS
		ps.speedMin = 20; 
		ps.speedMax = 60; 
		ps.directionZ = 0; 
		ps.directionZVar = 90; 
		ps.directionYVar = 180; 
		ps.drag = 0.90; 
		ps.gravity.set(0,30); 
		
		//LIFE
		ps.lifeMin = 0.5; 
		ps.lifeMax = 0.8; 
		
		//APPEARANCE
		
		ps.sizeStartMin = 4; 
		ps.sizeStartMax = 6;
		ps.sizeChangeRatio = 1; 
		
		ps.hueStartMin = 0; 
		ps.hueStartMax = 30; 
		ps.hueChange = 0; 
		
		ps.brightnessStartMin = 150; 
		ps.brightnessStartMax = 255;
		ps.brightnessEnd = 0; 
		
		ps.saturationMin = 150; 
		ps.saturationMax = 255; 
		ps.saturationEnd = 255; 
		
		//ps.shimmerMin = 0.1; 
		
		// but also : 
		// lifeExpectancy
		// delay
		
		ps.emitMode = PARTICLE_EMIT_CONTINUOUS;
		ps.emitCount = 1000; 
		
		ps.emitDelay = 0; 
		ps.emitLifeTime= 2;
		
		ps.emitStartSizeModifier = 0; 
		ps.emitSpeedModifier = 0; 
		ps.emitHueModifierOffset = 0;
		
		//ps.emitAttachedPhysicsObject = &rocket;
		ps.emitInheritVelocity = -0.5; 
		
		//psystem.init(ps); 
		
		
		
		// optional colour modifier
		
		ParticleSystemSettings ps2; 
		// PHYSICS
		ps2.speedMin = 650; 
		ps2.speedMax = 700; 
		ps2.directionZ = 0; 
		ps2.directionZVar = 90; 
		ps2.directionYVar = 180; 
		ps2.drag = 0.90; 
		ps2.gravity.set(0,30); 
		
		//LIFE
		ps2.lifeMin = 0.5; 
		ps2.lifeMax = 0.8; 
		
		//APPEARANCE
		
		ps2.sizeStartMin = 5; 
		ps2.sizeStartMax = 7;
		ps2.sizeChangeRatio = 0; 
		
		ps2.hueStartMin = 20; 
		ps2.hueStartMax = 25; 
		ps2.hueChange = -20; 
		
		ps2.brightnessStartMin = 155; 
		ps2.brightnessStartMax = 155;
		ps2.brightnessEnd = 100; 
		
		ps2.saturationMin = 50; 
		ps2.saturationMax = 100; 
		ps2.saturationEnd = 500; 
		
		//ps.shimmerMin = 0.1; 
		
		// but also : 
		// lifeExpectancy
		// delay
		
		ps2.emitMode = PARTICLE_EMIT_BURST;
		ps2.emitCount = 10000; 
		
		ps2.emitDelay = 2; 
		ps2.emitLifeTime= 0.05;
		
		
		// optional colour modifier
		
		ParticleSystemSettings ps3; 
		// PHYSICS
		ps3.speedMin = 550; 
		ps3.speedMax = 800; 
		ps3.directionZ = 0; 
		ps3.directionZVar = 0; 
		ps3.directionYVar = 180; 
		ps3.drag = 0.99; 
		ps3.gravity.set(0,30); 
		
		//LIFE
		ps3.lifeMin = 0.5; 
		ps3.lifeMax = 0.8; 
		
		//APPEARANCE
		
		ps3.sizeStartMin = 10; 
		ps3.sizeStartMax = 12;
		ps3.sizeChangeRatio = 0; 
		
		ps3.hueStartMin = 10; 
		ps3.hueStartMax = 15; 
		ps3.hueChange = 0; 
		
		ps3.brightnessStartMin = 200; 
		ps3.brightnessStartMax = 200;
		ps3.brightnessEnd = 100; 
		
		ps3.saturationMin = 200; 
		ps3.saturationMax = 200; 
		ps3.saturationEnd = 250; 
		
		//ps.shimmerMin = 0.1; 
		
		// but also : 
		// lifeExpectancy
		// delay
		
		ps3.emitMode = PARTICLE_EMIT_BURST;
		ps3.emitCount = 10000; 
		
		ps3.emitDelay = 1.95; 
		ps3.emitLifeTime= 0.05;
		
		ps3.startSound = "ExplosionSynth1";
				
		RocketSettings rocketSettings;
		
		rocketSettings.startSpeedMin = 600;
		rocketSettings.startSpeedMax = 700; 
		rocketSettings.direction = -90; 
		rocketSettings.directionVar = 5; 
		rocketSettings.gravity.y = 400; 
		
		rocketSettings.addParticleSystemSetting(ps); 
		rocketSettings.addParticleSystemSetting(ps2); 
		rocketSettings.addParticleSystemSetting(ps3); 
		
		TriggerSimple trigger(particleSystemManager);
		
		trigger.addRocket(rocketSettings);
		
		TriggerPattern pattern;
		pattern.addTrigger(trigger);
		
		//addTriggers(trigger, 4, 20,ofGetHeight()*0.85, ofGetWidth()-160);
		
		
		// makes chargeable trigger
		trigger.type = TRIGGER_TYPE_FIRE_ON_CHARGE;
		trigger.triggerLevel = 1; 
		trigger.chargeAmount = 5;
		
		//addTriggers(trigger, 4, 100,ofGetHeight()*0.85, ofGetWidth()-160);
		pattern.addTrigger(trigger);
		
		
		// makes one shot type
		trigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		trigger.triggerLevel = 1;
		trigger.restoreSpeed = 0; 
		trigger.rocketPower = 0.9; 
		
		//addTriggers(trigger, 4, 180,ofGetHeight()*0.85, ofGetWidth()-160);
		pattern.addTrigger(trigger);
		
		
		addArrangement(pattern);
		
		
		
		
	}
	
	bool draw() {
		
		if(!Scene::draw()) return false;
		
		starfield.draw();
		
		return true;
		
	}
	
	
	Starfield starfield; 
	
};