#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(60);
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
	
	for(int i = 0; i<physicsObjects.size(); i++) { 
		PhysicsObject * rocket = physicsObjects[i]; 
		if(!rocket->enabled) continue; 
		rocket->update(deltaTime); 
		
		if(rocket->pos.y>ofGetHeight()) { 
			sparePhysicsObjects.push_back(rocket); 
			rocket->enabled = false; 
		}
		
	}
	for(int i = 0; i<particleSystems.size(); i++) { 
		
		ParticleSystem * ps = particleSystems[i];
		if(ps->finished) continue; 
		ps->update(deltaTime); 
		if(ps->finished) { 
			spareParticleSystems.push_back(ps); 
		}
		
	}
	
	
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix(); 
	
	ofTranslate(0,ofGetHeight()*0.9); 
	ofRotateX(5); 
	ofTranslate(0,ofGetHeight()*-0.9);

	for(int i = 0; i<particleSystems.size(); i++) { 
		particleSystems[i]->draw(); 
	}
	
	
	for(int i = 0; i<physicsObjects.size(); i++) { 
		//ofCircle(physicsObjects[i]->pos, 2); 
		
		//update(deltaTime); 
	}
	
	ofPopMatrix(); 
}

void testApp:: mousePressed(int x, int y, int button ) { 
//	psystem.reset(); 
//	rocket.reset(); 
//	rocket.vel.set(0,-800,0);
//	rocket.gravity.y = 500;
//	rocket.vel.rotate(0,0,ofRandom(-10,10));
//	
//	rocket.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);

	makeRocket(rocketSettings); 
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
	
	//ps2.emitStartSizeModifier = 0; 
	//ps2.emitSpeedModifier = 0; 
	//ps2.emitHueModifierOffset = 0;
	
	//ps.emitAttachedPhysicsObject = &rocket;
	//ps2.emitInheritVelocity = -0.5; 
	
	//psystem.init(ps); 
	
	
	//ped
	
	
	
// SO... TO MAKE A ROCKET... 
	// I need to know settings for that. The usual physics starter settings, 
	// same is with a particle system. 
	// startSpeedMin / Max
	// startRotationZ / var 
	// Probably doesn't need RotationY ?
	// then it just needs some particleSystemSettings, right? 
	
		
	rocketSettings.startSpeedMin = 600;
	rocketSettings.startSpeedMax = 700; 
	rocketSettings.direction = -90; 
	rocketSettings.directionVar = 10; 
	rocketSettings.gravity.y = 400; 
	
	rocketSettings.addParticleSystemSetting(ps); 
	rocketSettings.addParticleSystemSetting(ps2); 
	
	

}


void testApp::makeRocket(RocketSettings rs) { 
	
	
	PhysicsObject *rocket; 
	
	if(sparePhysicsObjects.size()>0) {
		rocket = sparePhysicsObjects.back();
		sparePhysicsObjects.pop_back();
		rocket->reset();
	} else {
		rocket = new PhysicsObject();
		physicsObjects.push_back(rocket); 
		
	}

	rocket->vel.set(ofRandom(rs.startSpeedMin, rs.startSpeedMax),0,0); 
	rocket->vel.rotate(0,0,ofRandom(rs.direction - rs.directionVar, rs.direction+rs.directionVar)); 
	rocket->gravity = rs.gravity; 
	rocket->drag = rs.drag; 
	rocket->pos.set((ofGetWidth()/2), ofGetHeight() *0.9); 
	
	
	
	for(int i = 0; i<rs.particleSystemSettings.size(); i++) { 
		ParticleSystemSettings pss = rs.particleSystemSettings[i]; 
		
		ParticleSystem* ps; 
		if(spareParticleSystems.size()>0) { 
			ps = spareParticleSystems.back(); 
			spareParticleSystems.pop_back(); 
			ps->reset();
		} else {
			ps = new ParticleSystem(); 
			particleSystems.push_back(ps); 
			
		}
		
		
	
		//pss.hueStartMin = pss.hueStartMax = ofRandom(255); 
		ps->init(pss);
		ps->attachedPhysicsObject = rocket; 
	}
	
	
	
}

void testApp::exit() { 


}