

#include "SceneRetro.h"


SceneRetro :: SceneRetro(ParticleSystemManager& psm, ofRectangle triggerarea) : Scene(psm, triggerarea) {

	bloomLevel = 1.5;
	pixelSize = 4;
	
	TriggerRocket triggerRocket(psm);
	TriggerRocket triggerFountain(psm);
	
	TriggerPattern pattern;
	
	triggerRocket.addRocketSettings(getRetroRocket());
	triggerRocket.addRocketSettings(getRetroRocket(120));
	
	triggerFountain.restoreSpeed = 4;
	triggerFountain.minTriggerInterval = 0.1; 
	triggerFountain.addRocketSettings(getRetroFountain());
	
	pattern.addTrigger(triggerRocket);
	pattern.addTrigger(triggerFountain);
	addArrangement(pattern); 
	
};


bool SceneRetro :: draw() {
	if(!Scene::draw()) return false;
	
	ofPushStyle();
	ofDisableSmoothing();
	ofDisableBlendMode();
	ofEnableAlphaBlending();
	
	ofMesh mesh;
	mesh.setMode(OF_PRIMITIVE_LINES);
	
	ofColor lineColour(0,0,0,100);
	
	
	for(float x = 0; x<APP_WIDTH; x+=pixelSize) {
		
		mesh.addVertex(ofVec3f(x,0));
		mesh.addVertex(ofVec3f(x,APP_HEIGHT));
		mesh.addColor(lineColour);
		mesh.addColor(lineColour);
		
		
	}
	for(float y = 0; y<APP_HEIGHT; y+=pixelSize) {
		
		mesh.addVertex(ofVec3f(0,y));
		mesh.addVertex(ofVec3f(APP_WIDTH,y));
		mesh.addColor(lineColour);
		mesh.addColor(lineColour);
		
		
	}
	mesh.draw(); 
	
	ofPopStyle();
	
}

RocketSettings SceneRetro:: getFluffyRocket() {

	RocketSettings rocketSettings;
	ParticleSystemSettings pss;
	pss.renderer = new ParticleRendererShape();
	
	rocketSettings.addParticleSystemSetting(pss);
	
	return rocketSettings;

};

RocketSettings SceneRetro::getRetroRocket(float hue, float hueChange) {
	RocketSettings rocketSettings;
	
	rocketSettings.startSpeedMin = 1000;
	rocketSettings.startSpeedMax = 1200;
	rocketSettings.drag = 0.95; 
		
	ParticleSystemSettings trails = getPixelTrailParticles(hue, hueChange);
	ParticleSystemSettings explosion = getPixelExplosionParticles(hue, hueChange);
	
	
	
	explosion.emitDelay = trails.emitLifeTime; 

	rocketSettings.addParticleSystemSetting(trails);
	rocketSettings.addParticleSystemSetting(explosion);
	
	return rocketSettings;

	
}



RocketSettings SceneRetro:: getRetroFountain() {
	
	RocketSettings rocketSettings;
	ParticleSystemSettings pss;
	pss.renderer = new ParticleRendererLowRes(pixelSize);
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
	
};



ParticleSystemSettings SceneRetro::  getPixelTrailParticles(float hue, float hueChange){
	
	ParticleSystemSettings trails;
	trails.renderer = new ParticleRendererLowRes(pixelSize);
	//pss.directionZVar = 20;
	trails.speedMin = 10;
	trails.speedMax = 10;
	trails.sizeStartMin = trails.sizeStartMax = 3;
	trails.hueStartMin = trails.hueStartMax = hue;
	trails.hueChange = hueChange;
	trails.saturationMin = trails.saturationMax = 0;
	trails.saturationEnd = 500;
	trails.brightnessStartMin = trails.brightnessStartMin = trails.brightnessEnd = 255;
	
	trails.shimmerMin = 0;
	trails.lifeMin = trails.lifeMax = 0.3;
	trails.startSound = "RetroLaunch"; 

	return trails;
	
};

ParticleSystemSettings SceneRetro::  getPixelExplosionParticles(float hue, float hueChange){
	
	ParticleSystemSettings explosion;
	explosion.renderer = new ParticleRendererLowRes(pixelSize);
	
	//pss.directionZVar = 20;
	explosion.speedMin = 500;
	explosion.speedMax = 500;

	explosion.sizeStartMin = explosion.sizeStartMax = 30;
	explosion.hueStartMin = explosion.hueStartMax = hue;
	explosion.hueChange = hueChange;
	explosion.saturationMin = explosion.saturationMax = 0;
	explosion.saturationEnd = 500;
	explosion.brightnessStartMin = explosion.brightnessStartMin = explosion.brightnessEnd = 255;
	
	explosion.shimmerMin = 0;
	explosion.lifeMin = explosion.lifeMax = 0.6;
	
	explosion.emitMode = PARTICLE_EMIT_BURST;
	explosion.emitLifeTime = 0.1;
	explosion.emitCount = 500;
	explosion.startSound = "RetroExplosion";

	
	return explosion;
	
};



