#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(120);
	lastUpdateTime = ofGetElapsedTimef();
	
	//setupControlPanel();
	
	//gui.hide();
	
	ofBackground(0);

	//rocket.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
	setupScenes(); 

}

//--------------------------------------------------------------
void testApp::update(){

	//cout << particleSystems.size() << " " << physicsObjects.size()<< endl; 
	
	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	lastUpdateTime = time;
	
	for(int i = 0; i<scenes.size(); i++) {	
		scenes[i]->update(deltaTime); 
	}
	
	particleSystemManager.update(deltaTime);
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix(); 
	
	// change perspective so we're looking up
	ofTranslate(0,ofGetHeight()*0.9); 
	ofRotateX(5); 
	ofTranslate(0,ofGetHeight()*-0.9);

	
	for(int i = 0; i<scenes.size(); i++) {	
		scenes[i]->draw(); 
	}
	particleSystemManager.draw();
	ofPopMatrix(); 
	
	ofDrawBitmapString(ofToString(ofGetFrameRate()),20,20); 
	ofDrawBitmapString(ofToString(particleSystemManager.particleSystems.size()),20,35); 
	
	
}

void testApp:: mousePressed(int x, int y, int button ) { 
	//trigger.makeRocket();
}

void testApp:: setupScenes() { 

	
	
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
	ps2.speedMin = 750; 
	ps2.speedMax = 800; 
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
	ps2.emitCount = 30000; 
	
	ps2.emitDelay = 2; 
	ps2.emitLifeTime= 0.05;
	
	
	
	
	
	RocketSettings rocketSettings; 
		
	rocketSettings.startSpeedMin = 600;
	rocketSettings.startSpeedMax = 700; 
	rocketSettings.direction = -90; 
	rocketSettings.directionVar = 5; 
	rocketSettings.gravity.y = 400; 
	
	rocketSettings.addParticleSystemSetting(ps); 
	rocketSettings.addParticleSystemSetting(ps2); 
	
	Trigger trigger(particleSystemManager); 
	
	trigger.rocketSettings = rocketSettings; 
	
	Scene* scene1 = new Scene(particleSystemManager); 
	
	scene1->addTriggers(trigger, 8);
	
	scenes.push_back(scene1); 
	

}



void testApp::exit() { 


}