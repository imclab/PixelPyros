//
//  RocketBasic.h
//  ArchitectureCamera
//
//  Created by Seb Lee-Delisle on 17/08/2012.
//
//

#pragma once

#include "ParticleSystemSettings.h"
#include "ParticleRendererSquare.h"
#include "ParticleRendererLine.h"
//#include "ParticleRendererBitmap.h"

class RocketTron : public RocketSettings {
	
    public :
    
    RocketTron(float hueStartOffset = 0, float hueChange = 0, float explosionHue = 20, ParticleRendererBase * renderer1 = NULL, ParticleRendererBase * renderer2 = NULL) : RocketSettings() {
        
		
		particleRenderer = new ParticleRendererSquare();
		particleLineRenderer = new ParticleRendererLine(); 
		particleLineRenderer->lineWidth = 2;
		whiteImage.loadImage("img/ParticleWhite.png");
        
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
		
		// PHYSICS
		ps.speedMin = 60;
		ps.speedMax = 100;
		ps.directionZ = 0;
		ps.directionZVar = 0;
		ps.directionYVar = 180;
		ps.drag = 0.90;
		ps.gravity.set(0,30);
		
		//LIFE
		ps.lifeMin = 0.5;
		ps.lifeMax = 1.5;
		
		//APPEARANCE
		
		ps.sizeStartMin = 4;
		ps.sizeStartMax = 6;
		ps.sizeChangeRatio = 1;
		
		ps.hueStartMin = 0+hueStartOffset;
		ps.hueStartMax = 30+hueStartOffset;
		ps.hueChange = hueChange;
		
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
		ps.emitInheritVelocity = -2;
		
		ps.startSound = "SynthThud";
		
		if(renderer1!=NULL)
			ps.renderer = renderer1;
		else
			ps.renderer = particleRenderer;
		
		
		
		// PHYSICS
		ps2.speedMin = 600;
		ps2.speedMax = 800;
		ps2.directionZ = 0;
		ps2.directionZVar =0;
		ps2.directionYVar = 180;
		ps2.drag = 0.959;
		ps2.gravity.set(0,0);
		
		//LIFE
		ps2.lifeMin = 0.8;
		ps2.lifeMax = 1.2;
		
		//APPEARANCE
		
		ps2.sizeStartMin = 25;
		ps2.sizeStartMax = 35;
		ps2.sizeChangeRatio = 0;
		
		ps2.hueStartMin = 0+explosionHue;
		ps2.hueStartMax = 15+explosionHue;
		ps2.hueChange = 0;
		
		ps2.brightnessStartMin = 255;
		ps2.brightnessStartMax = 255;
		ps2.brightnessEnd = 255;
		
		ps2.saturationMin = 25;
		ps2.saturationMax = 75;
		ps2.saturationEnd = 200;
		
		ps2.shimmerMin = 0.3;
		
		// but also :
		// lifeExpectancy
		// delay
		
		ps2.emitMode = PARTICLE_EMIT_BURST;
		ps2.emitCount = 10000;
		
		ps2.emitDelay = 2;
		ps2.emitLifeTime= 0.1;
		
		ps2.startSound = "ExplosionSynth1";
		if(renderer2!=NULL)
			ps2.renderer = renderer2;
		else
			ps2.renderer = particleRenderer;
		
		
        startSpeedMin = 600;
		startSpeedMax = 750;
		direction = -90;
		directionVar = 5;
		gravity.y = 400;
		lifeTime =2.2;
		
		addParticleSystemSetting(ps);
		addParticleSystemSetting(ps2);
		
        
    };
	
	
	
	
	ofImage whiteImage;
	
	
	ParticleRendererShape* particleRenderer;
	ParticleRendererLine* particleLineRenderer;
	
	ParticleSystemSettings ps;
	
	ParticleSystemSettings ps2;
	
	
	
};
