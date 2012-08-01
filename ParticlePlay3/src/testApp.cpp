#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	
	ofSetFrameRate(60);
	lastUpdateTime = ofGetElapsedTimef();
	
	//setupControlPanel();
	
	//gui.hide();
	
	ofBackground(0);
	
//	rocket.reset(ofGetWidth()/2, ofGetHeight()*0.8, 0); 
//	rocket.physics.vel.y = -600;
//	rocket.physics.gravity.y = 500; 
//	
	psystem.pos.set(ofGetWidth()/2, ofGetHeight()*0.8, 0);
	setupScenes(); 

}

//--------------------------------------------------------------
void testApp::update(){

	float time = ofGetElapsedTimef(); 
	float deltaTime =  time - lastUpdateTime; 

	lastUpdateTime = time;
	
	psystem.update(deltaTime); 
	
}

//--------------------------------------------------------------
void testApp::draw(){

	ofPushMatrix(); 
	
	ofTranslate(0,ofGetHeight()*0.9); 
	ofRotateX(5); 
	ofTranslate(0,ofGetHeight()*-0.9);

	psystem.draw(); 
	// ofCircle(particle.getPos(), 2); 
	
	ofPopMatrix(); 
}

void testApp:: mousePressed(int x, int y, int button ) { 
	psystem.reset(); 
	//rocket.physics.vel.y = -600;

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
	
	ParticleSettings ps; 
	// PHYSICS
	ps.speedMin = 20; 
	ps.speedMax = 100; 
	ps.directionZ = 0; 
	ps.directionZVar = 180; 
	ps.drag = 0.96; 
	ps.gravity.set(0,30); 
	
	//LIFE
	ps.lifeMin = 2; 
	ps.lifeMax = 4; 
	
	//APPEARANCE
	
	ps.sizeStartMin = 10; 
	ps.sizeStartMax = 10;
	ps.sizeChangeRatio = 2; 
	
	ps.hueStartMin = -70; 
	ps.hueStartMax = -10; 
	ps.hueChange = 0; 
	
	ps.brightnessStartMin = 150; 
	ps.brightnessStartMax = 150;
	ps.brightnessEnd = 0; 
	
	ps.saturationMin = 205; 
	ps.saturationMax = 255; 
	
	ps.shimmerMin = 1; 
	
	
	//rocket.trail->settings = ps; 
	
	
	
	
	// WHAT DOES PARTICLEEMITTERDATA STORE ? 
	// everything that we have so far in ParticleSystemSettings 
	// emission rate (over time?) 
	
	// start ParticleSettings
	// end ParticleSettings
	// if no end settings, then doesn't change
	
	// drag 
	// gravity
	
	// but also : 
	// lifeExpectancy
	// delay

	ParticleSystemSettings pes; 
	
	
	
	pes.emitMode = PARTICLE_EMIT_CONTINUOUS;
	pes.emitCount = 200; 
	
	
	// I DON'T THINK THAT THIS SHOULD CONTAIN PHYSICS
	
	pes.speedMin = 300; 
	pes.speedMax = 350; 
	pes.rotationZ = 270; 
	pes.rotationZVar = 10; 
	
	pes.delayMax = pes.delayMin = 0; 
	pes.lifeTimeMax = pes.lifeTimeMin = 2;
	
	pes.drag = 0.99; 
	pes.gravity.set(0,300); 
	pes.settings = ps; 
	
	
	psystem.init(pes); 
	
	
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