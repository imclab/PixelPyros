#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(60);
	lastUpdateTime = ofGetElapsedTimef();
	
	//setupControlPanel();
	
	//gui.hide();
	
	ofBackground(0);

	rocket.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
	setupScenes(); 

}

//--------------------------------------------------------------
void testApp::update(){

	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	lastUpdateTime = time;
	
	rocket.update(deltaTime); 
	psystem.update(deltaTime); 
	
	if(rocket.pos.y>ofGetHeight()) { 
		
		psystem.reset(); 
		rocket.reset(); 
		rocket.vel.set(0,-800,0);
		rocket.gravity.y = 500;
		rocket.vel.rotate(0,0,ofRandom(-20,20));
		
		rocket.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix(); 
	
	ofTranslate(0,ofGetHeight()*0.9); 
	ofRotateX(5); 
	ofTranslate(0,ofGetHeight()*-0.9);

	psystem.draw(); 
	ofCircle(rocket.pos, 2); 
	
	ofPopMatrix(); 
}

void testApp:: mousePressed(int x, int y, int button ) { 
	psystem.reset(); 
	rocket.reset(); 
	rocket.vel.set(0,-800,0);
	rocket.gravity.y = 500;
	rocket.vel.rotate(0,0,ofRandom(-20,20));
	
	rocket.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
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
	ps.speedMin = 10; 
	ps.speedMax = 50; 
	ps.directionZ = 0; 
	ps.directionZVar = 180; 
	ps.drag = 0.90; 
	ps.gravity.set(0,30); 
	
	//LIFE
	ps.lifeMin = 0.5; 
	ps.lifeMax = 0.8; 
	
	//APPEARANCE
	
	ps.sizeStartMin = 4; 
	ps.sizeStartMax = 6;
	ps.sizeChangeRatio = 1; 
	
	ps.hueStartMin = -70; 
	ps.hueStartMax = -10; 
	ps.hueChange = 0; 
	
	ps.brightnessStartMin = 255; 
	ps.brightnessStartMax = 150;
	ps.brightnessEnd = 0; 
	
	ps.saturationMin = 205; 
	ps.saturationMax = 255; 
	
	ps.shimmerMin = 0.8; 
	
	// but also : 
	// lifeExpectancy
	// delay

	ps.emitMode = PARTICLE_EMIT_CONTINUOUS;
	ps.emitCount = 1000; 
	
	ps.emitDelay = 0; 
	ps.emitLifeTime= 3;
	
	ps.emitStartSizeModifier = 0; 
	ps.emitSpeedModifier = 0; 
	ps.emitHueModifierOffset = 500;
	
	ps.emitAttachedPhysicsObject = &rocket;
	ps.emitInheritVelocity = -0.5; 
	
	psystem.init(ps); 
	
	
	
	//ped
	
	
	
	
	
	
	
//	particleSystemData.addSettings(settings, "squareExplosion"); 
	
	// WHAT DOES ROCKETDATA STORE? 
	
	// particleSystemSettings * n
	// startDirection / Var
	// startSpeed / Var
	// gravity
	// drag
	
//	rs.
	
	
	//rocketData.addSettings(rocketsettings, "BasicRocket"); 
	
	//Scene scene1; 
	
	//scene1.addOrbs(orbData.getOrbByName["Rocket1"], defaultPositions); 
	
	//scenes.push(&scene1); 
	
	
	
	// Particle object has : 
	// PHYSICS : 
	// position 
	// velocity
	// other physics stuff 
	//		gravity
	//		drag
	
	// UPDATING / ENABLING
	// elapsedTime
	// lifeTime
	// enabled
	
	// VISUAL STUFF 
	// size
	// start / end size
	// texture
	// geometry
	// start / end colour
	
	
}




void testApp::exit() { 


}