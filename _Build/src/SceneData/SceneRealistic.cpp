//
//  SceneRealistic .cpp
//  PixelPyros
//
//  Created by Seb Lee-Delisle on 27/08/2012.
//
//

#include "SceneRealistic.h"

SceneRealistic :: SceneRealistic(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea) {

	softWhiteImage.loadImage("img/ParticleWhite.png");
	bangerFlashImage.loadImage("img/ParticleBangerFlash.png");
	
	TriggerRocket triggerFluffy(psm);
	TriggerRocket triggerFlower(psm);
	TriggerRocket triggerBanger(psm);

	TriggerPattern pattern;
	
	triggerFluffy.addRocketSettings(getFluffyRocket());
	//triggerFluffy.addRocketSettings(getFountain());
	triggerFlower.addRocketSettings(getFlowerRocket());
	triggerFluffy.restoreSpeed = 2;
	
	triggerBanger.triggerPower = 1; 
	
	
	triggerBanger.addRocketSettings(getBangerRocket());

	pattern.addTrigger(triggerFluffy);
	pattern.addTrigger(triggerFluffy);
	pattern.addTrigger(triggerFlower);
	pattern.addTrigger(triggerFluffy);
	pattern.addTrigger(triggerFluffy);
	pattern.addTrigger(triggerFlower);
	pattern.addTrigger(triggerBanger);

	addArrangement(pattern);
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
	trails.startSound = "LaunchRocketSharp";
	
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
	
	//explosion.emitMode = PARTICLE_EMIT_BURST;
	explosion.emitLifeTime = 0.1;
	explosion.emitCount = 3000;
	
	explosion.startSound = "SoftExplosion";
	
	
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
	
	//explosion.emitMode = PARTICLE_EMIT_BURST;
	explosion.emitLifeTime = 0.1;
	explosion.emitCount = 2000;
	
	//explosion.startSound = "RetroExplosion";
	
	
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
	
	pss2.startSound = "RocketFountain";
	
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
	
	pss.gravity.y = 100;
	pss.speedMin = 00;
	pss.speedMax = 20;
	pss.drag = 0.93;
	
	pss.sizeStartMin = 8;
	pss.sizeStartMax = 15;
	pss.sizeChangeRatio = 0.9;
	pss.shimmerMin = 1; 
	
	pss.emitCount = 500;
	pss.emitStartSizeModifier = 0.2;
	
	pss.brightnessStartMin = 10;
	pss.brightnessStartMax = 255;
	pss.brightnessEnd = 0;
	
	pss.lifeMin = 0.5;
	pss.lifeMax = 0.8;

	
	pss.startSound = "RocketFountain";


	rocketSettings.startSpeedMin = 350;
	rocketSettings.startSpeedMax = 400;
	rocketSettings.gravity.y = 100;
	
	
	
	rocketSettings.addParticleSystemSetting(pss);
	//rocketSettings.addParticleSystemSetting(getSmoke());
	
	return rocketSettings;
	
}

RocketSettings SceneRealistic:: getBangerRocket() {
	
	RocketSettings rocketSettings;
	
	rocketSettings.startSpeedMin = 1000;
	rocketSettings.startSpeedMax = 1200;
	rocketSettings.directionVar = 4;
	rocketSettings.gravity.y = 200;
	rocketSettings.drag = 0.95;
	
	ParticleSystemSettings trails = getBangerTrails();
	ParticleSystemSettings bang = getBangerBang();
	ParticleSystemSettings bangCrackles = getBangerCrackles();
	ParticleSystemSettings smoke1 = getSmoke();
	ParticleSystemSettings smoke2 = getSmoke();
	
	smoke2.emitMode = PARTICLE_EMIT_CONTINUOUS;
	smoke2.emitCount = 200;
	smoke2.emitLifeTime = 0.2; 
	smoke2.sizeStartMax = 30;
	smoke2.speedMax = 100;
	smoke2.brightnessStartMin = 10;
	smoke2.brightnessStartMax = 30;
	
	
	bang.emitDelay = bangCrackles.emitDelay = trails.emitLifeTime = smoke1.emitLifeTime =smoke2.emitDelay = 2;
	
	rocketSettings.addParticleSystemSetting(trails);
	rocketSettings.addParticleSystemSetting(smoke1);
	rocketSettings.addParticleSystemSetting(smoke2);
	rocketSettings.addParticleSystemSetting(bang);
	rocketSettings.addParticleSystemSetting(bangCrackles);
	
	return rocketSettings;
	
}


ParticleSystemSettings SceneRealistic :: getBangerTrails() {
	
	ParticleSystemSettings trails;
	trails.renderer = new ParticleRendererLine(1.5, true);
	//pss.directionZVar = 20;
	trails.speedMin = 5;
	trails.speedMax = 6;
	trails.sizeStartMin = trails.sizeStartMax = 3;
	trails.hueStartMin = trails.hueStartMax = 30;
	trails.hueChange = -10;
	trails.saturationMin = trails.saturationMax = 0;
	trails.saturationEnd = 0;
	trails.brightnessStartMin = trails.brightnessStartMin = trails.brightnessEnd = 255;
	
	trails.emitInheritVelocity = -0.01;
	trails.emitCount = 500;
	
	
	trails.shimmerMin = 0;
	trails.lifeMin = 0.1;
	trails.lifeMax = 0.3;
	trails.startSound = "Launch";
	
	return trails;

	
}


ParticleSystemSettings SceneRealistic:: getBangerBang() {
	
	ParticleSystemSettings explosion;
	//explosion.renderer = new ParticleRendererCircle(24);
	explosion.renderer = new ParticleRendererBitmap(&bangerFlashImage);

	//pss.directionZVar = 20;
	explosion.speedMin = 0;
	explosion.speedMax = 0;
	explosion.drag = 0.90;
	
	explosion.sizeStartMin = 600;
	explosion.sizeStartMax = 900;
	explosion.sizeChangeRatio = 0;
	explosion.hueStartMin = explosion.hueStartMax = 0;
	explosion.hueChange = 0;
	explosion.saturationMin = explosion.saturationMax = 0;
	explosion.saturationEnd = 0;
	explosion.brightnessStartMin = explosion.brightnessStartMin = 255;
	explosion.brightnessEnd = 0;
	
	explosion.shimmerMin = 1;
	explosion.lifeMin = 0.1;
	explosion.lifeMax = 0.1;
	
	explosion.emitMode = PARTICLE_EMIT_BURST;
	explosion.emitLifeTime = 0.1;
	explosion.emitCount = 1;
	
	
	
	explosion.startSound = "Banger";
	
	
	return explosion;

	
	return ParticleSystemSettings();
	
}



ParticleSystemSettings SceneRealistic:: getBangerCrackles() {
	
	ParticleSystemSettings explosion;
	explosion.renderer = new ParticleRendererCircle();

	
	explosion.directionYVar= 90;
	explosion.speedMin = 300;
	explosion.speedMax = 400;
	explosion.drag = 0.93;
	
	explosion.sizeStartMin = 5;
	explosion.sizeStartMax = 8;
	explosion.hueStartMin = explosion.hueStartMax = 0;
	explosion.hueChange = 0;
	explosion.saturationMin = explosion.saturationMax = 0;
	explosion.saturationEnd = 0;
	explosion.brightnessStartMin = explosion.brightnessStartMin = 255;
	explosion.brightnessEnd = 0;
	
	explosion.shimmerMin = 0.0;
	explosion.lifeMin = 0.1;
	explosion.lifeMax = 0.2;
	
	explosion.emitMode = PARTICLE_EMIT_BURST;
	//explosion.emitLifeTime = 0.1;
	explosion.emitCount = 200;
	
	explosion.renderDelayMin = 0.5;
	explosion.renderDelayMax = 3;
	
	
	explosion.startSound = "Crackle";
	
	
	return explosion;
	
	
}


ParticleSystemSettings SceneRealistic:: getSmoke() {
	
	float hueStartOffset = 200;
	float saturation = 0; 
	ParticleSystemSettings ps2; 
	// PHYSICS
	ps2.speedMin = 15;
	ps2.speedMax = 20;
	ps2.directionZ = 0;
	ps2.directionZVar = 90;
	ps2.directionYVar = 180;
	ps2.drag = 0.90;
	ps2.gravity.set(0,-30);
	
	//LIFE
	ps2.lifeMin = 1;
	ps2.lifeMax = 1.5;
	
	//APPEARANCE
	
	ps2.sizeStartMin = 2;
	ps2.sizeStartMax = 5;
	ps2.sizeChangeRatio = 5;
	
	ps2.hueStartMin = 0+hueStartOffset;
	ps2.hueStartMax = 0+hueStartOffset;
	ps2.hueChange = 0;
	
	ps2.brightnessStartMin = 20;
	ps2.brightnessStartMax = 70;
	ps2.brightnessEnd = 0;
	
	ps2.saturationMin = saturation;
	ps2.saturationMax = saturation;
	ps2.saturationEnd = saturation;
	
	//ps.shimmerMin = 0.1;
	
	// but also :
	// lifeExpectancy
	// delay
	
	ps2.emitStartSizeModifier = 0;
	//ps2.emitSpeedModifier = 0;
	
	
	ps2.emitMode = PARTICLE_EMIT_CONTINUOUS;
	ps2.emitCount = 500;
	
	ps2.emitDelay = 0;
	ps2.emitLifeTime= 0.5;
	
	ps2.renderer = new ParticleRendererBitmap(&softWhiteImage); 

	
	return ps2; 
	
	
}


