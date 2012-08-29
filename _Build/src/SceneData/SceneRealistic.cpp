//
//  SceneRealistic .cpp
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 27/08/2012.
//
//

#include "SceneRealistic.h"

SceneRealistic :: SceneRealistic(ParticleSystemManager& psm, ofRectangle* triggerarea) : Scene(psm, triggerarea) {

	softWhiteImage.loadImage("img/ParticleWhite.png");
	
	TriggerRocket triggerFluffy(psm);
	TriggerRocket triggerFlower(psm);

	TriggerPattern pattern;
	
	triggerFluffy.addRocketSettings(getFluffyRocket());
	triggerFlower.addRocketSettings(getFlowerRocket());
	triggerFluffy.restoreSpeed = 2; 

	pattern.addTrigger(triggerFluffy);
	pattern.addTrigger(triggerFlower);

	addArrangement(pattern);

	bloomLevel = 2;

}


RocketSettings SceneRealistic :: getFlowerRocket(float hue , float hueChange ){
	
	RocketSettings rocketSettings;
	
	rocketSettings.startSpeedMin = 1200;
	rocketSettings.startSpeedMax = 1500;
	rocketSettings.directionVar = 4;
	rocketSettings.gravity.y = 200; 
	rocketSettings.drag = 0.95;
	
	ParticleSystemSettings trails = getFlowerTrailParticles(hue, hueChange);
	ParticleSystemSettings explosion = getFlowerExplosionParticles(hue, hueChange);
	ParticleSystemSettings explosionLines = getLineExplosionParticles(150, hueChange);
	
	
	
	explosion.emitDelay = explosionLines.emitDelay = trails.emitLifeTime = 2;
	
	rocketSettings.addParticleSystemSetting(trails);
	rocketSettings.addParticleSystemSetting(explosion);
	rocketSettings.addParticleSystemSetting(explosionLines);
	
	return rocketSettings;
	

	
};
ParticleSystemSettings SceneRealistic :: getFlowerTrailParticles(float hue, float hueChange ){
	
	
	ParticleSystemSettings trails;
	trails.renderer = new ParticleRendererLine(1.5, true);
	//pss.directionZVar = 20;
	trails.speedMin = 10;
	trails.speedMax = 10;
	trails.sizeStartMin = trails.sizeStartMax = 3;
	trails.hueStartMin = trails.hueStartMax = hue;
	trails.hueChange = hueChange;
	trails.saturationMin = trails.saturationMax = 0;
	trails.saturationEnd = 300;
	trails.brightnessStartMin = trails.brightnessStartMin = trails.brightnessEnd = 255;
	
	trails.emitInheritVelocity = -0.1;
	trails.emitCount = 500;
	
	
	trails.shimmerMin = 0;
	trails.lifeMin = 0.1;
	trails.lifeMax = 0.3;
	trails.startSound = "RetroLaunch";
	
	return trails;

	
};
ParticleSystemSettings SceneRealistic :: getFlowerExplosionParticles(float hue, float hueChange){
	
	
	
	ParticleSystemSettings explosion;
	explosion.renderer = new ParticleRendererBitmap(&softWhiteImage);
	
	//pss.directionZVar = 20;
	explosion.speedMin = 300;
	explosion.speedMax = 500;
	explosion.drag = 0.9;
	
	explosion.sizeStartMin = 20;
	explosion.sizeStartMax = 40;
	explosion.hueStartMin = explosion.hueStartMax = hue;
	explosion.hueChange = hueChange;
	explosion.saturationMin = explosion.saturationMax = 0;
	explosion.saturationEnd = 500;
	explosion.brightnessStartMin = explosion.brightnessStartMin = 255;
	explosion.brightnessEnd = 0;
	
	explosion.shimmerMin = 0.5;
	explosion.lifeMin = 0.5;
	explosion.lifeMax = 1;
	
	explosion.emitMode = PARTICLE_EMIT_BURST;
	explosion.emitLifeTime = 0.1;
	explosion.emitCount = 3000;
	
	explosion.startSound = "RetroExplosion";
	
	
	return explosion;
	
	
}
ParticleSystemSettings SceneRealistic :: getLineExplosionParticles(float hue, float hueChange){
	
	
	
	ParticleSystemSettings explosion;
	explosion.renderer = new ParticleRendererLine(2, true);
	
	//pss.directionZVar = 20;
	explosion.speedMin = 300;
	explosion.speedMax = 500;
	explosion.drag = 0.95;
	explosion.gravity.y = 100;
	
	explosion.sizeStartMin = 5;
	explosion.sizeStartMax = 10;
	explosion.hueStartMin = explosion.hueStartMax = hue;
	explosion.hueChange = hueChange;
	explosion.saturationMin = explosion.saturationMax = 0;
	explosion.saturationEnd = 150;
	explosion.brightnessStartMin = explosion.brightnessStartMin =  255;
	explosion.brightnessEnd = 0;
	
	explosion.shimmerMin = 0.5;
	explosion.lifeMin = 1;
	explosion.lifeMax = 2;
	
	explosion.emitMode = PARTICLE_EMIT_BURST;
	explosion.emitLifeTime = 0.1;
	explosion.emitCount = 2000;
	
	explosion.startSound = "RetroExplosion";
	
	
	return explosion;
	
	
}

RocketSettings SceneRealistic :: getFountain(){
	
	
	RocketSettings rocketSettings;
	ParticleSystemSettings pss;
	pss.renderer = new ParticleRendererLowRes();
	pss.speedMin = 100;
	pss.speedMax = 100;
	pss.drag = 0.9;
	
	pss.directionZVar = 0;
	pss.directionZ = 0;
	
	pss.sizeStartMin = 4;
	pss.sizeStartMax = 4;
	pss.sizeChangeRatio = 0;
	
	pss.hueStartMin = pss.hueStartMax = 0;
	pss.brightnessEnd = 255;
	pss.saturationMin = 0;
	pss.saturationMax = 0;
	pss.saturationEnd = 700;
	pss.shimmerMin = 1;
	
	pss.lifeMin= 0.2;
	pss.lifeMax= 0.8;
	
	
	pss.emitCount = 100;
	pss.emitLifeTime = 0.5;
	pss.emitHueModifierOffset = -128;
	pss.emitSpeedModifier = 0;
	pss.emitInheritVelocity = 0.5;
	
	ParticleSystemSettings pss2(pss);
	pss2.directionZ = 180;
	
	pss2.startSound = "RetroFountain";
	
	rocketSettings.startSpeedMin = 700;
	rocketSettings.startSpeedMax = 1200;
	rocketSettings.lifeTime = 0.5;
	rocketSettings.drag = 0.99;
	rocketSettings.gravity.y = 1000;
	rocketSettings.addParticleSystemSetting(pss);
	rocketSettings.addParticleSystemSetting(pss2);
	
	return rocketSettings;

	
	
}

RocketSettings SceneRealistic :: getFluffyRocket(){
	
	
	
	RocketSettings rocketSettings;
	ParticleSystemSettings pss;
	pss.renderer = new ParticleRendererBitmap(&softWhiteImage);
	pss.shimmerMin = 0.5;
	pss.gravity.y = 100;
	pss.speedMin = 00;
	pss.speedMax = 50;
	
	pss.sizeStartMin = 10;
	pss.sizeStartMax = 12;
	
	pss.emitCount = 500;
	pss.emitStartSizeModifier = 0;
	
	pss.lifeMin = 0.4;
	pss.lifeMax = 0.9;
	

	rocketSettings.startSpeedMin = 200;
	rocketSettings.startSpeedMin = 400;
	
	
	
	rocketSettings.addParticleSystemSetting(pss);
	
	return rocketSettings;

	
	
	
	
	
	
}
