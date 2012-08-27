//
//  SceneSpace.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 14/08/2012.
//  Copyright (c) 2012 seb.ly. All rights reserved.
//
#pragma once

#include "Scene.h"
#include "RocketBasic.h"
#include "TriggerRocket.h"
#include "RocketThinFountain.h"
#include "ParticleRendererStar.h"
#include "RocketFountain.h"
#include "Starfield.h"

class SceneSpace : public Scene {
	
	public : 
	
	SceneSpace(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea){
		
		bloomLevel = 4;

		TriggerRocket planetTrigger(particleSystemManager);
		
		planetTrigger.addRocketSettings(getPlanetRocket());
		
		TriggerPattern pattern;
		
		
		// makes chargeable trigger
		planetTrigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		planetTrigger.triggerLevel = 1; 
		planetTrigger.motionSensitivity = 5;
		planetTrigger.restoreSpeed = 0; 
		
		//pattern.addTrigger(trigger);
		
		
		// makes one shot type
		TriggerRocket starTrigger(psm);
		
		starTrigger.addRocketSettings(getStarryRocket());
		starTrigger.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		starTrigger.triggerLevel = 1;
		starTrigger.restoreSpeed = 0; 
		starTrigger.triggerPower = 0.2;
		
		
		TriggerRocket fountainTrigger2(psm);
		
		fountainTrigger2.addRocketSettings(RocketFountain(120));
		fountainTrigger2.type = TRIGGER_TYPE_FIRE_ON_MOTION;
		fountainTrigger2.triggerLevel = 1;
		fountainTrigger2.restoreSpeed = 0;
		fountainTrigger2.triggerPower = 0.2;
		
		pattern.addTrigger(starTrigger);
		pattern.addTrigger(fountainTrigger2);
		pattern.addTrigger(planetTrigger);
		
		addArrangement(pattern);
		
	}
	
	bool update(float deltaTime) {
		if(!Scene::update(deltaTime)) return false;
		
		starfield.update(deltaTime); 
		
	}
	
	bool draw() {
		
		if(!Scene::draw()) return false;
		
		starfield.draw();
		
		return true;
		
	}
	
	RocketSettings getPlanetRocket() {
		
		renderer = new ParticleRendererShape();
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
		
		ps.renderer = renderer;
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
		
		ps2.renderer = renderer;
		
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
		
		//ps3.startSound = "ExplosionSynth1";
		
		ps3.renderer = renderer;
		
		
		RocketSettings rocketSettings;
		
		rocketSettings.startSpeedMin = 600;
		rocketSettings.startSpeedMax = 700;
		rocketSettings.direction = -90;
		rocketSettings.directionVar = 5;
		rocketSettings.gravity.y = 400;
		
		rocketSettings.addParticleSystemSetting(ps);
		rocketSettings.addParticleSystemSetting(ps2);
		rocketSettings.addParticleSystemSetting(ps3);
		
		return rocketSettings; 
		
		
		
		
	}
	
	RocketSettings getStarryRocket() {
		
		
		ParticleRendererStar* starRenderer = new ParticleRendererStar(10);
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
		
		ps.sizeStartMin = 0.1;
		ps.sizeStartMax = 0.15;
		ps.sizeChangeRatio = 7;
		
		ps.hueStartMin = 100;
		ps.hueStartMax = 120;
		ps.hueChange = 0;
		
		ps.brightnessStartMin = 255;
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
		
		ps.renderer = starRenderer;
		//psystem.init(ps);
		
		ParticleSystemSettings stars;
		
		stars.renderer = starRenderer;
		
		stars.sizeStartMin = 0.2;
		stars.sizeStartMax = 1;
		stars.sizeChangeRatio = 3;
		
		stars.speedMin = 0;
		stars.speedMax = 40;
		
		stars.lifeMin = 1;
		stars.lifeMin = 1.2;
		
		stars.emitLifeTime =1.3;
		stars.emitDelay = 0;
		stars.emitCount = 500;
		stars.emitStartSizeModifier = 0;
		stars.emitSpeedModifier = 0;
		
		
		stars.brightnessEnd = 0;
		stars.saturationMin = 0;
		stars.saturationMax = 100;
		stars.hueStartMin = 100;
		stars.hueStartMax = 120;
		
		stars.shimmerMin = 0.1; 
		
		
		
		RocketSettings rocketSettings;
		
		rocketSettings.startSpeedMin = 800;
		rocketSettings.startSpeedMax = 1000;
		rocketSettings.direction = -90;
		rocketSettings.directionVar = 5;
		rocketSettings.gravity.y = 300;
		rocketSettings.drag = 0.96;
		rocketSettings.lifeTime = 1;
		
		//rocketSettings.addParticleSystemSetting(ps);
		rocketSettings.addParticleSystemSetting(stars);
		
		return rocketSettings; 
		
		
		
	}
		
	
	ParticleRendererShape* renderer;
	
	Starfield starfield; 
	
};